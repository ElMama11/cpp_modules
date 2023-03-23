/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:38:26 by mverger           #+#    #+#             */
/*   Updated: 2023/03/17 16:52:49 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	type = "WrongCat";
	std::cout << "Default constructor called for WrongCat" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) {
	*this = copy;
	std::cout << "Copy constructor called for WrongCat" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "Destructor called for WrongCat" << std::endl;

}

/* Operator overload*/

WrongCat &WrongCat::operator=(const WrongCat &rhs) {
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return *this;
}

/* Member functions*/

void WrongCat::makeSound(void) {
	std::cout << "WrongCat sound" << std::endl;
}