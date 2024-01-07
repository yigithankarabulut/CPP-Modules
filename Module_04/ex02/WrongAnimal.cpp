/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <ykarabul@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 01:44:28 by ykarabul          #+#    #+#             */
/*   Updated: 2023/07/31 01:56:57 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    type = "WrongAnimal";
    std::cout << "WrongAnimal constructor called\n";
}

WrongAnimal::WrongAnimal(std::string type): type(type) {
    std::cout << "WrongAnimal constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) {
    *this = copy;
    std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& copy) {
    this->type = copy.type;
    return (*this);
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called\n";
}

std::string WrongAnimal::getType() const {
    return (type);
}

void WrongAnimal::setType(std::string type) {
    this->type = type;
}

void WrongAnimal::makeSound() const {
    std::cout << "regular WrongAnimal sound\n";
}
