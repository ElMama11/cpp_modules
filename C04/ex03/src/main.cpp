/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:58:45 by mverger           #+#    #+#             */
/*   Updated: 2023/04/27 16:43:23 by mverger          ###   ########.fr       */
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
	AMateria* tmp2;
	tmp = src->createMateria("ice");
	Cloud->equip(tmp);
	tmp2 = src->createMateria("cure");
	Cloud->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	
	Cloud->use(0, *bob);
	Cloud->use(1, *bob);

	Cloud->unequip(0);
	Cloud->unequip(1);
	
	delete tmp;
	delete tmp2;
	
	delete bob;
	delete Cloud;
	delete src;

    return 0;
}