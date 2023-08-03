#pragma once

#include "Contact.hpp"

#define CONTACTS_SIZE 8

class PhoneBook {
public:
	PhoneBook(void);
	PhoneBook(const PhoneBook& other);

	~PhoneBook(void);

	void addContact(void);
	void search(void) const;

	PhoneBook& operator=(const PhoneBook& other);

private:
	Contact	_contacts[CONTACTS_SIZE];
	int		_contactsLen;
	int		_oldestContactIndex;
};
