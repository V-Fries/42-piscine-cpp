#include <iostream>

#include "Contact.hpp"

#include "input.hpp"


// Contructors

Contact::Contact(void) {
	return ;
}

Contact::Contact(const Contact& other) {
	this->firstName = other.firstName;
	this->lastName = other.lastName;
	this->nickname = other.nickname;
	this->phoneNumber = other.phoneNumber;
	this->darkestSecret = other.darkestSecret;
}


// Destructor

Contact::~Contact(void) {
	return ;
}


// Methods

int Contact::updateWithInput(void) {
	this->firstName = getLine("Input first name $> ");
	this->lastName = getLine("Input last name $> ");
	this->nickname = getLine("Input nickname $> ");
	this->phoneNumber = getLine("Input phone number $> ");
	this->darkestSecret = getLine("Input darkest secret $> ");
	return (0);
}


// Operators

Contact& Contact::operator=(const Contact& other) {
	this->firstName = other.firstName;
	this->lastName = other.lastName;
	this->nickname = other.nickname;
	this->phoneNumber = other.phoneNumber;
	this->darkestSecret = other.darkestSecret;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Contact& contact) {
    os << "First name: " << contact.firstName << std::endl;
	os << "Last name: " << contact.lastName << std::endl;
	os << "nickname: " << contact.nickname << std::endl;
	os << "Phone number name: " << contact.phoneNumber << std::endl;
	os << "Darkest secret: " << contact.darkestSecret << std::endl;
    return os;
}
