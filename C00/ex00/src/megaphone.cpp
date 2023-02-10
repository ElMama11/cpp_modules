/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:57:47 by mverger           #+#    #+#             */
/*   Updated: 2023/02/07 18:13:43 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdio>

int main(int ac, char **av) {
	
	if (ac > 1)
	{
		for(int i = 1; i < ac; i++)
			for(size_t j = 0; j < strlen(av[i]); j++)	
				putchar(toupper(av[i][j]));
	}
	else
		std::cout <<"* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return 0;
}