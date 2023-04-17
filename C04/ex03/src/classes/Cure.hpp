#ifndef CURE_HPP
# define CURE_HPP

# include <string>
# include <iostream>
# include "AMateria.hpp"

class AMateria {

	public:
		AMateria();
		AMateria(std::string const &type);
		AMateria(const AMateria &cpy);
		virtual ~AMateria();
		AMateria &operator=(const AMateria &rhs);

		std::string const &getType() const; //Returns the materia type
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);

	protected:
		std::string _type;
};


#endif