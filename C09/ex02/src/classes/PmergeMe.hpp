#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <list>
# include <vector>
# include <cstdlib>
# include <limits.h>
# include <sys/time.h>

class PmergeMe {

	public:
		PmergeMe();
		PmergeMe(char **av);
		PmergeMe(const PmergeMe &cpy);
		~PmergeMe();

		PmergeMe &operator=(const PmergeMe &rhs);

		long sortVector();
		long sortList();
		void printVector();
		void printList();

	private:
		std::list<int>		_numbersList;
		std::vector<int>	_numbersVector;

		void vector_merge(int left, int middle, int right);
		void vector_mergeSort(int left, int right);

		void list_merge(int left, int middle, int right);
		void list_mergeSort(int left, int right);

		long getTimestamp() const;
};

#endif