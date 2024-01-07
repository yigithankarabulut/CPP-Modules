/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:09:50 by ykarabul          #+#    #+#             */
/*   Updated: 2023/06/26 15:09:50 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->setType(type);
}

void Weapon::setType(std::string newType)
{
    this->type = newType;
}

const std::string &Weapon::getType(void)
{
    return this->type;
}
