/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:17:19 by hkheired          #+#    #+#             */
/*   Updated: 2025/08/05 11:17:19 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat john("John", 5);

        // Test ShrubberyCreationForm
        ShrubberyCreationForm shrubbery("home");
        john.signForm(shrubbery);
        john.executeForm(shrubbery);

        // Test RobotomyRequestForm
        RobotomyRequestForm robotomy("Bender");
        john.signForm(robotomy);
        john.executeForm(robotomy);

        // Test PresidentialPardonForm
        PresidentialPardonForm pardon("Arthur Dent");
        john.signForm(pardon);
        john.executeForm(pardon);
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}