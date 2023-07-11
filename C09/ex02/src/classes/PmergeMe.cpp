/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:15:34 by mverger           #+#    #+#             */
/*   Updated: 2023/07/11 18:06:11 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(char **av) {
	int i = 1;
	std::list<unsigned int>::iterator ite = _numbersList.begin();
	std::vector<unsigned int>::iterator iteV;
	while (av[i]) {
		iteV = _numbersVector.begin();
		_numbersList.insert(ite, atoi(av[i]));
		_numbersVector.insert(iteV, atoi(av[i]));
		i++;
	}
	std::cout << _numbersList.front() << std::endl;
	std::cout << _numbersList.back() << std::endl;
	std::cout << _numbersVector.front() << std::endl;
	std::cout << _numbersVector.back() << std::endl;
}

PmergeMe::~PmergeMe() {
}