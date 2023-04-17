/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:27:01 by mverger           #+#    #+#             */
/*   Updated: 2023/04/15 18:19:25 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
}

AMateria::AMateria(std::string const &type) : _type(type) {
}

AMateria::AMateria(const AMateria &cpy) {
	*this = cpy;
}

AMateria::~AMateria() {
}

/* Operator overload*/

AMateria &AMateria::operator=(const AMateria &rhs) {
	if (this != &rhs)
	{
		_type = rhs._type;
	}
	return *this;
}

/* public ft */

std::string const &AMateria::getType() const {
	return _type;
}

AMateria* AMateria::clone() const
{
    return (AMateria*)this;
}

void AMateria::use(ICharacter &target) {
	
}