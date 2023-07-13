/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:39:49 by mverger           #+#    #+#             */
/*   Updated: 2023/07/13 17:46:23 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/PmergeMe.hpp"

int check_numbers(char **av) {
	int i = 1, j;
	while (av[i])
	{
		j = 0;
		int nb = atoi(av[i]);
		while (av[i][j])
		{
			if ((nb == 0 && av[i][0] != '0') || nb < 0 || av[i][j] < '0' || av[i][j] > '9') {
				std::cerr << "Only positive numbers" << std::endl;
				return 1;
			}
			j++;
		}
		i++;
	}
	return 0;
}

template <class T>
void print_container(const std::string &mesg, const T &c)
{
	typedef typename T::const_iterator const_iterator;

	std::cout << mesg;
	for (const_iterator it = c.begin(); it != c.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template <class T>
double bench_container(T &c)
{
	std::clock_t start = std::clock();
	PmergeMe::process(c);
	std::clock_t end = std::clock();
	double elapsed = 1000000.0 * (end - start) / CLOCKS_PER_SEC;
	return elapsed;
}



int main(int ac, char **av)
{
	if (ac < 3) {
		std::cerr << "Need at least two numbers" << std::endl;
		return 1;
	}
	else
		if (check_numbers(av))
			return 1;

	std::vector<int> v;
	std::deque<int> d;
	int i = 1;
	while (av[i])
	{
		d.push_back(atoi(av[i]));
		v.push_back(atoi(av[i]));
		i++;
	}

	print_container("Before: ", v);

	double time_vector = bench_container(v);
	double time_deque = bench_container(d);

	print_container("After: ", v);

	std::cout << "Time to process a range of " << v.size() << " elements with std::vector : " << time_vector << " us\n";
	std::cout << "Time to process a range of " << d.size() << " elements with std::deque : " << time_deque << " us\n";
	return 0;
}