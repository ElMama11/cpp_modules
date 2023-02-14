/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:21:00 by mverger           #+#    #+#             */
/*   Updated: 2023/02/14 20:02:28 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/Zombie.hpp"

int main(void) {
	Zombie *horde;
	int n = 10;
	
	horde = zombieHorde(n, "JEAN");
	for (int i = 0; i < n; i++)
		horde[i].Announce();
	delete[] horde;
	return 0;
}