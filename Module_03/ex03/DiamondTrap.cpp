/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 07:11:58 by ykarabul          #+#    #+#             */
/*   Updated: 2023/07/31 07:11:58 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap()
{
    std::cout << "DiamondTrap Default Constructor Called!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
    this->name = name;
    this->ClapTrap::setName(name + "_clap_name");

    FragTrap::setHitPoints(100);
    ScavTrap::setEnergyPoints(50);
    FragTrap::setAttackDamage(30);
    
    std::cout << "DiamondTrap Constructor Called!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	std::cout << "DiamondTrap Copy Constructor Called!" << std::endl;
    *this = copy;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap Destructor Called!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& copy)
{
	this->name = copy.name;
    this->setName(copy.getName());
    this->setHitPoints(copy.getHitPoints());
    this->setEnergyPoints(copy.getEnergyPoints());
    this->setAttackDamage(copy.getAttackDamage());
	std::cout << "DiamondTrap Copy Assigment Operator Called!" << std::endl;
    return *this;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "DiamondTrap " << this->name << " also know as " << ClapTrap::getName() << std::endl;
}
