/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:58:45 by mverger           #+#    #+#             */
/*   Updated: 2023/03/15 19:15:07 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "classes/ScavTrap.hpp"
# include "classes/FragTrap.hpp"

int main( void ) {
	
    FragTrap a("BOT");

    a.attack("nobody");
    a.takeDamage(30);
    a.beRepaired(10);
    a.highFivesGuys();

	return 0;
}
