/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 09:59:46 by ykarabul          #+#    #+#             */
/*   Updated: 2023/09/14 22:03:50 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource() {
    std::cout << "MateriaSource constructer called\n";
    for (int i = 0; i < 4; i++) {
        this->inventory[i] = 0;
    }
}

MateriaSource::MateriaSource(const MateriaSource& copy) {
    *this = copy;
}

MateriaSource &MateriaSource::operator=(const MateriaSource& copy) {
    for (int i = 0; i < 4; i++) {
        this->inventory[i] = copy.inventory[i];
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i])
            delete this->inventory[i];
    }
    std::cout << "MateriaSource destructed\n";
}

void MateriaSource::learnMateria(AMateria* m) {
	int i = 0;

	if (!m) {
		std::cout << "Tried to learn but Materia is empty\n";
		return ;
	}
	while (this->inventory[i] != NULL){
		i++;
	}
	if (i > 3) {
		std::cout << "There is no enough space for learn Materia\n";
		return ;
	}
	this->inventory[i] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++)
	{
        if (this->inventory[i]->getType() == type)
            return this->inventory[i]->clone();
    }
    return NULL;
}
