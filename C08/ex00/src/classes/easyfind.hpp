#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <string>
# include <iostream>
# include <algorithm>
# include <list>

template<typename T>
typename T::iterator easyfind(T &int_cont, int to_find) {
	typename T::iterator ite;
	ite = std::find(int_cont.begin(), int_cont.end(), to_find);

	return ite;
}
#endif