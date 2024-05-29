/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/28 15:00:29 by fras          #+#    #+#                 */
/*   Updated: 2024/05/29 16:45:56 by fras          ########   odam.nl         */
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
	if (hit_points_ <= 0)
	{
		std::cout << "ScavTrap " << name_ << " is dead; cannot heal or attack\n";
	}
	else if (!energy_points_)
	{
		std::cout << "ScavTrap " << name_ << " has no energy points left\n";
	}
	else if (target == name_)
	{
		std::cout << "ScavTrap " << name_ << " heals itself and restores "\
				<< attack_damage_ << " hit points!\n";
		energy_points_ -= 1;
	}
	else
	{
		std::cout << "ScavTrap " << name_ << " attacks " << target \
				<< " causing " << attack_damage_ << " points of damage!\n";
		energy_points_ -= 1;
	}
}

void ScavTrap::guardGate()
{
	if (hit_points_ <= 0)
	{
		std::cout << "ScavTrap " << name_ << " is dead; cannot go in guard mode.\n";
	}
	else
	{
		std::cout << "ScavTrap " << name_ << " is in guard mode.\n";
	}
}