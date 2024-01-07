/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:23:33 by ykarabul          #+#    #+#             */
/*   Updated: 2023/07/26 16:23:34 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <cmath>

class Fixed {
	private:
		static const int _fractional = 8;
		int _fixed;
	public:
		Fixed();
		Fixed(const Fixed&);
		Fixed(const int);
		Fixed(const float);
		Fixed& operator=(const Fixed&);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const);
		
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream & operator<<(std::ostream &o, const Fixed &f);