/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:36:58 by ykarabul          #+#    #+#             */
/*   Updated: 2023/06/26 15:36:58 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name_tmp, Weapon &weapon) : name(name_tmp), weapon(weapon)
{
}

void HumanA::attack(void) const
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
