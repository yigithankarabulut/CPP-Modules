/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:28:16 by ykarabul          #+#    #+#             */
/*   Updated: 2023/06/26 14:28:16 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
# define N 5

int main()
{
    Zombie *zombi = zombieHorde(N, "zombi");
    for (int i = 0; i < N; i++)
    {
        zombi[i].announce();
    }
    delete []zombi;
    return 0;
}