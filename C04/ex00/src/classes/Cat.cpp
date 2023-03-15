/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:22:06 by mverger           #+#    #+#             */
/*   Updated: 2023/03/15 18:57:02 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	type = "Cat";
	std::cout << "Default constructor called for Cat" << std::endl;
}

Cat::Cat(const Cat &copy) {
	*this = copy;
	std::cout << "Copy constructor called for Cat" << std::endl;
}

Cat::~Cat() {
	std::cout << "Destructor called for Cat" << std::endl;

}

/* Operator overload*/

Cat &Cat::operator=(const Cat &rhs) {
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return *this;
}

/* Member functions*/

void Cat::makeSound(void) {
	std::cout << "Miaou" << std::endl;
}