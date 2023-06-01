/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:39:49 by mverger           #+#    #+#             */
/*   Updated: 2023/06/01 17:10:51 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/BitcoinExchange.hpp"

int main(int ac, char **av)
{
	(void)av;
	if (ac != 2) {
		std::cerr << "Need input.txt" << std::endl;
		return 1;
	}
	
	std::ifstream inputFile(av[1]);
	if (inputFile.is_open() == false) {
		std::cerr << "Error: could not open input file" << std::endl;
		return 1;
	}
	
	BitcoinExchange	exchange("data.csv");
	std::string	line;
	std::getline(inputFile, line);
	while (std::getline(inputFile, line))
	{
		std::stringstream ss(line);
		std::string date;
		float value;
		if (std::getline(ss, date, '|') && ss >> value)
		{
			date.erase(0, date.find_first_not_of(" \t\n\r\f\v"));
			date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1);
			try
			{
				float exchangeRate = exchange.getExchangeRate(date, value);
				float result = value * exchangeRate;
				std::cout << date << " => " << value << " = " << result << std::endl;
			}
			catch (const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
		else
			std::cerr << "Error: bad input => " << line << std::endl;
	}
}