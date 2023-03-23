/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:19:34 by mverger           #+#    #+#             */
/*   Updated: 2023/03/23 16:21:34 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// Constructors
AAnimal::AAnimal() {
	std::cout << "AAnimal Default Constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy) {
	std::cout << "AAnimal Copy Constructor called" << std::endl;
	*this = copy;
}

// Deconstructors
AAnimal::~AAnimal() {
	std::cout << "AAnimal Deconstructor called" << std::endl;
}

// Overloaded Operators
AAnimal &AAnimal::operator=(const AAnimal &rhs) {
	std::cout << "AAnimal Assignation operator called" << std::endl;
	if (this == &rhs)
		return *this;
	this->_type = rhs._type;
	return *this;
}

// Public Methods
void AAnimal::makeSound(void)const
{
	std::cout << "AAnimal sound" << std::endl;
}

// Getter
std::string	AAnimal::getType(void)const
{
	return _type;
}