/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <ykarabul@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:46:48 by ykarabul          #+#    #+#             */
/*   Updated: 2023/08/01 13:19:47 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() {
    std::cout << "AMateria constructor called\n";
}

AMateria::AMateria(std::string const & type): type(type) {
        std::cout << "AMateria constructor called\n";
}

AMateria::AMateria(const AMateria& copy): type(copy.getType()) {
    
}

// We don't use copy assigment operator
AMateria &AMateria::operator=(const AMateria& copy) {
    (void)copy;
    return *this;
}

AMateria::~AMateria() {
    std::cout << "AMateria destructor called\n";
}

std::string const & AMateria::getType() const {
    return (this->type);
}

void AMateria::use(ICharacter& target) {
	std::cout << "AMateria used on " << target.getName() << std::endl;
}
