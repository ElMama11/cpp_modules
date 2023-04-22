/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:54:23 by mverger           #+#    #+#             */
/*   Updated: 2023/04/22 16:19:56 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria() {
	_type = "cure";
}

Cure::Cure(const Cure &cpy) {
	*this = cpy;
}

Cure::~Cure() {
}

Cure &Cure::operator=(const Cure &rhs) {
	if (this != &rhs) {
		_type = rhs._type;
	}
	return *this;
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName()  << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const
{
    return (new Cure(*this));
}