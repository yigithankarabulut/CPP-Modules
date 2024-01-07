/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:58:11 by ykarabul          #+#    #+#             */
/*   Updated: 2023/06/26 13:58:11 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    if (ac != 1)
    {
        int i = 0;
        int j = 1;

        while (av[j])
        {
            i = 0;
            while (av[j][i])
            {
                std::cout << (char)std::toupper(av[j][i]);
                i++;
            }
            j++;
        }
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
    return (0);
}
