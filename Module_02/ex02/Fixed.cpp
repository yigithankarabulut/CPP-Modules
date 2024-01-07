/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:18:18 by ykarabul          #+#    #+#             */
/*   Updated: 2023/07/26 16:51:41 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed() : _fixed(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy): _fixed(copy.getRawBits())
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int nbr) : _fixed(nbr << _fractional) 
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float nbr) : _fixed(roundf(nbr * (1 << _fractional)))
{
	std::cout << "Float constructor called" << std::endl;
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


bool	Fixed::operator>(const Fixed &n) const
{
	return(this->_fixed > n.getRawBits());
}

bool Fixed::operator<(const Fixed &n) const
{
	return(this->_fixed < n.getRawBits());
}

bool Fixed::operator>=(const Fixed &n) const
{
	return(this->_fixed >= n.getRawBits());
}

bool Fixed::operator<=(const Fixed &n) const
{
	return(this->_fixed <= n.getRawBits());
}

bool Fixed::operator==(const Fixed& n) const
{
	return(this->_fixed == n.getRawBits());
}

bool Fixed::operator!=(const Fixed& n) const
{
	return(this->_fixed != n.getRawBits());
}

Fixed Fixed::operator+(const Fixed& n) const
{
	return(Fixed(this->toFloat() + n.toFloat()));
}

Fixed Fixed::operator-(const Fixed& n) const
{
	return(Fixed(this->toFloat() - n.toFloat()));
}

Fixed Fixed::operator*(const Fixed& n) const
{
	return(Fixed(this->toFloat() * n.toFloat()));
}

Fixed Fixed::operator/(const Fixed& n) const
{
	return(Fixed(this->toFloat() / n.toFloat()));
}


Fixed &Fixed::operator++(void) // before than operator
{
	this->_fixed++;
	return(*this);
}

Fixed Fixed::operator++(int) // after than operator
{
	Fixed a(this->toFloat());
	this->_fixed++;
	return(a);
}

Fixed &Fixed::operator--(void) // before than operator
{
	this->_fixed--;
	return(*this);
}

Fixed Fixed::operator--(int) // after than operator
{
	Fixed a(this->toFloat());
	this->_fixed--;
	return(a);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() >= b.getRawBits())
		return a;
	return b;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() >= b.getRawBits())
		return a;
	return b;
}

std::ostream & operator<<(std::ostream &o, const Fixed &f)
{
	o << f.toFloat();
	return o;
}
