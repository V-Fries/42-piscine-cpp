#include "BitcoinExchange.h"

#include <fstream>
#include <cstdlib>
#include <cerrno>
#include <stdexcept>
#include <iostream>
#include <limits>

#define FILE_OPEN_ERROR "Error: could not open file."
#define FILE_HEADER_ERROR "Error: file does not contain the proper header."

static bool	isValidExchangeRateLineFormat(const std::string& line);
static void	readDate(int& year, int& month, int& day, const std::string& line, char*& pointerPostDay);
bool		isValidDate(int year, int month, int day);
static bool	isValidPriceLineFormat(const std::string& line);

BitcoinExchange::BitcoinExchange():
	_prices()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other):
	_prices(other._prices)
{}

BitcoinExchange::BitcoinExchange(const char* fileWithBitcoinExchangeRates):
	_prices()
{
	std::cout << "Parsing exchange rate database:" << std::endl;

	std::ifstream	file;

	file.open(fileWithBitcoinExchangeRates);
	if (!file.is_open())
		throw (std::invalid_argument(FILE_OPEN_ERROR));

	std::string	line;
	if (!std::getline(file, line) || line != "date,exchange_rate")
		throw (std::invalid_argument(FILE_HEADER_ERROR));
	while (std::getline(file, line))
		addBitcoinExchangeRate(line);
	std::cout << "Done\n" << std::endl;
}

void	BitcoinExchange::addBitcoinExchangeRate(const std::string& line) {
	try {
		if (isValidExchangeRateLineFormat(line) == false)
			throw (std::invalid_argument("the line isn't formated correctly"));

		int		year;
		int		month;
		int		day;
		char*	pointerPostDay;
		readDate(year, month, day, line, pointerPostDay);

		errno = 0;
		double	price = std::strtod(pointerPostDay + 1, NULL);
		if (errno != 0)
			throw (std::invalid_argument("the price is not a valid double"));
		if (price < 0)
			throw (std::invalid_argument("the price can not be negative"));

		this->_prices[BitcoinExchange::getKeyFromDate(year, month, day)] = price;

	} catch (const std::exception& e) {
		std::cerr << line << " -> ignored because " << e.what() << std::endl;
	}
}

static bool	isValidExchangeRateLineFormat(const std::string& line) {
	if (line.length() == 0)
		return false;
	if (!std::isdigit(static_cast<unsigned char>(line[0])))
		return false;
	size_t	i = 0;
	for (; i < line.length() && std::isdigit(static_cast<unsigned char>(line[i])); i++);
	if (i >= line.length() - 1 || line[i] != '-' || !std::isdigit(static_cast<unsigned char>(line[i + 1])))
		return false;
	for (i = i + 1; i < line.length() && std::isdigit(static_cast<unsigned char>(line[i])); i++);
	if (i >= line.length() - 1 || line[i] != '-' || !std::isdigit(static_cast<unsigned char>(line[i + 1])))
		return false;
	for (i = i + 1; i < line.length() && std::isdigit(static_cast<unsigned char>(line[i])); i++);
	if (i >= line.length() - 1 || line[i] != ',' || !std::isdigit(static_cast<unsigned char>(line[i + 1])))
		return false;
	char*	postPricePtr;
	std::strtod(line.c_str() + i + 1, &postPricePtr);
	size_t	postPriceIndex = postPricePtr - line.c_str();
	return postPriceIndex == line.length();
}

static void	readDate(int& year, int& month, int& day, const std::string& line, char*& pointerPostDay) {
	char*		pointerPostYear;
	char*		pointerPostMonth;

	long		longYear = std::strtol(line.c_str(), &pointerPostYear, 10);
	if (longYear > std::numeric_limits<int>::max())
		throw (std::invalid_argument("the year is not a valid 32 bit integer"));
	long	longMonth = std::strtol(pointerPostYear + 1, &pointerPostMonth, 10);
	if (longMonth > std::numeric_limits<int>::max())
		throw (std::invalid_argument("the month is not a valid 32 bit integer"));
	long	longDay = std::strtol(pointerPostMonth + 1, &pointerPostDay, 10);
	if (longDay > std::numeric_limits<int>::max())
		throw (std::invalid_argument("the day is not a valid 32 bit integer"));

	year = static_cast<int>(longYear);
	month = static_cast<int>(longMonth);
	day = static_cast<int>(longDay);

	if (isValidDate(year, month, day) == false)
		throw std::invalid_argument("the date is invalid");
}

bool	isValidDate(int year, int month, int day) {
	if (month > 12 || month == 0 || day == 0)
		return false;

	bool	isLeapYear;
	switch (month) {
		case 1:
			if (day > 31)
				return false;
			break;
		case 2:
			isLeapYear = year % 4;
			if ((isLeapYear && day > 29) || (isLeapYear == false && day > 28))
				return false;
			break;
		case 3:
			if (day > 31)
				return false;
			break;
		case 4:
			if (day > 30)
				return false;
			break;
		case 5:
			if (day > 31)
				return false;
			break;
		case 6:
			if (day > 30)
				return false;
			break;
		case 7:
			if (day > 31)
				return false;
			break;
		case 8:
			if (day > 31)
				return false;
			break;
		case 9:
			if (day > 30)
				return false;
			break;
		case 10:
			if (day > 31)
				return false;
			break;
		case 11:
			if (day > 30)
				return false;
			break;
		case 12:
			if (day > 31)
				return false;
			break;
	}

	return true;
}

BitcoinExchange::~BitcoinExchange() {}


BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& rightValue) {
	if (this == &rightValue)
		return *this;
	_prices = rightValue._prices;
	return *this;
}


long	BitcoinExchange::getKeyFromDate(const int year, const int month, const int day) {
	return (day + month * 100 + year * 10000);
}


void	BitcoinExchange::evaluatePrices(const char* fileWithPricesToEvaluate) {
	std::cout << "Evaluating the prices in " << fileWithPricesToEvaluate << ':' << std::endl;

	std::ifstream	file;

	if (fileWithPricesToEvaluate == NULL)
		throw (std::invalid_argument(FILE_OPEN_ERROR));
	file.open(fileWithPricesToEvaluate);
	if (!file.is_open())
		throw (std::invalid_argument(FILE_OPEN_ERROR));

	if (_prices.size() == 0) {
		std::cout << "No bitcoin exchange rates were found in the database, the prices can not be evaluated"
				  << std::endl;
		return;
	}

	std::string	line;
	if (!std::getline(file, line) || line != "date | value")
		throw (std::invalid_argument(FILE_HEADER_ERROR));
	while (std::getline(file, line))
		this->evaluatePrice(line);
	std::cout << "Done\n" << std::endl;
}


double	BitcoinExchange::getExchangeRateFromKey(const long key) const {
	std::map<long, double>::const_iterator	it = this->_prices.upper_bound(key);
	if (it == this->_prices.begin())
		throw (std::invalid_argument("there is no price at or before this date"));
	return (--it)->second;
}


void	BitcoinExchange::evaluatePrice(const std::string& line) {
	std::cout << line << " -> ";
	try {
		if (isValidPriceLineFormat(line) == false)
			throw (std::invalid_argument("the line isn't formated correctly"));

		int		year;
		int		month;
		int		day;
		char*	pointerPostDay;
		readDate(year, month, day, line, pointerPostDay);

		errno = 0;
		double	price = std::strtod(pointerPostDay + 3, NULL);
		if (errno != 0)
			throw (std::invalid_argument("the price is not a valid double"));
		if (price < 0)
			throw (std::invalid_argument("the price can not be negative"));
		if (price > 1000)
			throw (std::invalid_argument("the price can not be above 1000"));

		long	key = BitcoinExchange::getKeyFromDate(year, month, day);
		std::cout << getExchangeRateFromKey(key) * price << std::endl;

	} catch (const std::exception& e) {
		std::cerr << "ignored because " << e.what() << std::endl;
	}
}

static bool	isValidPriceLineFormat(const std::string& line) {
	if (line.length() == 0)
		return false;
	if (!std::isdigit(static_cast<unsigned char>(line[0])))
		return false;
	size_t	i = 0;
	for (; i < line.length() && std::isdigit(static_cast<unsigned char>(line[i])); i++);
	if (i >= line.length() - 1 || line[i] != '-' || !std::isdigit(static_cast<unsigned char>(line[i + 1])))
		return false;
	for (i = i + 1; i < line.length() && std::isdigit(static_cast<unsigned char>(line[i])); i++);
	if (i >= line.length() - 1 || line[i] != '-' || !std::isdigit(static_cast<unsigned char>(line[i + 1])))
		return false;
	for (i = i + 1; i < line.length() && std::isdigit(static_cast<unsigned char>(line[i])); i++);
	if (i >= line.length() - 1 || line[i] != ' ')
		return false;
	i++;
	if (i >= line.length() - 1 || line[i] != '|')
		return false;
	i++;
	if (i >= line.length() - 1 || line[i] != ' ' || !std::isdigit(static_cast<unsigned char>(line[i + 1])))
		return false;
	char*	postPricePtr;
	std::strtod(line.c_str() + i + 1, &postPricePtr);
	size_t	postPriceIndex = postPricePtr - line.c_str();
	return postPriceIndex == line.length();
	return i == line.length();
}
