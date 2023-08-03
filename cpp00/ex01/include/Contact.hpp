#pragma once

#include <string>

class Contact {
public:
	Contact(void);
	Contact(const Contact& other);

	~Contact(void);

	int updateWithInput(void);

	Contact& operator=(const Contact& other);

	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
};

std::ostream& operator<<(std::ostream& os, const Contact& contact);
