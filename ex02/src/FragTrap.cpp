/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/29 17:24:51 by fras          #+#    #+#                 */
/*   Updated: 2024/05/30 15:21:53 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

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
	if (hit_points_ <= 0)
	{
		std::cout << "FragTrap " << name_ << " is dead; cannot give a high five.\n";
	}
	else
	{
		std::cout << "FragTrap " << name_ << " gives a high five!\n";
	}
}