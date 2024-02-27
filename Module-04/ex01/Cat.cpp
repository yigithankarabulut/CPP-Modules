/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <ykarabul@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 01:27:16 by ykarabul          #+#    #+#             */
/*   Updated: 2023/07/31 22:57:10 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat constructor called" << std::endl;
    Animal::setType("Cat");
    this->brain = new Brain();
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = copy;
}

Cat &Cat::operator=(const Cat& copy)
{
    Animal::setType(copy.getType());
    this->brain = copy.brain;
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "meow meow" << std::endl;
}

Brain *Cat::getBrain() const
{
    return brain;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}
