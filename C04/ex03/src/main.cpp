/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:58:45 by mverger           #+#    #+#             */
/*   Updated: 2023/04/22 17:58:24 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "classes/AMateria.hpp"
# include "classes/Character.hpp"
# include "classes/MateriaSource.hpp"
# include "classes/Ice.hpp"
# include "classes/Cure.hpp"


int main( void ) {

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* Cloud = new Character("Cloud");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	Cloud->equip(tmp);
	tmp = src->createMateria("cure");
	Cloud->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	
	Cloud->use(0, *bob);
	Cloud->use(1, *bob);
	
	delete bob;
	delete Cloud;
	delete src;

    return 0;
}