/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:54:01 by ykarabul          #+#    #+#             */
/*   Updated: 2023/06/27 15:54:01 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug()
{
	std::cout<<"\033[1;31m -> DEBUG <-\033[0m"<<std::endl;
	std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger."<<std::endl;
	std::cout<<"I really do!"<<std::endl;
}

void Harl::info()
{
	std::cout<<"\033[1;31m -> INFO <-\033[0m"<<std::endl;
	std::cout<<"I cannot believe adding extra bacon costs more money."<<std::endl;
	std::cout<<"You didn't put enough bacon in my burger!"<<std::endl;
	std::cout<<"If you did, I wouldn't be asking for more!"<<std::endl;
}

void Harl::warning()
{
	std::cout<<"\033[1;31m -> WARNING <-\033[0m"<<std::endl;
	std::cout<<"I think I deserve to have some extra bacon for free."<<std::endl;
	std::cout<<"I’ve been coming for years whereas you started working here since last month."<<std::endl;
}

void Harl::error()
{
	std::cout<<"\033[1;31m -> ERROR <-\033[0m"<<std::endl;
	std::cout<<"This is unacceptable!"<<std::endl;
	std::cout<<"I want to speak to the manager now."<<std::endl;
}

void Harl::complain(std::string level)
{
    t_func fun[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    while (i < 4 && levels[i].compare(level))
        i++;
    if (i < 4)
        (this->*fun[i])();
}
