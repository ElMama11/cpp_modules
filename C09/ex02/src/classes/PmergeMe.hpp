#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <iostream>
# include <cctype>
# include <sstream>
# include <list>
# include <vector>
# include <cstdlib>

class PmergeMe {

	public:
		PmergeMe();
		PmergeMe(char **av);
		PmergeMe(const PmergeMe &cpy);
		~PmergeMe();

		PmergeMe &operator=(const PmergeMe &rhs);

	private:
		std::list<unsigned int>		_numbersList;
		std::vector<unsigned int>	_numbersVector;
};

#endif