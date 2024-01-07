/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <ykarabul@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 00:31:56 by ykarabul          #+#    #+#             */
/*   Updated: 2023/07/31 22:03:15 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
    protected:
        std::string type;
    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal& copy);
        Animal &operator=(const Animal& copy);
        virtual ~Animal();
        virtual void makeSound() const;
        std::string getType() const;
        void setType(std::string);
};

#endif
