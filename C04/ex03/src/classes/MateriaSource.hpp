#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <string>
# include <iostream>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public : 
		MateriaSource();
		MateriaSource(const MateriaSource &cpy);
		~MateriaSource();
		MateriaSource &operator=(const MateriaSource &rhs);

		AMateria	*createMateria(std::string const &type);
		void		learnMateria(AMateria*);

	private :
		AMateria *materia[4];
};

#endif