/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:39:16 by ykarabul          #+#    #+#             */
/*   Updated: 2023/06/26 15:39:16 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB
{
    private:
        Weapon* weapon;
        std::string name;
    public:
        HumanB(std::string name_tmp);
        void setWeapon(Weapon& weapon);
        void attack(void) const;
};
