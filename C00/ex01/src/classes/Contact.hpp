#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <sstream>
# include <string>

class Contact 
{
	public:
		Contact(void);
		~Contact(void);
		void GetInputUser();
		void PrintInfo();
		void PrintRow(int index);
		bool IsRegistred(void);
		
	private:
		std::string _getTruncString(std::string);
		
		int _columnSize;
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;
};

#endif