/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/28 14:59:56 by fras          #+#    #+#                 */
/*   Updated: 2024/08/22 13:45:48 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class FragTrap: public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& other);
		~FragTrap();
		FragTrap& operator=(const FragTrap& other);
		void attack(const std::string& target);
		void attack(FragTrap& target);
		void highFiveGuys();
};

#endif