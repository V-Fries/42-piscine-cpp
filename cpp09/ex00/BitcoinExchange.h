#pragma once

#include <map>
#include <string>

class BitcoinExchange {
private:
	std::map<long, double>	_prices;

	void	addBitcoinExchangeRate(const std::string& line);

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange(const char* fileWithBitcoinExchangeRates);

	~BitcoinExchange();

	BitcoinExchange&	operator=(const BitcoinExchange& rightValue);

	static long	getKeyFromDate(int year, int month, int day);

	double	getExchangeRateFromKey(long key) const;

	void	evaluatePrices(const char* fileWithPricesToEvaluate);
	void	evaluatePrice(const std::string& line);
};
