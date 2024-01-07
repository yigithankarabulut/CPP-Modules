/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 00:30:49 by ykarabul          #+#    #+#             */
/*   Updated: 2023/09/14 21:17:20 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
    {
        // const Animal* meta = new Animal(); error: allocating an object of abstract class type 'Animal'
        const AAnimal* j = new Dog();
        const AAnimal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        j->makeSound();

        delete j;
        delete i;
        const int numAnimals = 4;
        AAnimal* animals[numAnimals];
        for (int i = 0; i < numAnimals / 2; ++i)
        {
            animals[i] = new Dog();
        }
        for (int i = numAnimals / 2; i < numAnimals; ++i)
        {
            animals[i] = new Cat();
        }
        for (int i = 0; i < numAnimals; ++i)
        {
            animals[i]->makeSound();
        }
        Dog* doggy = dynamic_cast<Dog*>(animals[0]);
        Cat* catty = dynamic_cast<Cat*>(animals[2]);
        std::cout << doggy->getBrain()->ideas[0] << std::endl;
        std::cout << catty->getBrain()->ideas[0] << std::endl;
        for (int i = 0; i < numAnimals; ++i)
        {
            delete animals[i];
        }
    }
    return 0;
}
