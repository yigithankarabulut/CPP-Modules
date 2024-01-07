/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:58:26 by ykarabul          #+#    #+#             */
/*   Updated: 2023/06/26 13:58:26 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

std::string contact::input(std::string message) const
{
	std::string	enteredInput;
	do
	{
		std::cout << message;
		std::getline(std::cin, enteredInput);
		if(enteredInput.empty())
		{
			std::cout << "You can't go next if empty imput sir!\n";
			continue;
		}
	}while(enteredInput.empty());
	return (enteredInput);
}

std::string contact::charlimited(std::string str) const
{
	if(str.length() > 10)
		return(str.substr(0,9) + ".");
	return(str);
}

void contact::assigment(int index)
{
	this->name = this->input("Enter First Name: ");
	this->lastName = this->input("Enter Last Name: ");
	this->nickName = this->input("Enter Nickname: ");
	this->phoneNumber = this->input("Enter Phone Number: ");
	this->dSecret = this->input("Enter Darkest Secret: ");
	this->index = index;
}

int contact::getvaluechack(void) const
{
	if(this->name.empty())
		return 1;
	else
		return 0;
}

void contact::getcontactinfo(void) const
{
	if(this->name.empty())
		return;
	std::cout << "|" << std::setw(10) << this->index;
	std::cout << "|" << std::setw(10) << this->charlimited(this->name);
	std::cout << "|" << std::setw(10) << this->charlimited(this->lastName);
	std::cout << "|" << std::setw(10) << this->charlimited(this->nickName);
	std::cout << "|\n";
}

void contact::getuserinfo(void) const
{
	if (this->name.empty())
	{
		std::cout << "No user is registered. :) \n";
		return;
	}
	std::cout << "User[" << index << "] First Name: " << this->name << std::endl;
	std::cout << "User[" << index << "] Last Name: " << this->lastName << std::endl;
	std::cout << "User[" << index << "] Nickname: " << this->nickName << std::endl;
	std::cout << "User[" << index << "] Phone Number: " << this->phoneNumber << std::endl;
	std::cout << "User[" << index << "] Darkest Secret: " << this->dSecret << std::endl;
}