/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:06:59 by mverger           #+#    #+#             */
/*   Updated: 2023/05/24 18:09:10 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {
}

Span::Span(unsigned int n) : _n(n) {
}

Span::Span(const Span &cpy) {
	*this = cpy;
}

Span &Span::operator=(const Span &rhs) {
	if (this != &rhs)
	{
		_n = rhs._n;
	}
	return *this;
}

Span::~Span() {
}

/* Public ft */

void Span::addNumber(unsigned int nb) {
	if (_n == _lst.size())
		throw CantAddNumber();
	else
		_lst.push_back(nb);
}

void Span::addNumbers( std::list<int>::const_iterator itBegin, std::list<int>::const_iterator itEnd ) {
	if (_n == _lst.size())
		throw CantAddNumber();
	_lst.insert( _lst.end(), itBegin, itEnd );
}

int Span::shortestSpan(void) {
	int i = INT_MAX;
	int j = 0;
	std::list<int>::iterator ite, ite2;
	
	if (_lst.size() <= 1)
		throw TooFewNumber();
	_lst.sort();
	ite2 = _lst.begin();
	for (ite = _lst.begin(); ite != _lst.end(); ite++)
	{
		if (j >= 1)
		{
			if (i > *ite - *ite2)
				i = *ite - *ite2;
			ite2++;
		}
		j++;
	}
	return i;
}

int Span::longestSpan(void) {
	if (_lst.size() <= 1)
		throw TooFewNumber();
	_lst.sort();
	return (_lst.back() - _lst.front());
}

