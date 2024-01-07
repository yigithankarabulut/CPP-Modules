/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:39:15 by ykarabul          #+#    #+#             */
/*   Updated: 2023/06/26 15:39:15 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name_tmp) : name(name_tmp)
{
    this->weapon = NULL;
}

void HumanB::setWeapon(Weapon &Weapon)
{
    this->weapon = &Weapon;
}

void HumanB::attack(void) const
{
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}
