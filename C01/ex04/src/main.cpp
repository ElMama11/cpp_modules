/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:21:00 by mverger           #+#    #+#             */
/*   Updated: 2023/02/23 15:44:37 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "classes/SedV2.hpp"

int main(int ac, char **av) {
    if (ac != 4)
	{
        std::cerr << "Usage: ./SedV2 <filename> <to_find> <replace>." << std::endl;
        return 1;
    }
	else
	{
        SedV2   sed2(av[1]);
        sed2.replace(av[2], av[3]);
    }
    return 0;
}