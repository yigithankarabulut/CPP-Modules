/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 00:32:03 by ykarabul          #+#    #+#             */
/*   Updated: 2023/09/12 21:33:39 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() 
{
    type = "Animal";
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string type): type(type)
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& copy)
{
    *this = copy;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal& copy)
{
    this->type = copy.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return (type);
}

void Animal::setType(std::string type)
{
    this->type = type;
}

void Animal::makeSound() const
{
    std::cout << "regular animal sound" << std::endl;
}
