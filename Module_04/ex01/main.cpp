/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 00:30:49 by ykarabul          #+#    #+#             */
/*   Updated: 2023/09/12 21:58:30 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        j->makeSound();

        delete j;
        delete i;
        const int numAnimals = 4;
        Animal* animals[numAnimals];

        for (int i = 0; i < numAnimals / 2; ++i) {
            animals[i] = new Dog();
        }
        for (int i = numAnimals / 2; i < numAnimals; ++i) {
            animals[i] = new Cat();
        }
        for (int i = 0; i < numAnimals; ++i) {
            animals[i]->makeSound();
        }
		Cat* catty = (Cat*)animals[2];
        Dog* doggy = dynamic_cast<Dog*>(animals[0]);
		std::cout << catty->getBrain()->ideas[0] << std::endl;
        std::cout << doggy->getBrain()->ideas[0] << std::endl;
        for (int i = 0; i < numAnimals; ++i) {
            delete animals[i];
        }
    }
    return 0;
}
