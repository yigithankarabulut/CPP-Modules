/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <ykarabul@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 00:32:03 by ykarabul          #+#    #+#             */
/*   Updated: 2023/08/01 14:28:51 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    type = "Animal";
    std::cout << "Animal constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type): type(type)
{
    std::cout << "Animal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy)
{
    *this = copy;
    std::cout << "Animal copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal& copy)
{
    this->setType(copy.getType());
    return (*this);
}

AAnimal::~AAnimal()
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string AAnimal::getType() const
{
    return (type);
}

void AAnimal::setType(std::string type)
{
    this->type = type;
}

void AAnimal::makeSound() const
{
    std::cout << "regular animal sound" << std::endl;
}
