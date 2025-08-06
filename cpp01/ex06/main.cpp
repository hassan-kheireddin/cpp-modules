/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:09:50 by hkheired          #+#    #+#             */
/*   Updated: 2025/07/08 18:09:50 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


int main(int argc, char **argv) {
    Harl harl;

    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <LOG_LEVEL>" << std::endl;
        std::cout << "Available levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
        return 1;
    }
    
    harl.filterComplain(argv[1]);

    return 0;
}