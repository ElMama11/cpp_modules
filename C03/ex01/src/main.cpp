/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:58:45 by mverger           #+#    #+#             */
/*   Updated: 2023/03/03 16:15:49 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "classes/ScavTrap.hpp"

int main( void ) {
	
	ScavTrap a("BOT");
	
	a.attack("some other robot");
	a.takeDamage(20);
	a.beRepaired(5);
	a.guardGate();

	return 0;
}
