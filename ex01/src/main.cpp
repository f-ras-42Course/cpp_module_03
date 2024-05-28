/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/27 16:28:09 by fras          #+#    #+#                 */
/*   Updated: 2024/05/28 22:13:30 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap pjotr("Pjotr");	
	ScavTrap kees("Kees");
	for (size_t i = 0; i < 12; i++)
	{
		pjotr.attack("Kees");
	}
	for (size_t i = 0; i < 12; i++)
	{
		kees.attack("Kees");
	}
}
