/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:08:50 by mverger           #+#    #+#             */
/*   Updated: 2023/02/10 19:34:41 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

std::string get_input()
{
	std::string	input;
	
	std::cout << "Authorized commands : ADD, SEARCH or EXIT." << std::endl;
	std::cout << "Enter a command :" << std::endl;
	getline(std::cin, input);
	std::cout << std::endl;
	return input;
}

int main(void) {
	
	PhoneBook	book;
	std::string	input;
	int			nb_contact = 0;

	input = get_input();
	while (input != "EXIT")
	{
		if (nb_contact == 8)
			nb_contact = 0;
		if (input == "ADD")
		{
			book.addContact(nb_contact);
			nb_contact++;
		}
		else if (input == "SEARCH")
		{
			book.printContact();
		}
		input = get_input();
	}
	return 0;
}