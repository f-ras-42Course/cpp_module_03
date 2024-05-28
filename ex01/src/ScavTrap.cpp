/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/28 15:00:29 by fras          #+#    #+#                 */
/*   Updated: 2024/05/28 22:12:54 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name)
: ClapTrap(name)
{
	std::cout << "ScavTrap constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& other)
: ClapTrap(other)
{

	std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap deconstructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap copy assignment operator called\n";
	if (this != &other)
		name_ = other.name_;
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (!energy_points_)
	{
		std::cout << "ScavTrap " << name_ << " has no energy points left\n";
		return ;
	}
	if (target == name_)
	{
		std::cout << "ScavTrap " << name_ << " heals itself and restores "\
				<< attack_damage_ << " hit points\n";
		beRepaired(attack_damage_);
	}
	else
	{
		std::cout << "ScavTrap " << name_ << " attacks " << target \
				<< " causing " << attack_damage_ << " points of damage!\n";
		takeDamage(attack_damage_);
	}
	energy_points_ -= 1;
}
