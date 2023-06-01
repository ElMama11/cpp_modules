/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:08:45 by mverger           #+#    #+#             */
/*   Updated: 2023/06/01 17:31:41 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const std::string &databaseFile) {
	std::ifstream myFile(databaseFile.c_str());
	if (!myFile.is_open())
		throw databaseError();
	std::string line;
	while(std::getline(myFile, line))
	{
		std::stringstream ss(line);
		std::string date;
		float price;
		if (std::getline(ss, date, ',') && ss >> price)
			_exchangeRates[date] = price;
	}
		
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& cpy) {
	*this = cpy;
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	if (this != &rhs)
		this->_exchangeRates = rhs._exchangeRates;
	return *this;
}

bool	BitcoinExchange::_isValidDate(const std::string& dateStr) {
	int year, month, day;
	char separator;
	std::istringstream ss(dateStr);
	
	ss >> year >> separator >> month >> separator >> day;
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			return false;
	}
	else if (month == 2 && day > 28)
		return false;
	return true;
}

float BitcoinExchange::getExchangeRate(const std::string &date, float value) {
	if (value < 0)
		throw negativeValue();
	if (value > 1000)
		throw tooLargeNumber();
	if (_isValidDate(date) == false)
		throw inexistentDate();
	std::map<std::string, float>::const_iterator it = _exchangeRates.find(date);
	if (it == _exchangeRates.end())
	{
		it = _exchangeRates.upper_bound(date);
		if (it == _exchangeRates.begin())
			throw invalidArgument();
		--it;
	}
	return it->second;
}

std::ostream&	operator<<(std::ostream& o, const BitcoinExchange& i)
{
	(void)i;
	return o;
}