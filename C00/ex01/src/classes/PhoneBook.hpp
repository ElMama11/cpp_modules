#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <sstream>
# include <string>
# include "Contact.hpp"

const int SIZE_BOOK = 8;

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void Add(void);
		void Search(void);

	private:
		void _printContacts(void);

		Contact _contactList[SIZE_BOOK];
		int _index;
};

#endif