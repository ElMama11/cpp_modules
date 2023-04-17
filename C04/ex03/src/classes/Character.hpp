#ifndef CHARACTER_HPP
# define CHARACTERR_HPP

# include <string>
# include <iostream>
# include "AMateria.hpp"

class Character : public ICharacter
{
	public :
		Character();
		Character(std::string name);
		Character(const Character &cpy);
		~Character();
		Character &operator=(const Character &cpy);

		
	private :
		AMateria	_inventory[4];
		std::string	_name;
};

#endif