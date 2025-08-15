/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:13:57 by hkheired          #+#    #+#             */
/*   Updated: 2025/08/05 11:13:57 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : 
    AForm("Robotomy Request", 72, 45, target) {
    std::srand(std::time(0));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : 
    AForm(other) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    AForm::operator=(other);
    return *this;
}

void RobotomyRequestForm::executeAction() const {
    //Without seeding, std::rand() would produce the same sequence of numbers every time the program 
    //is executed, which would make the robotomy outcome predictable and unrealistic.
    std::srand(std::time(0)); 
    std::cout << "* Drilling noises *" << std::endl;
    if (std::rand() % 2) {
        std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy on " << getTarget() << " failed." << std::endl;
    }
}