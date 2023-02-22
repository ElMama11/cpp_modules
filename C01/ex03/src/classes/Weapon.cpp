/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:16:40 by mverger           #+#    #+#             */
/*   Updated: 2023/02/22 17:43:21 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {
}

Weapon::Weapon(std::string type) {
	_type = type;
}

Weapon::~Weapon() {
}

const std::string	&Weapon::getType(void) {
	return _type;
}

void Weapon::setType(std::string ValueForType) {
	_type = ValueForType;
}