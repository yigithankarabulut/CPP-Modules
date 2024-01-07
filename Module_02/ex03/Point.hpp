/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:22:51 by ykarabul          #+#    #+#             */
/*   Updated: 2023/07/26 16:22:52 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Header-protection
#pragma once

// Includes
#include <string>
#include <iostream>
#include "Fixed.hpp"

// classes

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;

	public:
	// Constructors
		Point();
		Point(const float x, const float y);
		Point(const Point& copy);

	// Deconstructors
		~Point();

	// Overloaded Operators
		Point &operator=(const Point &src);

	// Public Methods

	// Getter
		const Fixed &getX(void)const;
		const Fixed &getY(void)const;
	// Setter

};

// Overload for ostream
std::ostream	&operator<<(std::ostream &o, Point const point);
