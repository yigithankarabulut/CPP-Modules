/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:23:27 by ykarabul          #+#    #+#             */
/*   Updated: 2023/07/26 16:36:51 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixed(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int nbr)
{
    std::cout << "Int constructor called" << std::endl;
	this->_fixed = nbr << _fractional;
}

Fixed::Fixed(const float nbr)
{
    std::cout << "Float constructor called" << std::endl;
	this->_fixed = roundf(nbr * (1 << _fractional));
}

Fixed& Fixed::operator=(const Fixed& nbr)
{
    std::cout << "Copy assigment operator called" << std::endl;
    if(this != &nbr)
		this->_fixed = nbr.getRawBits();
    return(*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return(this->_fixed);
}

void Fixed::setRawBits(int const nbr)
{
	this->_fixed = nbr;
}

float Fixed::toFloat(void) const 
{
   return((float)getRawBits() / (1 << _fractional));
}

int Fixed::toInt() const
{
    return (getRawBits() >> _fractional);
}

std::ostream & operator<<(std::ostream &o, const Fixed &f)
{
	o << f.toFloat();
	return o;
}
