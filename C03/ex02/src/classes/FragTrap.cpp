/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:39:17 by mverger           #+#    #+#             */
/*   Updated: 2023/03/03 17:00:50 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


FragTrap::FragTrap() : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "Default constructor called for FragTrap." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "String constructor called for FragTrap " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) {
	std::cout << "Copy constructor called for FragTrap " << _name << std::endl;
	*this = copy;
}

FragTrap::~FragTrap() {
	std::cout << "Destructor called for FragTrap " << _name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs) {
	if (this != &rhs)
	{
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}	
	return *this;
}

/* Member functions */

void FragTrap::attack(const std::string &target) {
	if (_hitPoints <= 0)
	{
		std::cout << "FragTrap " << _name << " can't attack, he has " << _hitPoints << " HP." << std::endl;
		return ;
	}
	else if (_energyPoints <= 0)
	{
		std::cout << "FragTrap " << _name << " can't attack, he has " << _energyPoints << " EP." << std::endl;
		return ;
	}
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void FragTrap::takeDamage(unsigned int amount) {
	_hitPoints = _hitPoints - amount;
	std::cout << "FragTrap " << _name << " receive " << amount << " points of damage ! HP left : " << _hitPoints << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
	if (_hitPoints <= 0)
	{
		std::cout << "FragTrap " << _name << " can't be repaired, he has " << _hitPoints << " HP." << std::endl;
		return ;
	}
	else if (_energyPoints <= 0)
	{
		std::cout << "FragTrap " << _name << " can't be repaired, he has " << _energyPoints << " EP." << std::endl;
		return ;
	}
	_energyPoints--;
	_hitPoints = _hitPoints + amount;
	std::cout << "FragTrap " << _name << " repair " << amount << " of HP ! HP now : " << _hitPoints << std::endl;
}

void FragTrap::highFivesGuys(void) {
	if (_hitPoints <= 0)
	{
		std::cout << "FragTrap " << _name << " is out of HP." << std::endl;
		return ;
	}
	else if (_energyPoints <= 0)
	{
		std::cout << "FragTrap " << _name << " is out of energy." << std::endl;
		return ;
	}
	std::cout << "FragTrap " << _name << " high fives his mates" << std::endl;
	_energyPoints -= 1;
}
