/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:28:51 by mverger           #+#    #+#             */
/*   Updated: 2023/04/22 17:57:56 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string name) : ICharacter(), _name(name) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character &cpy) {
	_name = cpy._name;
	*this = cpy;
	std::cout << "Character " << _name << " created" << std::endl;
}

Character::~Character()
{
	std::cout << "Character " << _name << " destroyed" << std::endl;
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
}

Character &Character::operator=(Character const & rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		for (int i = 0; i < 4; i++)
			if (_inventory[i])
				delete _inventory[i];
		for (int i = 0; i < 4; i++)
			_inventory[i] = rhs._inventory[i];
	}
	return *this;
}

/* Public ft */

std::string const &Character::getName() const {
	return _name;
}

void Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++)
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			std::cout << _name << " equip " << m->getType() << std::endl;
			return ;
		}
	std::cout << _name << " can't equip " << m->getType() << ", inventory is full" << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		return;
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
	if (_inventory[idx] != NULL) {
		_inventory[idx]->use(target);
	}
	else
		std::cout << "Materia doesn't exist" << std::endl;
}
