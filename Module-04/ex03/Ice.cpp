/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <ykarabul@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:56:58 by ykarabul          #+#    #+#             */
/*   Updated: 2023/08/01 11:23:45 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(): AMateria("ice")
{
    std::cout << "Ice constructor called\n";
}

Ice::Ice(const Ice& copy) : AMateria(copy)
{
    *this = copy;
}

Ice &Ice::operator=(const Ice& copy) {
    this->type = copy.getType();
    return *this;
}

std::string const &Ice::getType() const {
    return (this->type);
}

Ice::~Ice() {
    std::cout << "Ice destructor called\n";
}

Ice *Ice::clone() const {
    Ice *ret = new Ice;
    return ret;
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
