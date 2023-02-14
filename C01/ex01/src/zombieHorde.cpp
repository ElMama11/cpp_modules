/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:34:32 by mverger           #+#    #+#             */
/*   Updated: 2023/02/14 19:52:10 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	Zombie *zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zombies[i].SetZombieName(name);
	}
	return zombies;
}
