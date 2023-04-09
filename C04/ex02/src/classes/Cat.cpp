/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:22:06 by mverger           #+#    #+#             */
/*   Updated: 2023/03/23 15:51:55 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	type = "Cat";
	std::cout << "Default constructor called for Cat" << std::endl;
	_brain = new Brain();
	if (_brain == NULL)
	{
		perror("Cat Brain allocation failed");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}
}

Cat::Cat(const Cat &copy) {
	*this = copy;
	std::cout << "Copy constructor called for Cat" << std::endl;
}

Cat::~Cat() {
	std::cout << "Destructor called for Cat" << std::endl;
	delete  _brain;
}

/* Operator overload*/

Cat &Cat::operator=(const Cat &rhs) {
	std::cout << "Cat = operator called." << std::endl;
	if (this != &rhs)
	{
		type = rhs.type;
		_brain = new Brain(*rhs._brain);
	}
	return *this;
}

/* Member functions*/

void Cat::makeSound(void) {
	std::cout << "Miaou" << std::endl;
}