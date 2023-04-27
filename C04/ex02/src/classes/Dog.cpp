/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:22:01 by mverger           #+#    #+#             */
/*   Updated: 2023/04/27 17:02:23 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	type = "Dog";
	std::cout << "Default constructor called for Dog" << std::endl;
	_brain = new Brain();
	if (_brain == NULL)
	{
		perror("Dog Brain allocation failed");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}
}

Dog::Dog(const Dog &copy) {
	*this = copy;
	std::cout << "Copy constructor called for Dog" << std::endl;
}

Dog::~Dog() {
	std::cout << "Destructor called for Dog" << std::endl;
	delete  _brain;
}

/* Operator overload*/

Dog &Dog::operator=(const Dog &rhs) {
	std::cout << "Dog = called." << std::endl;
	if (this != &rhs)
	{
		type = rhs.type;
		_brain = new Brain(*rhs._brain );
	}
	return *this;
}

/* Member functions*/

void Dog::makeSound(void) {
	std::cout << "Ouaf ouaf" << std::endl;
}