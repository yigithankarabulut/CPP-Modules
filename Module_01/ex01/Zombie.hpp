/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:26:17 by ykarabul          #+#    #+#             */
/*   Updated: 2023/06/26 14:26:17 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie
{
    private:
        std::string name;
    public:
        ~Zombie();
        void setname(std::string name);
        void announce(void);
};


Zombie* zombieHorde(int N, std::string name);

#endif
