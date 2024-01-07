/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <ykarabul@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 02:05:24 by ykarabul          #+#    #+#             */
/*   Updated: 2023/07/31 21:43:23 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Brain
{
    public:
        std::string ideas[100];
        Brain();
        Brain(const Brain& b);
        Brain &operator=(const Brain& b);
        virtual ~Brain();
};
