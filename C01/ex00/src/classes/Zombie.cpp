/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:48:17 by mverger           #+#    #+#             */
/*   Updated: 2023/02/14 19:00:56 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	_name = name;
}

Zombie::~Zombie() {
	std::cout << "Zombie " << _name << " erased." << std::endl;
}

void Zombie::Announce() {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}