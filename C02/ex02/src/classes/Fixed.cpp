/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:50:29 by mverger           #+#    #+#             */
/*   Updated: 2023/02/28 16:37:52 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed::Fixed(const int nb)
{
	_fixedPointValue = nb << _fractionalBits;
}

Fixed::Fixed(const float nb)
{
	_fixedPointValue = roundf(nb * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
}

/* Operators overload */

Fixed &Fixed::operator=(const Fixed &rhs)
{
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
	return *this;
}

// Overloaded Comparison Operators
bool Fixed::operator>(Fixed &fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool Fixed::operator<(Fixed &fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

bool Fixed::operator>=(Fixed &fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool Fixed::operator<=(Fixed &fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool Fixed::operator==(Fixed &fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

bool Fixed::operator!=(Fixed &fixed) const
{
	return (this->toFloat() != fixed.toFloat());
}

// Overloaded Arithmetic Operators
float Fixed::operator+(Fixed &fixed) const
{
	return (this->toFloat() + fixed.toFloat());
}

float Fixed::operator-(Fixed &fixed) const
{
	return (this->toFloat() - fixed.toFloat());
}

float Fixed::operator*(Fixed fixed) const
{
	return (this->toFloat() * fixed.toFloat());
}

float Fixed::operator/(Fixed &fixed) const
{
	return (this->toFloat() / fixed.toFloat());
}

// Overloaded pre-increment Operators
Fixed Fixed::operator++()
{
	this->_fixedPointValue++;
	return (*this);
}

Fixed Fixed::operator--()
{
	this->_fixedPointValue--;
	return (*this);
}

// Overloaded post-increment Operators
Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	// i = this->_fp_value;
	++this->_fixedPointValue;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	// i = this->_fp_value;
	--this->_fixedPointValue;
	return (tmp);
}

std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}

/* Member functions */

int Fixed::getRawBits(void) const
{
	return _fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)_fixedPointValue / (float)(1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return (_fixedPointValue >> _fractionalBits);
}

Fixed &Fixed::min(Fixed &first, Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed &Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

Fixed &Fixed::max(Fixed &first, Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed &Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}
