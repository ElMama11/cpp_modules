/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:39:49 by mverger           #+#    #+#             */
/*   Updated: 2023/05/08 18:02:58 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "classes/Bureaucrat.hpp"

int main(void) {

	/* Can be sign */
	Bureaucrat slave("Slave", 148);
	Form form1("AB", 149, 145);
	
	std::cout << "status of form1 : " << form1.getIsSigned() << std::endl;
	slave.signForm(form1);
	std::cout << "status of form1 : " << form1.getIsSigned() << std::endl << std::endl;

	/* Can't be sign */
	
	Bureaucrat slave2("Jeandroitos", 150);
	Form form2("CD", 100, 145);

	std::cout << "status of form2 : " << form2.getIsSigned() << std::endl;
	slave2.signForm(form2);
	std::cout << "status of form2 : " << form2.getIsSigned() << std::endl;

	std::cout << form2 << std::endl;

	return 0;
}