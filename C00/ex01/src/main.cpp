/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:08:50 by mverger           #+#    #+#             */
/*   Updated: 2023/02/13 15:35:59 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(void)
{
	std::string line;
	PhoneBook book;
	
	std::cout << "COMMANDS: ADD, SEARCH, EXIT" << std::endl;
	while(getline(std::cin, line)) {
		if (line == "ADD")
			book.Add();
		else if (line == "SEARCH")
			book.Search();
		else if (line == "EXIT")
			break;
		std::cout << "COMMANDS: ADD, SEARCH, EXIT" << std::endl;		
	}
	return 0;
}