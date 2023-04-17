#ifndef ICE_HPP
# define ICE_HPP

# include <string>
# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria {

	public:
		Ice();
		Ice(const Ice &cpy);
		~Ice();
		Ice &operator=(const Ice &rhs);
		
		void		use(ICharacter &target);
		AMateria	*clone() const;

};


#endif