/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:17:51 by ykarabul          #+#    #+#             */
/*   Updated: 2023/07/26 16:17:57 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>
#include  <string>

class Fixed {
	private:
		static const int _fractional = 8;
		int _fixed;
	public:
		Fixed();
		Fixed(const Fixed&);
		Fixed(const int);
		Fixed(const float);
		~Fixed();

        //comparison operators
        bool operator>(const Fixed&)	const;
        bool operator<(const Fixed&)	const;
        bool operator>=(const Fixed&)	const;
        bool operator<=(const Fixed&)	const;
        bool operator==(const Fixed&)	const;
        bool operator!=(const Fixed&)	const;
		
        //arithmetic operators
        Fixed operator+(const Fixed&)	const;
        Fixed operator-(const Fixed&)	const;
        Fixed operator*(const Fixed&)	const;
        Fixed operator/(const Fixed&)	const;

        //assignment operator
        Fixed& operator=(const Fixed&);

        //++ --
        Fixed &operator++(void);
        Fixed operator++(int);
        Fixed &operator--(void);
        Fixed operator--(int);

        //min max
        static Fixed& min(Fixed &a, Fixed &b);
    	static Fixed& max(Fixed &a, Fixed &b);

		const static Fixed& min(const Fixed &a, const Fixed &b);
		const static Fixed& max(const Fixed &a, const Fixed &b);

		int getRawBits(void) const;
		void setRawBits(int const);
		
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream & operator<<(std::ostream &o, const Fixed &f);