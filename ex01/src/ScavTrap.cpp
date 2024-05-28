/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/28 15:00:29 by fras          #+#    #+#                 */
/*   Updated: 2024/05/28 15:03:24 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name)
: name_(name), hit_points_(10), energy_points_(10), attack_damage_(0)
{
	std::cout << "Constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& other)
: name_(other.name_), hit_points_(other.hit_points_),
  energy_points_(other.energy_points_), attack_damage_(other.attack_damage_)
{

	std::cout << "Copy constructor called\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "Deconstructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "Copy assignment operator called\n";
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

void ScavTrap::takeDamage(unsigned int amount)
{
	hit_points_ -= amount;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	hit_points_ += amount;
}
