/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <ykarabul@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 01:06:56 by ykarabul          #+#    #+#             */
/*   Updated: 2023/07/31 22:56:59 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog constructor called" << std::endl;
    Animal::setType("Dog");
    this->brain = new Brain();
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = copy;
}

Dog &Dog::operator=(const Dog& copy)
{
    Animal::setType(copy.getType());
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
    delete brain;
    std::cout << "Dog destructor called" << std::endl;
}
