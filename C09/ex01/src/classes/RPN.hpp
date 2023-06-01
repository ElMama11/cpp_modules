#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <iostream>
# include <cctype>
# include <sstream>
# include <stack>
# include <cstdlib>

class RPN {

	public:
		RPN();
		RPN(const RPN &cpy);
		RPN&	operator=(const RPN &rhs);
		~RPN();

		void	process(const std::string &expr);
		bool	isOperator(char c);
		void	calculate(int num1, int num2, char op);
		int		getResult();

		class insufficientOperands : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: insufficient operands");
				}
		};

		class invalidToken : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error");
				}
		};

		class tooManyOperands : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: too many operands");
				}
		};

		class divisionByZero : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: division by zero");
				}
		};

	private:
		std::stack<int> _stack;
		int				_result;

};

std::ostream&	operator<<(std::ostream& o, RPN &i);
#endif