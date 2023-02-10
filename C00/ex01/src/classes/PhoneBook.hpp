#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"
# include <cstdlib>

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void addContact(const int totalNumberContact);
		void printContact();

	private:
		Contact _contact_list[8];
};

#endif