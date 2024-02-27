/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:36:58 by ykarabul          #+#    #+#             */
/*   Updated: 2023/06/26 16:36:58 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

class file
{
    private:
        std::ifstream read;
        std::ofstream write;
        std::string readline;
        std::string file_name;
        std::string file_search_word;
        std::string file_replace_word;
    public:
        file(char **av);
        void file_replace(void);
        void file_copy(void);
};
