/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/27 16:28:09 by fras          #+#    #+#                 */
/*   Updated: 2024/08/22 13:32:29 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap pjotr("Pjotr");	
	ClapTrap kees("Kees");
	for (size_t i = 0; i < 12; i++)
	{
		pjotr.attack(kees);
	}
	for (size_t i = 0; i < 12; i++)
	{
		kees.attack(kees);
	}
}
