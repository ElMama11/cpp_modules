/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:39:49 by mverger           #+#    #+#             */
/*   Updated: 2023/06/02 16:19:07 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/Bureaucrat.hpp"
#include <cstdlib>
#include "classes/PresidentialPardonForm.hpp"
#include "classes/RobotomyRequestForm.hpp"
#include "classes/ShrubberyCreationForm.hpp"
#include "classes/Intern.hpp"

void test_form(Form &form, Bureaucrat &correct)
{
	correct.signForm(form);
	correct.executeForm(form);
}

int main()
{
	srand(time(NULL));

	Bureaucrat slave("SLAVE", 1);
	Intern intern;

	Form *form;
	try
	{
		form = intern.makeForm("RobotomyRequestForm", "target"); //PresidentialPardonForm | RobotomyRequestForm | ShrubberyCreationForm
		test_form(*form, slave);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}