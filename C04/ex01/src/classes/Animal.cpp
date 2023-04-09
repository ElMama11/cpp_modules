/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:21:53 by mverger           #+#    #+#             */
/*   Updated: 2023/03/15 19:03:22 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Default constructor called for Animal" << std::endl;
}

Animal::Animal(const Animal &copy) {
	*this = copy;
	std::cout << "Copy constructor called for Animal" << std::endl;
}

Animal::~Animal() {
	std::cout << "Destructor called for Animal" << std::endl;

}

/* Operator overload*/

Animal &Animal::operator=(const Animal &rhs) {
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return *this;
}

/* Member functions*/

void Animal::makeSound(void) {
	std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType(void) {
	return type;
}