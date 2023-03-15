/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:22:01 by mverger           #+#    #+#             */
/*   Updated: 2023/03/15 15:55:02 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	type = "Dog";
	std::cout << "Default constructor called for Dog" << std::endl;
}

Dog::Dog(const Dog &copy) {
	*this = copy;
	std::cout << "Copy constructor called for Dog" << std::endl;
}

Dog::~Dog() {
	std::cout << "Destructor called for Dog" << std::endl;

}

/* Operator overload*/

Dog &Dog::operator=(const Dog &rhs) {
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return *this;
}

/* Member functions*/

void Dog::makeSound(void) {
	std::cout << "Ouaf ouaf" << std::endl;
}