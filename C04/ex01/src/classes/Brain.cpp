/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:36:24 by mverger           #+#    #+#             */
/*   Updated: 2023/03/22 15:22:48 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Default constructor called for Brain" << std::endl;
}

Brain::Brain(const Brain &copy) {
	*this = copy;
	std::cout << "Copy constructor called for Brain" << std::endl;
}

Brain::~Brain() {
	std::cout << "Destructor called for Brain" << std::endl;
}

/* Operator overload*/

Brain &Brain::operator=(const Brain &rhs) {
	std::cout << "Brain = operator called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			if (rhs._ideas[i].length() > 0)
				this->_ideas[i].assign(rhs._ideas[i]);
	}
	return *this;
}

/* Member functions*/
