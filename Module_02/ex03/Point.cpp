/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:18:47 by ykarabul          #+#    #+#             */
/*   Updated: 2023/07/26 16:18:57 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Constructors
Point::Point(): _x(0), _y(0)
{
	// std::cout << "Point Default Constructor called" << std::endl;
}

Point::Point(const float x, const float y):_x(x), _y(y)
{
	// std::cout << "Constuctor called" << std::endl;
}

Point::Point(const Point &copy): _x(copy.getX()), _y(copy.getY())
{
	// std::cout << "Point Copy Constructor called" << std::endl;
	// *this = copy;
}

// Deconstructors
Point::~Point()
{
	// std::cout << "Point Deconstructor called" << std::endl;
}

// Overloaded Operators
Point &Point::operator=(const Point &src)
{
	// std::cout << "Point Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

// Public Methods

// Getter
const Fixed	&Point::getX(void)const
{
	return (this->_x);
}

const Fixed	&Point::getY(void)const
{
	return (this->_y);
}

// Setter


// Overload for ostream
std::ostream	&operator<<(std::ostream &o, Point const point)
{
	o << "_x: " << point.getX() << " / _y: " << point.getY() << std::endl;
	return (o);
}
