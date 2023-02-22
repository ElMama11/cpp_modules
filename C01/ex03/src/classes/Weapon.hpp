/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:16:43 by mverger           #+#    #+#             */
/*   Updated: 2023/02/22 17:10:38 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
	public:
		Weapon(void);
		Weapon(std::string type);
		~Weapon(void);
		
		void				setType(std::string ValueForType);
		const std::string	&getType(void);
		
	private:
		
		std::string _type;
};
#endif