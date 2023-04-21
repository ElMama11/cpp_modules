/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:36:19 by mverger           #+#    #+#             */
/*   Updated: 2023/04/21 21:22:28 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		materia[i] = NULL;
}


MateriaSource::MateriaSource(MateriaSource const & src)
{
	*this = src;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	if (materia[i])
			 delete materia[i];
}

MateriaSource& MateriaSource::operator=(MateriaSource const & rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
			materia[i] = rhs.materia[i];
	}
	return *this;
}

/* Public ft*/

void    MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
		if (materia[i] == NULL)
		{
			materia[i] = m;
			return;
		}
	std::cout << "Slot for materias are full" << std::endl;
}

AMateria   *MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++)
		if (materia[i] && materia[i]->getType() == type)
			return materia[i]->clone();
	return NULL;
}

// AMateria* MateriaSource::getMateria(std::string const &type)
// {
//     for (int i = 0; i < 4; i++)
//         if (materia[i] && materia[i]->getType() == type)
//             return materia[i];
//     return NULL;
// }