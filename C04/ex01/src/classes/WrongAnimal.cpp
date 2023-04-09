/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:51:05 by mverger           #+#    #+#             */
/*   Updated: 2023/03/17 15:51:55 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "Default constructor called for WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
	*this = copy;
	std::cout << "Copy constructor called for WrongAnimal" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Destructor called for WrongAnimal" << std::endl;

}

/* Operator overload*/

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs) {
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return *this;
}

/* Member functions*/

void WrongAnimal::makeSound(void) {
	std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType(void) {
	return type;
}