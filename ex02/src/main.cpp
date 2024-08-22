/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/27 16:28:09 by fras          #+#    #+#                 */
/*   Updated: 2024/08/22 13:59:55 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	{
		ScavTrap pjotr("Pjotr");	
		ScavTrap kees("Kees");
		ScavTrap karel("Karel");

		for (size_t i = 0; i < 3; i++)
		{
			pjotr.attack(kees);
		}
		for (size_t i = 0; i < 3; i++)
		{
			kees.attack(pjotr);;
		}
		for (size_t i = 0; i < 3; i++)
		{
			karel.attack(karel);
		}	
		pjotr.guardGate();
		karel.guardGate();
		kees.guardGate();
	}
	{
		FragTrap pjotr("Pjotr");	
		FragTrap kees("Kees");
		FragTrap karel("Karel");

		for (size_t i = 0; i < 3; i++)
		{
			pjotr.attack(kees);
		}
		for (size_t i = 0; i < 3; i++)
		{
			kees.attack(pjotr);;
		}
		for (size_t i = 0; i < 3; i++)
		{
			karel.attack(karel);
		}	
		pjotr.highFiveGuys();
		karel.highFiveGuys();
		kees.highFiveGuys();
	}
}
