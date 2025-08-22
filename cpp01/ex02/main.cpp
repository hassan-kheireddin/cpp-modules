/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:51:23 by hkheired          #+#    #+#             */
/*   Updated: 2025/07/08 12:51:23 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
    std::string stringVariable = "HI THIS IS BRAIN";
    std::string* stringPTR = &stringVariable;
    std::string& stringREF = stringVariable;

    std::cout << "Memory address of the string variable: " << &stringVariable << std::endl<<std::endl;
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl << std::endl;
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl<<std::endl;
    
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl << std::endl;
    std::cout << "Value of the string variable: " << stringVariable << std::endl << std::endl;
    std::cout << "Value referred to by stringREF: " << stringREF << std::endl << std::endl;
    return 0;
}
/*
Pointers: Require explicit dereferencing (*) to access the value.
They can also be reassigned to point to different variables.

References: Act as aliases for the original variable.
They do not require dereferencing and cannot be reassigned to refer to another variable.
*/