#include <iostream>
#include <limits>

#include "PhoneBook.hpp"

#include "input.hpp"

static void printName(std::string name);
static int getSearchInput(int len);


// Contructors

PhoneBook::PhoneBook(void) {
	this->_contactsLen = 0;
	this->_oldestContactIndex = -1;
}

PhoneBook::PhoneBook(const PhoneBook& other) {
	for (int i = 0; i < CONTACTS_SIZE; i++)
		this->_contacts[i] = other._contacts[i];
	this->_contactsLen = other._contactsLen;
	this->_oldestContactIndex = other._oldestContactIndex;
}


// Destructors

PhoneBook::~PhoneBook(void) {
	return ;
}


// Methods

void PhoneBook::addContact(void) {
	if (this->_contactsLen == CONTACTS_SIZE) {
		this->_contacts[this->_oldestContactIndex].updateWithInput();
		this->_oldestContactIndex++;
		if (this->_oldestContactIndex == CONTACTS_SIZE)
			this->_oldestContactIndex = 0;
	} else {
		this->_contacts[this->_contactsLen].updateWithInput();
		if (this->_oldestContactIndex == -1)
			this->_oldestContactIndex = 0;
		this->_contactsLen++;
	}
}

void PhoneBook::search(void) const {
	if (this->_contactsLen == 0) {
		std::cout << "Phone book is empty" << std::endl;
		return ;
	}

	std::cout << "-------------------------------------------\n"
			  << "|   index|first name| last name|  nickname|\n"
			  << "-------------------------------------------" << std::endl;

	for (int i = 0; i < this->_contactsLen; i++) {
		std::cout << "|       " << i << '|';
		printName(this->_contacts[i].firstName);
		printName(this->_contacts[i].lastName);
		printName(this->_contacts[i].nickname);
		std::cout << "\n-------------------------------------------" << std::endl;
	}

	int	inputed_index = getSearchInput(this->_contactsLen);
	std::cout << this->_contacts[inputed_index];
}

static void printName(std::string name) {
	if (name.length() <= 10) {
		for (int i = 10 - name.length(); i; i--)
			std::cout << ' ';
		std::cout << name << '|';
	}
	else {
		for (int i = 0; i < 9; i++)
			std::cout << name[i];
		std::cout << ".|";
	}
}

static int getSearchInput(int len) { // TODO test with ctrl + d
	int	inputed_index;

	while (true) {
		inputed_index = getInt("Input the index of the entry to display $> ");
		if (inputed_index < 0) {
			std::cout << "Input needs to be above or equal to 0" << std::endl;
		} else if (inputed_index >= len) {
			std::cout << "Input needs to be below " << len << std::endl;
		} else {
			return inputed_index;
		}
	}
}


// Operators

PhoneBook& PhoneBook::operator=(const PhoneBook& other) {
	for (int i = 0; i < CONTACTS_SIZE; i++)
		this->_contacts[i] = other._contacts[i];
	this->_contactsLen = other._contactsLen;
	this->_oldestContactIndex = other._oldestContactIndex;
	return *this;
}
