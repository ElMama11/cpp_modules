/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:43:11 by mverger           #+#    #+#             */
/*   Updated: 2023/02/10 19:35:49 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::addContact(const int totalNumberContact)
{
	_contact_list[totalNumberContact].getInfo();
}

void PhoneBook::printContact()
{
	int index = 0;
	std::cout << "Please choose an index." << std::endl;
	std::cin >> index;
	if (index < 0 || index > 7)
	{
		std::cout << "Invalid index" << std::endl << std::endl;
		return;
	}
	_contact_list[index].printInfo();
}