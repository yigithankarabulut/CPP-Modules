/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:19:42 by ykarabul          #+#    #+#             */
/*   Updated: 2023/07/10 19:19:42 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// --Constuctor--
ClapTrap::ClapTrap(void) : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "Default ClapTrap Destructor Called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " Constructor Called!" << std::endl;
}


ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = copy;
}

// --Destructor--
ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap Destructor Called!" << std::endl;
}

// --Operator Overloading--
ClapTrap&   ClapTrap::operator=(const ClapTrap& copy)
{
    this->name = copy.getName();
    this->hitPoints = copy.getHitPoints();
    this->energyPoints = copy.getEnergyPoints();
    this->attackDamage = copy.attackDamage;
    return (*this);
}

// --Getter--
std::string ClapTrap::getName(void) const
{
    return this->name;
}

int ClapTrap::getHitPoints(void) const
{
    return this->hitPoints;
}

int ClapTrap::getEnergyPoints(void) const
{
    return this->energyPoints;
}

int ClapTrap::getAttackDamage(void) const
{
    return this->attackDamage;
}

// --Setter--
void ClapTrap::setHitPoints(int amount)
{
    this->hitPoints = amount;
}

void ClapTrap::setEnergyPoints(int amount)
{
    this->energyPoints = amount;
}

void ClapTrap::setAttackDamage(int amount)
{
    this->attackDamage = amount;
}


// --Public Methods--

void ClapTrap::attack(const std::string &target)
{
    if (this->hitPoints <= 0)
        return ;
    if (this->energyPoints <= 0)
    {
        std::cout << "ClapTrap " << this->getName() << " does not have any energy points to attack" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
    this->energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints <= 0)
        return ;
    if (this->hitPoints <= (int)amount) {
        std::cout << "ClapTrap " << this->getName() << " is died\n";
        this->hitPoints -= amount;
        return ;
    }
    std::cout << "ClapTrap " << this->getName() << " has take " << amount << " point of damage\n";
    this->hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->hitPoints <= 0)
        return ;
    if (this->energyPoints <= 0) {
        std::cout << "ClapTrap " << this->getName() << " does not have any energy points to repair itself\n";
        return ;
    }
    std::cout << "ClapTrap " << this->getName() << " has repaired " << amount << " point of itself\n";
    this->energyPoints--;
    this->hitPoints += amount;
}
