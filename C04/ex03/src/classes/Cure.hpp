#ifndef CURE_HPP
# define CURE_HPP

# include <string>
# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria {

	public:
		Cure();
		Cure(const Cure &cpy);
		virtual ~Cure();
		Cure &operator=(const Cure &rhs);

		AMateria *clone() const;
		void use(ICharacter &target);

};


#endif