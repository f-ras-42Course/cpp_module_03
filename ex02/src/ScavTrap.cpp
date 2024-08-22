/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/28 15:00:29 by fras          #+#    #+#                 */
/*   Updated: 2024/08/22 13:57:43 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(const std::string& name)
: ClapTrap(name)
{
	std::cout << "ScavTrap constructor called\n";
	hit_points_ = 100;
	energy_points_ = 50;
	attack_damage_ = 20;
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
	if (this == &other)
		return *this;
	name_ = other.name_;
	hit_points_ = other.hit_points_;
	energy_points_ = other.energy_points_;
	attack_damage_ = other.attack_damage_;
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

void ScavTrap::attack(ScavTrap& target)
{
	if (!hit_points_)
	{
		std::cout << "ScavTrap " << name_ << " is dead; cannot heal or attack\n";
	}
	else if (!energy_points_)
	{
		std::cout << "ScavTrap " << name_ << " has no energy points left\n";
	}
	else if (this == &target)
	{
		std::cout << "ScavTrap " << name_ << " heals itself and restores "\
				<< attack_damage_ << " hit points!\n";
		beRepaired(attack_damage_);
		energy_points_ -= 1;
	}
	else
	{
		std::cout << "ScavTrap " << name_ << " attacks " << target.name_ \
				<< " causing " << attack_damage_ << " points of damage!\n";
		target.takeDamage(attack_damage_);
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