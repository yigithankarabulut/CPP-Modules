/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:56:54 by ykarabul          #+#    #+#             */
/*   Updated: 2023/09/14 22:05:25 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria {
    public:
        Cure();
        Cure(const Cure& copy);
        Cure &operator=(const Cure& copy);
        std::string const & getType() const;
        Cure *clone() const;
        void use(ICharacter& target);
        ~Cure();
};

#endif