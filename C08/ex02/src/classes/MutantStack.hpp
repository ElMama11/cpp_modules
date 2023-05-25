#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <string>
# include <iostream>
# include <algorithm>
# include <stack>
# include <list>
# include <deque>

template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	
	public :
		MutantStack() {};
		MutantStack(const MutantStack &cpy) {*this = cpy;}
		MutantStack &operator=(const MutantStack &rhs)
		{
			std::stack< T, Container >::operator=(rhs);
			return *this;
		};
		~MutantStack() {};

		typename Container::iterator begin(void) {return this->c.begin();}
		typename Container::iterator end(void) {return this->c.end();}
};
#endif