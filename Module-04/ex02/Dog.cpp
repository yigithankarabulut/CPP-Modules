/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <ykarabul@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 01:06:56 by ykarabul          #+#    #+#             */
/*   Updated: 2023/08/01 14:30:16 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): AAnimal()
{
    std::cout << "Dog constructor called" << std::endl;
    AAnimal::setType("Dog");
    this->brain = new Brain();
}

Dog::Dog(const Dog& copy) : AAnimal(copy)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = copy;
}

Dog &Dog::operator=(const Dog& copy)
{
    AAnimal::setType(copy.getType());
    this->brain = copy.brain;
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "woof woof" << std::endl;
}

Brain *Dog::getBrain() const
{
    return this->brain;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}
