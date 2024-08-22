/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/27 17:01:16 by fras          #+#    #+#                 */
/*   Updated: 2024/08/22 13:58:45 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::ClapTrap(const std::string& name)
: name_(name), hit_points_(10), energy_points_(10), attack_damage_(0)
{
	std::cout << "ClapTrap constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
: name_(other.name_), hit_points_(other.hit_points_),
  energy_points_(other.energy_points_), attack_damage_(other.attack_damage_)
{

	std::cout << "ClapTrap copy constructor called\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap deconstructor called\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment operator called\n";
	if (this == &other)
		return *this;
	name_ = other.name_;
	hit_points_ = other.hit_points_;
	energy_points_ = other.energy_points_;
	attack_damage_ = other.attack_damage_;
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (!hit_points_)
	{
		std::cout << "ClapTrap " << name_ << " is dead; cannot heal or attack\n";
	}
	else if (!energy_points_)
	{
		std::cout << "ClapTrap " << name_ << " has no energy points left\n";
	}
	else if (target == name_)
	{
		std::cout << "ClapTrap " << name_ << " heals itself and restores "\
				<< attack_damage_ << " hit points! (" << hit_points_ << ")\n";
		energy_points_ -= 1;
	}
	else
	{
		std::cout << "ClapTrap " << name_ << " attacks " << target \
				<< " causing " << attack_damage_ << " points of damage!\n";
		energy_points_ -= 1;
	}	
}

void ClapTrap::attack(ClapTrap& target)
{
	if (!hit_points_)
	{
		std::cout << "ClapTrap " << name_ << " is dead; cannot heal or attack\n";
	}
	else if (!energy_points_)
	{
		std::cout << "ClapTrap " << name_ << " has no energy points left\n";
	}
	else if (this == &target)
	{
		std::cout << "ClapTrap " << name_ << " heals itself and restores "\
				<< attack_damage_ << " hit points!\n";
		beRepaired(attack_damage_);
		energy_points_ -= 1;
	}
	else
	{
		std::cout << "ClapTrap " << name_ << " attacks " << target.name_ \
				<< " causing " << attack_damage_ << " points of damage!\n";
		target.takeDamage(attack_damage_);
		energy_points_ -= 1;
	}	
}

void ClapTrap::takeDamage(unsigned int amount)
{
	hit_points_ -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	hit_points_ += amount;
}
