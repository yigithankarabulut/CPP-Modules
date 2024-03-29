/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <ykarabul@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 01:44:31 by ykarabul          #+#    #+#             */
/*   Updated: 2023/07/31 01:58:12 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "WrongCat constructor called\n";
    WrongAnimal::type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy)
{
    std::cout << "WrongCat copy constructor called\n";
    *this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat& copy)
{
    WrongAnimal::type = copy.type;
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << "meow meow\n";
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called\n";
}
