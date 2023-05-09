/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:23:55 by mverger           #+#    #+#             */
/*   Updated: 2023/05/09 17:03:10 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
}

Intern::Intern(Intern const &cpy) {
	*this = cpy;
}

Intern &Intern::operator=(Intern const &rhs) {
	(void)rhs;
	return *this;
}

Intern::~Intern() {
}

/* Public ft */

Form *Intern::makeForm(std::string form_name, std::string target) {
	std::string formsNames[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	Form *(*formsCreateFt[3])(std::string const &target) = {&ShrubberyCreationForm::create, &RobotomyRequestForm::create, &PresidentialPardonForm::create};
	
	for (int i = 0; i < 4; i++)
	{
		if (formsNames[i] == form_name) {
			std::cout << "Intern creates " << form_name << std::endl;
			return formsCreateFt[i](target);
		}
	}
	throw Intern::UnknownFormException();
}
