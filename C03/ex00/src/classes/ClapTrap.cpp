/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:58:34 by mverger           #+#    #+#             */
/*   Updated: 2023/02/28 17:54:21 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "String constructor called for ClapTrap " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	*this = copy;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called for ClapTrap " << _name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
	if (this != &rhs)
	{
		_hitPoints = rhs._hitPoints;
		_energyPoints = rhs._energyPoints;
		_attackDamage = rhs._attackDamage;
	}	
	return *this;
}

/* Member functions */

void ClapTrap::attack(const std::string &target) {
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " can't attack, he has " << _hitPoints << " HP." << std::endl;
		return ;
	}
	else if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " can't attack, he has " << _energyPoints << " EP." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	_hitPoints = _hitPoints - amount;
	std::cout << "ClapTrap " << _name << " receive " << amount << " points of damage ! HP left : " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " can't be repaired, he has " << _hitPoints << " HP." << std::endl;
		return ;
	}
	else if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " can't be repaired, he has " << _energyPoints << " EP." << std::endl;
		return ;
	}
	_energyPoints--;
	_hitPoints = _hitPoints + amount;
	std::cout << "ClapTrap " << _name << " repair " << amount << " of HP ! HP now : " << _hitPoints << std::endl;
}