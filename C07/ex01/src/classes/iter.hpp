#ifndef ITER_HPP
# define ITER_HPP

# include <string>
# include <iostream>

template<typename T>
void iter(T *array, size_t size, void (*ft)(T const &x)) {
	for (size_t i = 0; i < size; i++)
		ft(array[i]);
}

#endif