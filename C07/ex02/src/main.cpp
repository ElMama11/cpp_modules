/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:39:49 by mverger           #+#    #+#             */
/*   Updated: 2023/05/19 18:22:51 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/Array.hpp"

int main(void) {
	
	Array<int> a();
	Array<int> b(3);

	b[0] = 1;
	b[1] = 2;
	b[2] = 3;
	
	std::cout << b[0] << std::endl;
	std::cout << b[1] << std::endl;
	std::cout << b[2] << std::endl;

	try
	{
		std::cout << b[3] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}