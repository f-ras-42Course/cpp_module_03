/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/29 17:24:51 by fras          #+#    #+#                 */
/*   Updated: 2024/05/29 17:28:30 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name)
: ClapTrap(name)
{
	std::cout << "FragTrap constructor called\n";
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
	if (this != &other)
		name_ = other.name_;
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

void FragTrap::highFiveGuys()
{
	std::cout << "FragTrap high five!\n";
}