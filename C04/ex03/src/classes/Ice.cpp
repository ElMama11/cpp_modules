/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:08:38 by mverger           #+#    #+#             */
/*   Updated: 2023/04/17 17:56:26 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria() {
	_type = "ice";
}

Ice::Ice(const Ice &cpy) {
	*this = cpy;
}

Ice::~Ice() {
}

Ice &Ice::operator=(const Ice &rhs) {
	if (this != &rhs) {
		_type = rhs._type;
	}
	return *this;
}

void use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << &target << " *"<< std::endl;
}

AMateria* Ice::clone() const
{
    return (new Ice(*this));
}