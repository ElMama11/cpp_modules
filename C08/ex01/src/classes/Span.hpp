#ifndef SPAN_HPP
# define SPAN_HPP

# include <string>
# include <iostream>
# include <algorithm>
# include <limits.h>
# include <list>

class Span {

	public :
		Span();
		Span(unsigned int n);
		Span(const Span &cpy);
		~Span();

		Span &operator=(const Span &rhs);

		/* Member ft */
		void	addNumber(unsigned int nb);
		void	addNumbers(std::list<int>::const_iterator, std::list<int>::const_iterator);
		int		shortestSpan(void);
		int		longestSpan(void);

		/* Exception class */
		class CantAddNumber : public std::exception {
			public :
				virtual const char *what() const throw() {
					return ("The list is full.");
				}
		};

		class TooFewNumber : public std::exception {
			public :
				virtual const char *what() const throw() {
					return ("Need more than 1 number.");
				}
		};

	private :
		unsigned int	_n;
		std::list<int>	_lst;

};
#endif