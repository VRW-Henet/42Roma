/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:12:29 by dpadrini          #+#    #+#             */
/*   Updated: 2023/06/26 15:12:32 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    int i;
    int c;

    c = 1;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }
    else
    {
        while (c < argc)
        {
            i = 0;
            while (argv[c][i])
            {
                std::cout << char(toupper(argv[c][i]));
                i++;
            }
            if (c != argc - 1)
                std::cout << " ";
            c++;
        }
    }
    std::cout << std::endl;
    return (0);
}