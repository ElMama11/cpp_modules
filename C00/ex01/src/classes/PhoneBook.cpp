/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:43:11 by mverger           #+#    #+#             */
/*   Updated: 2023/02/14 17:04:30 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	_index = 0;
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::Add()
{
	if (_index == SIZE_BOOK)
		_index = 0;
	_contactList[_index].GetInputUser();
	_index++;
}

void PhoneBook::Search()
{
	_printContacts();
	std::cout << "Please choose an index." << std::endl;
	std::string indexStr;
	getline(std::cin, indexStr);
	std::istringstream indexStream(indexStr);
	int index;
	indexStream >> index;
	if (index < 1 || index > 8)
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	_contactList[index - 1].PrintInfo();
		
}

void PhoneBook::_printContacts()
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < SIZE_BOOK; i++)
	{
		if (_contactList[i].IsRegistred())
			_contactList[i].PrintRow(i);
	}
	std::cout << "---------------------------------------------" << std::endl;
}