/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 05:07:17 by ykarabul          #+#    #+#             */
/*   Updated: 2023/07/31 05:07:17 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{

}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    std::cout << "ScavTrap Constructor Called!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
    *this = copy;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap Destructor Called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
    this->setName(copy.getName());
    this->setHitPoints(copy.getHitPoints());
    this->setEnergyPoints(copy.getEnergyPoints());
    this->setAttackDamage(copy.getAttackDamage());
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->getHitPoints() <= 0)
        return ;
    if (this->getEnergyPoints() <= 0)
    {
        std::cout << "ScavTrap " << this->getName() <<  " does not have any energy points to attack" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
    this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << this->getName() << " is now Gate Keeper Mode!" << std::endl;
}
