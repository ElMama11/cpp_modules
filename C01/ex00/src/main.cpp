/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:21:00 by mverger           #+#    #+#             */
/*   Updated: 2023/02/14 19:19:45 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/Zombie.hpp"

int main(void){

	std::string name;

	std::cout << "Creating zombie on the stack. " << "Zombie name: " << std::endl;
	std::cin >> name;
	Zombie zombi1(name);
	zombi1.Announce();

	std::cout << "Creating zombie on the heap. " << "Zombie name: " << std::endl;
	std::cin >> name;
	Zombie *zombi2 = newZombie(name);
	zombi2->Announce();
	delete zombi2;

	std::cout << "\nCalling randomChump()." << std::endl;
	randomChump("RANDOMGUY");
	return 0;
}