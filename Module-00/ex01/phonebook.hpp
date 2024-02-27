/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:58:31 by ykarabul          #+#    #+#             */
/*   Updated: 2023/06/26 13:58:31 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <iomanip>
# include <stdlib.h>

class contact
{
	private:
		std::string	name;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	dSecret;
		int			index;
		std::string	input(std::string message) const;
		std::string	charlimited(std::string str) const;
	public:
		void	assigment(int index);
		void	getcontactinfo(void) const;
		void	getuserinfo(void) const;
		int		getvaluechack(void) const;
};

class phoneBook
{
	private:
		contact	user[8];
	public:
		int		user_count;
		void	add(void);
		void	search(void) const;
};

#endif
