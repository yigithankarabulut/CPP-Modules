/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:36:57 by ykarabul          #+#    #+#             */
/*   Updated: 2023/06/26 16:36:57 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.hpp"

file::file(char **av) : file_name(av[1]), file_search_word(av[2]), file_replace_word(av[3])
{
    this->read.open(this->file_name.c_str());
    if(!this->read.is_open())
    {
        std::cerr << this->file_name << " file does not open" << std::endl;
        return;
    }
    this->write.open((this->file_name + ".replace").c_str());
    if(!this->write.is_open())
    {
        std::cerr << this->file_name << " file does not open or not create" << std::endl;
        return;
    }
}

void file::file_copy(void)
{
	while (std::getline(this->read, this->readline))
    {
        this->file_replace();
        this->write << std::endl;
    }
}

void file::file_replace(void)
{
    int i = 0;
    int len_search_word = this->file_search_word.length();
    while (this->readline[i])
    {
        if(!this->readline.compare(i, len_search_word, this->file_search_word))
        {
            this->write << this->file_replace_word;
            i += len_search_word;
        }
        else
        {
            this->write << this->readline[i];
            i++;
        }
    }
}
