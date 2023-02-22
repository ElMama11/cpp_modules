/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:16:35 by mverger           #+#    #+#             */
/*   Updated: 2023/02/22 17:38:37 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	_name = name;
	_weapon = NULL;
}

HumanB::~HumanB() {
}

void HumanB::attack(void) {
	if (_weapon == NULL)
	{
		std::cout << "No weapon" << std::endl;
		return ;
	}
	std::cout << _name << " attack with their " << _weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}