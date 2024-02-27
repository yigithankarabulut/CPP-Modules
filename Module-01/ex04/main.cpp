/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:36:59 by ykarabul          #+#    #+#             */
/*   Updated: 2023/06/26 16:36:59 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.hpp"

int main(int ac, char **av)
{
    if (ac == 4)
    {
        file file_tmp(av);
        file_tmp.file_copy();
    }
    else
        std::cout << "Used: <filename> <to_file> <replace>" << std::endl;
    return 0;
}
