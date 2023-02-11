/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:43:15 by mverger           #+#    #+#             */
/*   Updated: 2023/02/11 17:29:49 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() : _columnSize(10)
{
}

Contact::~Contact()
{
}

void Contact::GetInputUser()
{
	std::cout << "Enter first name : "  << std::endl;
	getline(std::cin, _firstName);
	while (_firstName.empty())
	{
		std::cout << "Enter first name : "  << std::endl;
		getline(std::cin, _firstName);
	}
	std::cout << "Enter last name : "  << std::endl;
	getline(std::cin, _lastName);
	while (_lastName.empty())
	{
		std::cout << "Enter last name : "  << std::endl;
		getline(std::cin, _lastName);
	}
	std::cout << "Enter nickname : "  << std::endl;
	getline(std::cin, _nickName);
	while (_nickName.empty())
	{
		std::cout << "Enter nickname : "  << std::endl;
		getline(std::cin, _nickName);
	}
	std::cout << "Enter phone number: "  << std::endl;
	getline(std::cin, _phoneNumber);
	while (_phoneNumber.empty())
	{
		std::cout << "Enter phone number : "  << std::endl;
		getline(std::cin, _phoneNumber);
	}
	std::cout << "Enter darkest secret : "  << std::endl;
	getline(std::cin, _darkestSecret);
	while (_darkestSecret.empty())
	{
		std::cout << "Enter darkest secret : "  << std::endl;
		getline(std::cin, _darkestSecret);
	}
	std::cout << std::endl;
}

std::string Contact::_getTruncString(std::string str) {
	std::string truncated;

	for (int i = 0; i < _columnSize; i++)
		truncated += " ";
	std::string sub = str.substr(0, _columnSize);
	const int startIndex = _columnSize - sub.length();
	truncated.replace(startIndex, sub.length() > _columnSize ? _columnSize : sub.length(), sub);

	if (str.length() > _columnSize)
		truncated.replace(_columnSize - 1, 1, ".");

	return truncated;
}

void Contact::PrintRow(int index) {
	std::ostringstream ss;
	ss << index;
	std::cout <<
		"|" + _getTruncString(ss.str()) +
		"|" + _getTruncString(_firstName) +
		"|" + _getTruncString(_lastName) +
		"|" + _getTruncString(_nickName) +
		"|" << std::endl;
}

void Contact::PrintInfo()
{
	std::cout << "First name : " << _firstName << std::endl;
	std::cout << "Last name : " << _lastName << std::endl;
	std::cout << "Nick name : " << _nickName << std::endl;
	std::cout << "Phone number : " << _phoneNumber << std::endl;
	std::cout << "Darkest secret : " << _darkestSecret << std::endl;
	std::cout << std::endl;
}

bool Contact::IsRegistred()
{
	if (_firstName.empty())
		return false;
	return true;
}