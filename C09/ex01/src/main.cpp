/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:39:49 by mverger           #+#    #+#             */
/*   Updated: 2023/06/01 18:10:25 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/RPN.hpp"

int main(int ac, char **av)
{
	RPN	rpn;

	if (ac != 2)
		std::cerr << "Too many args"<< std::endl;
	else
	{
		try
		{
			rpn.process(av[1]);
			std::cout << rpn << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}