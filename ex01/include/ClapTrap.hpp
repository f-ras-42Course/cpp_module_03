/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/27 17:01:24 by fras          #+#    #+#                 */
/*   Updated: 2024/08/22 13:45:38 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	protected:
		std::string name_;
		int hit_points_;
		int energy_points_;
		int attack_damage_;
	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& other);
		~ClapTrap();
		ClapTrap& operator=(const ClapTrap& other);
		void attack(const std::string& target);
		void attack(ClapTrap& target);
		void takeDamage(unsigned int amount);	
		void beRepaired(unsigned int amount);
};

#endif