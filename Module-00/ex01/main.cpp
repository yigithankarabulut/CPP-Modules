/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:58:27 by ykarabul          #+#    #+#             */
/*   Updated: 2023/06/26 13:58:27 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(void)
{
	phoneBook book;
	std::string input;
	book.user_count = 0;
	do
	{
		std::cout << "available commands: ADD , SEARCH , EXIT \n";
		std::cout << "command line >> ";
		std::getline(std::cin, input);
		if(!input.compare("ADD"))
			book.add();
		if(!input.compare("SEARCH"))
			book.search();
	}while(input.compare("EXIT"));
}
