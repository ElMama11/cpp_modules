/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conv.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:27:01 by mverger           #+#    #+#             */
/*   Updated: 2023/05/15 15:41:16 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conv.hpp"

Conv::Conv() : _value("error"){
}

Conv::Conv(std::string const &value) : _value(value) {
}

Conv::Conv(const Conv &cpy) : _value(cpy.getValue()) {
	*this = cpy;
}

Conv::~Conv() {
}

Conv &Conv::operator=(const Conv &rhs) {
	(void)rhs;
	return *this;
}

/* Public ft */

std::string const &Conv::getValue() const
{
	return _value;
}

char Conv::toChar() const
{
	int n;
	int i;
	
	try
	{
		std::istringstream(_value) >> i;
    	n = static_cast<int>(i);;
		if (n < 0 || n > 255)
		{
			throw Conv::ImpossibleException();
		}
	}
	catch (...)
	{
		throw Conv::ImpossibleException();
	}
	if (!isprint(n))
	{
		throw Conv::NonDisplayableException();
	}
	return (static_cast<char>(n));
}

int Conv::toInt() const
{
	int n;
	int i;

	try
	{
   		std::istringstream(_value) >> i;
    	n = static_cast<int>(i);
		if (n == 0 && _value[0] != '0')
			throw Conv::ImpossibleException();
	}
	catch (...)
	{
		throw Conv::ImpossibleException();
	}
	return (n);
}

float Conv::toFloat() const
{
	float f;

	try
	{
		f = std::stof(_value);
	}
	catch (...)
	{
		throw Conv::ImpossibleException();
	}
	return (f);
}

double Conv::toDouble() const
{
	float d;

	try
	{
		d = std::stod(_value);
	}
	catch (...)
	{
		throw Conv::ImpossibleException();
	}
	return (d);
}

std::ostream &operator<<(std::ostream &os, const Conv &Conv)
{
	os << "char: ";
	try
	{
		char c = Conv.toChar();
		os << "'" << c << "'" << std::endl;
	}
	catch (const std::exception &e)
	{
		os << e.what() << std::endl;
	}

	os << "int: ";
	try
	{
		os << Conv.toInt() << std::endl;
	}
	catch (const std::exception &e)
	{
		os << e.what() << std::endl;
	}

	os << "float: ";
	try
	{
		float f = Conv.toFloat();

		if (std::isnan(f) && std::signbit(f))
			os << "-";
		os << f;
		if (!std::isnan(f) && f - (int)f == 0)
			os << ".0";
		os << "f" << std::endl;
	}
	catch (const std::exception &e)
	{
		os << e.what() << std::endl;
	}

	os << "Double: ";
	try
	{
		double d = Conv.toDouble();

		if (std::isnan(d) && std::signbit(d))
			os << "-";
		os << d;
		if (!std::isnan(d) && d - (int)d == 0)
			os << ".0";
		os << std::endl;
	}
	catch (const std::exception &e)
	{
		os << e.what() << std::endl;
	}
	return (os);
}

