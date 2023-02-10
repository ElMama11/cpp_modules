/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:43:15 by mverger           #+#    #+#             */
/*   Updated: 2023/02/10 19:02:21 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::getInfo()
{
	std::cout << "Enter first name : "  << std::endl;
	getline(std::cin, _firstName);
	std::cout << "Enter last name : "  << std::endl;
	getline(std::cin, _lastName);
	std::cout << "Enter nick name : "  << std::endl;
	getline(std::cin, _nickName);
	std::cout << "Enter phone number: "  << std::endl;
	getline(std::cin, _phoneNumber);
	std::cout << "Enter darkest secret : "  << std::endl;
	getline(std::cin, _darkestSecret);
	std::cout << std::endl;
}

void Contact::printInfo()
{
	std::cout << "First name : " << _firstName << std::endl;
	std::cout << "Last name : " << _lastName << std::endl;
	std::cout << "Nick name : " << _nickName << std::endl;
	std::cout << "Phone number : " << _phoneNumber << std::endl;
	std::cout << "Darkest secret : " << _darkestSecret << std::endl;
	std::cout << std::endl;
}