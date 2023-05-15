/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:39:49 by mverger           #+#    #+#             */
/*   Updated: 2023/05/15 15:01:44 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/Conv.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "need one argument" << std::endl;
		return 1;
	}
	Conv conv(av[1]);

	std::cout << conv;
	return 0;
}