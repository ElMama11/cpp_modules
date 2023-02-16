/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:52:13 by mverger           #+#    #+#             */
/*   Updated: 2023/02/16 15:09:04 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
# include <iostream>

int main (void) {
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << &str << ": " << str << std::endl;
    std::cout << stringPTR << ": " << *stringPTR << std::endl;
    std::cout << &stringREF << ": " << stringREF << std::endl;
	return 0;
}