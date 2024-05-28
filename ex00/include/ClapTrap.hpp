/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/27 17:01:24 by fras          #+#    #+#                 */
/*   Updated: 2024/05/28 09:27:01 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

class ClapTrap
{
private:
	/* data */
public:
	ClapTrap();
	ClapTrap(const ClapTrap& other);
	~ClapTrap();
	ClapTrap& operator=(const ClapTrap& other);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);	
	void beRepaired(unsigned int amount);
};

#endif