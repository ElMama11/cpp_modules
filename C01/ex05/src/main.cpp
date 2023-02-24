/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:21:00 by mverger           #+#    #+#             */
/*   Updated: 2023/02/24 16:22:20 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "classes/Harl.hpp"

int main(void) {

    std::string input;
    Harl        harl;

    std::cout << "Usage: DEBUG, INFO, WARNING or ERROR." << std::endl << std::endl;
    while (input.compare("exit"))
    {
        std::cout << "Enter a level: ";
        std::cin >> input;
        harl.complain(input);
	}
    return 0;
}