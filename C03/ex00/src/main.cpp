/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:58:45 by mverger           #+#    #+#             */
/*   Updated: 2023/02/28 17:43:54 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "classes/ClapTrap.hpp"

int main( void ) {
	
	ClapTrap a;
	ClapTrap b("BOT");
	
	a.attack("some other robot");
	a.takeDamage(10);
	a.beRepaired(5);
	a.attack("some other other robot");
	
	b.beRepaired(3);
	for (int i = 0; i < 12; i++)
		b.attack("RandomGuy");
	b.beRepaired(3);

	return 0;
}
