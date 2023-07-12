/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:39:49 by mverger           #+#    #+#             */
/*   Updated: 2023/07/12 16:55:05 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/PmergeMe.hpp"
int check_numbers(char **av) {
	int i = 1;
	while (av[i]) {
		int nb = atoi(av[i]);
		if ((nb == 0 && av[i][0] != '0') || nb < 0) {
			std::cerr << "Only positive numbers" << std::endl;
			return 1;
		}
		i++;
	}
	return 0;
}

int main(int ac, char **av)
{
	if (ac < 2) {
		std::cerr << "Need at least two numbers" << std::endl;
		return 1;
	}
	else
		if (check_numbers(av))
			return 1;
	PmergeMe pmergeme(av);
	 std::cout << "Before: ";
    pmergeme.printList();

    long duration = pmergeme.sortVector();

    std::cout << "After:  ";
    pmergeme.printVector();

    std::cout << "Time to process range of " << ac - 1
              << " elements with std::vector: " << duration << " microseconds"
              << std::endl;

    duration = pmergeme.sortList();

    std::cout << "Time to process range of " << ac - 1
              << " elements with std::list: " << duration << " microseconds"
              << std::endl;
	return 0;
}