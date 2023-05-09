#ifndef INTERN_HPP
#define INTERN_HPP

# include "Bureaucrat.hpp"
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"


class Intern
{
	public:
		Intern();
		Intern(Intern const &cpy);
		Intern &operator=(Intern const &rhs);
		~Intern();

		Form *makeForm(std::string form_name, std::string target);

	class UnknownFormException : public std::exception
	{
		public:
			const char *what() const throw()
			{
				return ("This form name doesn't exist.");
			}
	};
};

#endif