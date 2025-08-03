/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:26:58 by hkheired          #+#    #+#             */
/*   Updated: 2025/07/08 12:26:58 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for (int i = 1; i < argc; i++)
    {
        int length = std::strlen(argv[i]);
        for(int j = 0; j < length; j++)
        {
            argv[i][j] = std::toupper(argv[i][j]);
            std::cout << argv[i][j];
        }
        std::cout << " ";
    }
    std::cout << std::endl;
    return 0;
}