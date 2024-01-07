/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 06:57:22 by ykarabul          #+#    #+#             */
/*   Updated: 2023/07/31 06:57:22 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{

}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
    std::cout << "FragTrap Constructor Called!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
	std::cout << "FragTrap Copy Constructor Called!" << std::endl;
    *this = copy;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap Destructor Called!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap& copy)
{
    this->setName(copy.getName());
    this->setHitPoints(copy.getHitPoints());
    this->setEnergyPoints(copy.getEnergyPoints());
    this->setAttackDamage(copy.getAttackDamage());
	std::cout << "FragTrap Copy Assigment Operator Called!" << std::endl;
    return *this;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->getName() << " want's to high five" << std::endl;
}
