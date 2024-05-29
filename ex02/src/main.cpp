/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/27 16:28:09 by fras          #+#    #+#                 */
/*   Updated: 2024/05/29 16:46:14 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap pjotr("Pjotr");	
	ScavTrap kees("Kees");
	ScavTrap karel("Karel");
	
	for (size_t i = 0; i < 6; i++)
	{
		pjotr.attack("Kees");
		kees.takeDamage(20);
	}
	for (size_t i = 0; i < 6; i++)
	{
		kees.attack("pjotr");;
	}
	for (size_t i = 0; i < 6; i++)
	{
		karel.attack("Karel");
		karel.beRepaired(20);
	}	
	pjotr.guardGate();
	karel.guardGate();
	kees.guardGate();
}
