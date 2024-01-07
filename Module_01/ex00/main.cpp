/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:58:51 by ykarabul          #+#    #+#             */
/*   Updated: 2023/06/26 13:58:51 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    std::string name;
    std::cout << "Creating zombie on the stack." << std::endl;
    std::cout << "Zombie Name: ";
    std::cin >> name;

    Zombie zombi1(name);

    std::cout << "Creating zombie on the heap." << std::endl;
    std::cout << "Zombie Name: ";
    std::cin >> name;

    Zombie *zombi2 = newZombie(name);
    zombi2->announce();
    delete(zombi2);

    std::cout << "Calling randomChump()." << std::endl;
    std::cout << "Zombie Name: ";
    std::cin >> name;
    randomChump(name);
    return 0;
}
