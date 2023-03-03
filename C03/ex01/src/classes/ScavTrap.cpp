/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:21:52 by mverger           #+#    #+#             */
/*   Updated: 2023/03/03 16:10:44 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "Default constructor called for ScavTrap." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "String constructor called for ScavTrap " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) {
	*this = copy;
}

ScavTrap::~ScavTrap() {
	std::cout << "Destructor called for ScavTrap " << _name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
	if (this != &rhs)
	{
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}	
	return *this;
}

/* Member functions */

void ScavTrap::attack(const std::string &target) {
	if (_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " can't attack, he has " << _hitPoints << " HP." << std::endl;
		return ;
	}
	else if (_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " can't attack, he has " << _energyPoints << " EP." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void ScavTrap::takeDamage(unsigned int amount) {
	_hitPoints = _hitPoints - amount;
	std::cout << "ScavTrap " << _name << " receive " << amount << " points of damage ! HP left : " << _hitPoints << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
	if (_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " can't be repaired, he has " << _hitPoints << " HP." << std::endl;
		return ;
	}
	else if (_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " can't be repaired, he has " << _energyPoints << " EP." << std::endl;
		return ;
	}
	_energyPoints--;
	_hitPoints = _hitPoints + amount;
	std::cout << "ScavTrap " << _name << " repair " << amount << " of HP ! HP now : " << _hitPoints << std::endl;
}

void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << _name << " has entering in Gate keeper mode" << std::endl;
}