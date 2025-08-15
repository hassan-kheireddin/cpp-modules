/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:10:28 by hkheired          #+#    #+#             */
/*   Updated: 2025/08/05 11:10:28 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("Default"), isSigned(false), signGrade(150), execGrade(150), target("Default") {}

AForm::AForm(const std::string& name, int signGrade, int execGrade, const std::string& target) : 
    name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade), target(target) {
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : 
    name(other.name), isSigned(other.isSigned), 
    signGrade(other.signGrade), execGrade(other.execGrade), target(other.target) {}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        isSigned = other.isSigned;
    }
    return *this;
}

const std::string& AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return isSigned; }
int AForm::getSignGrade() const { return signGrade; }
int AForm::getExecGrade() const { return execGrade; }
const std::string& AForm::getTarget() const { return target; }

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > signGrade)
        throw GradeTooLowException();
    isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const {
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > execGrade)
        throw GradeTooLowException();
    executeAction();
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Form grade is too high (must be >= 1)";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Form grade is too low (must be <= 150)";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form " << form.getName() 
       << " (Sign grade: " << form.getSignGrade() 
       << ", Exec grade: " << form.getExecGrade() << ") "
       << (form.getIsSigned() ? "[SIGNED]" : "[UNSIGNED]");
    return os;
}