/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/29 17:24:51 by fras          #+#    #+#                 */
/*   Updated: 2024/08/22 13:58:28 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(const std::string& name)
: ClapTrap(name)
{
	std::cout << "FragTrap constructor called\n";
	hit_points_ = 100;
	energy_points_ = 100;
	attack_damage_ = 30;
}

FragTrap::FragTrap(const FragTrap& other)
: ClapTrap(other)
{

	std::cout << "FragTrap copy constructor called\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap deconstructor called\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap copy assignment operator called\n";
	if (this == &other)
		return *this;
	name_ = other.name_;
	hit_points_ = other.hit_points_;
	energy_points_ = other.energy_points_;
	attack_damage_ = other.attack_damage_;
	return *this;
}

void FragTrap::attack(const std::string& target)
{
	if (hit_points_ <= 0)
	{
		std::cout << "FragTrap " << name_ << " is dead; cannot heal or attack\n";
	}
	else if (!energy_points_)
	{
		std::cout << "FragTrap " << name_ << " has no energy points left\n";
	}
	else if (target == name_)
	{
		std::cout << "FragTrap " << name_ << " heals itself and restores "\
				<< attack_damage_ << " hit points!\n";
		energy_points_ -= 1;
	}
	else
	{
		std::cout << "FragTrap " << name_ << " attacks " << target \
				<< " causing " << attack_damage_ << " points of damage!\n";
		energy_points_ -= 1;
	}
}


void FragTrap::attack(FragTrap& target)
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


void FragTrap::highFiveGuys()
{
	if (hit_points_ <= 0)
	{
		std::cout << "FragTrap " << name_ << " is dead; cannot give a high five.\n";
	}
	else
	{
		std::cout << "FragTrap " << name_ << " gives a high five!\n";
	}
}