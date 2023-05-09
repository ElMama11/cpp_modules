/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:39:49 by mverger           #+#    #+#             */
/*   Updated: 2023/05/09 16:18:23 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/Bureaucrat.hpp"
#include <cstdlib>
#include "classes/PresidentialPardonForm.hpp"
#include "classes/RobotomyRequestForm.hpp"
#include "classes/ShrubberyCreationForm.hpp"

void test_form(Form &form, Bureaucrat &correct, Bureaucrat &ERROR)
{
	ERROR.signForm(form);
	correct.executeForm(form);
	correct.signForm(form);
	ERROR.executeForm(form);
	correct.executeForm(form);
}

int main()
{
	srand(time(NULL));

	Bureaucrat SLAVE("SLAVE", 1);
	Bureaucrat ERROR("ERROR", 150);

	ShrubberyCreationForm form1("Target");
	RobotomyRequestForm form2("Target");
	PresidentialPardonForm form3("Target");
	
	test_form(form1, SLAVE, ERROR);
	test_form(form2, SLAVE, ERROR);
	test_form(form3, SLAVE, ERROR);

	return 0;
}