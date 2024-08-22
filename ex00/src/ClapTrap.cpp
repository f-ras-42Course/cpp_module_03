/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/27 17:01:16 by fras          #+#    #+#                 */
/*   Updated: 2024/08/22 13:52:41 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called\n";
}

ClapTrap::ClapTrap(const std::string& name)
: name_(name), hit_points_(10), energy_points_(10), attack_damage_(0)
{
	std::cout << "Constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
: name_(other.name_), hit_points_(other.hit_points_),
  energy_points_(other.energy_points_), attack_damage_(other.attack_damage_)
{

	std::cout << "Copy constructor called\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "Deconstructor called\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy assignment operator called\n";
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
	if (!energy_points_)
	{
		std::cout << "ClapTrap " << name_ << " has no energy points left\n";
		return ;
	}
	if (target == name_)
	{
		std::cout << "ClapTrap " << name_ << " heals itself and restores "\
				<< attack_damage_ << " hit points\n";
	}
	else
	{
		std::cout << "ClapTrap " << name_ << " attacks " << target \
				<< " causing " << attack_damage_ << " points of damage!\n";
	}
	energy_points_ -= 1;
}

void ClapTrap::attack(const ClapTrap& target)
{
	if (!energy_points_)
	{
		std::cout << "ClapTrap " << name_ << " has no energy points left\n";
		return ;
	}
	if (&target == this)
	{
		std::cout << "ClapTrap " << name_ << " heals itself and restores "\
				<< attack_damage_ << " hit points\n";
		beRepaired(attack_damage_);
	}
	else
	{
		std::cout << "ClapTrap " << name_ << " attacks " << target.name_ \
				<< " causing " << attack_damage_ << " points of damage!\n";
		takeDamage(attack_damage_);
	}
	energy_points_ -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	hit_points_ -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	hit_points_ += amount;
}
