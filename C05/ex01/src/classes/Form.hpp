#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	public :
		Form();
		Form(std::string name, int grade_to_sign, int grade_to_execute);
		Form(const Form &cpy);
		~Form();
		Form &operator=(const Form &rhs);

		std::string	getName() const;
		bool		getIsSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		void		beSigned(Bureaucrat bureaucrat);

		/* Exception class */
		class GradeTooHighException : public std::exception {
			public :
				virtual const char *what() const throw() {
					return ("this error has no sense");
				}
		};

		class GradeTooLowException : public std::exception {
			public :
				virtual const char *what() const throw() {
					return ("The grade of the bureaucrat is too low for this form.");
				}
		};

	private :
		const std::string _name;
		bool		_is_signed;
		const int			_grade_to_sign;
		const int			_grade_to_execute;
};

std::ostream &operator<<(std::ostream &o, Form &rhs);
#endif