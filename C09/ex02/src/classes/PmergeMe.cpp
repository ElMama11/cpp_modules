/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:15:34 by mverger           #+#    #+#             */
/*   Updated: 2023/07/12 17:05:37 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(char **av) {
	int i = 1;
	std::list<int>::iterator ite = _numbersList.begin();
	std::vector<int>::iterator iteV;
	while (av[i])
	{
		iteV = _numbersVector.begin();
		_numbersList.insert(ite, atoi(av[i]));
		_numbersVector.insert(iteV, atoi(av[i]));
		i++;
	}
}

PmergeMe::PmergeMe(const PmergeMe &cpy) {
	*this = cpy;
}

PmergeMe::~PmergeMe() {
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
	if (this != &rhs)
	{
		_numbersList = rhs._numbersList;
		_numbersVector = rhs._numbersVector;
	}
	return *this;
}

void PmergeMe::vector_merge(int left, int middle, int right) {
	int sizeLeftVector = middle - left + 1;
	int sizeRightVector = right - middle;

	std::vector<int> leftVector;
	std::vector<int> rightVector;

	for (int i = 0; i < sizeLeftVector; i++)
	{
		leftVector.push_back(_numbersVector[left + i]);
	}
	for (int j = 0; j < sizeRightVector; j++)
	{
		rightVector.push_back(_numbersVector[middle + 1 + j]);
	}

	// index of leftVector, rightVector and _numbersVector
	int i = 0, j = 0, k = left;

	while (i < sizeLeftVector && j < sizeRightVector)
	{ // merge
		if (leftVector[i] <= rightVector[j])
		{
			_numbersVector[k] = leftVector[i];
			i++;
		}
		else
		{
			_numbersVector[k] = rightVector[j];
			j++;
		}
		k++;
	}

	while (i < sizeLeftVector)
	{ // if leftVector is bigger
		_numbersVector[k] = leftVector[i];
		i++;
		k++;
	}

	while (j < sizeRightVector)
	{ // if rightVector is bigger
		_numbersVector[k] = rightVector[j];
		j++;
		k++;
	}
}

void PmergeMe::vector_mergeSort(int left, int right) {
	if (left < right)
	{
		int middle = (left + right) / 2;
		vector_mergeSort(left, middle);
		vector_mergeSort(middle + 1, right);
		vector_merge(left, middle, right);
	}
}

long PmergeMe::sortVector() {
	long start = getTimestamp();

	if (_numbersVector.size() <= 5)
	{
		// insert sort
		for (size_t i = 1; i < _numbersVector.size(); i++)
		{
			size_t j = i;
			while (j > 0 && _numbersVector[j - 1] > _numbersVector[j])
			{
				std::swap(_numbersVector[j - 1], _numbersVector[j]);
				j--;
			}
		}
	}
	else
	{
		// merge sort
		int left = 0;
		int right = _numbersVector.size() - 1;
		vector_mergeSort(left, right);
	}

	long end = getTimestamp();
	return end - start;
}

void PmergeMe::list_merge(int left, int middle, int right) {
	int sizeLeftList = middle - left + 1;
	int sizeRightList = right - middle;

	std::list<int> leftList;
	std::list<int> rightList;
	for (int i = 0; i < sizeLeftList; i++)
	{
		std::list<int>::iterator it = _numbersList.begin();
		std::advance(it, left + i);
		leftList.push_back(*it);
	}
	for (int j = 0; j < sizeRightList; j++)
	{
		std::list<int>::iterator it = _numbersList.begin();
		std::advance(it, middle + 1 + j);
		rightList.push_back(*it);
	}

	std::list<int>::iterator itLeft = leftList.begin();
	std::list<int>::iterator itRight = rightList.begin();
	std::list<int>::iterator it = _numbersList.begin();
	std::advance(it, left);

	while (itLeft != leftList.end() && itRight != rightList.end())
	{
		if (*itLeft <= *itRight)
		{
			*it = *itLeft;
			itLeft++;
		}
		else
		{
			*it = *itRight;
			itRight++;
		}
		it++;
	}

	while (itLeft != leftList.end())
	{
		*it = *itLeft;
		itLeft++;
		it++;
	}

	while (itRight != rightList.end())
	{
		*it = *itRight;
		itRight++;
		it++;
	}
}

void PmergeMe::list_mergeSort(int left, int right) {
	if (left < right)
	{
		int middle = (left + right) / 2;
		list_mergeSort(left, middle);
		list_mergeSort(middle + 1, right);
		list_merge(left, middle, right);
	}
}

long PmergeMe::sortList() {
	long start = getTimestamp();
	std::list<int>::iterator itprev = _numbersList.begin();
	int j = 0;

	if (_numbersList.size() <= 5)
	{
		// insert sort
		for (std::list<int>::iterator it = _numbersList.begin(); it != _numbersList.end(); it++)
		{
			if (j >= 1)
				itprev++;
			std::list<int>::iterator it2 = it;
			while (it2 != _numbersList.begin() && *itprev > *it2)
			{ // if prev is bigger
				std::swap(*itprev, *it2);
				it2--;
			}
			j++;
		}
	}
	else
	{
		// merge sort
		size_t left = 0;
		size_t right = _numbersList.size() - 1;
		list_mergeSort(left, right);
	}

	long end = getTimestamp();
	return end - start;
}

void PmergeMe::printVector() {
	for (std::vector<int>::const_iterator it = _numbersVector.begin();
		 it != _numbersVector.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printList() {
	for (std::list<int>::const_iterator it = _numbersList.begin();
		 it != _numbersList.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

long PmergeMe::getTimestamp() const {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * (int)1e6 + tv.tv_usec;
}