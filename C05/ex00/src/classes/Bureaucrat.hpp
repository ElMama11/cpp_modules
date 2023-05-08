#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Bureaucrat {

	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &cpy);
		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat &rhs);

		std::string getName();
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();

		/* Exception Class */
		class GradeTooHighException : public std::exception {
			public :
				virtual const char* what() const throw() {
					return ("grade too high");
				}
		};

		class GradeTooLowException : public std::exception {
			public :
				virtual const char* what() const throw() {
					return ("grade too low");
				}
		};

	private:
		const std::string	_name;
		int					_grade;

};

std::ostream &operator<<(std::ostream &o, Bureaucrat &rhs);

#endif