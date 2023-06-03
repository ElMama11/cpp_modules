/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:39:49 by mverger           #+#    #+#             */
/*   Updated: 2023/06/03 13:40:15 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/easyfind.hpp"

int main( void ) {
	std::list<int> lst1;

	lst1.push_back(1);
	lst1.push_back(5);
	lst1.push_back(10);
	lst1.push_back(20);
	
	std::list<int>::iterator a =  easyfind(lst1, 10);
	if (a == lst1.end())
		std::cout << "Value isn't in the container" << std::endl;
	else
		std::cout << *a << std::endl;
	return 0;
}