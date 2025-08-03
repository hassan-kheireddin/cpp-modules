/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:27:11 by hkheired          #+#    #+#             */
/*   Updated: 2025/07/08 12:27:11 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"


Contact::Contact() {};

bool Contact::checkName(const std::string& name) const
{
    if (name.empty()) {
        std::cout << "Field cannot be empty. Please try again." << std::endl;
        return false;
    }
    int length = std::strlen(name.c_str());
    for (int i = 0; i < length; ++i) {
        if (!std::isalpha(name[i]) && name[i] != ' ' && name[i] != '-') {
            std::cout << "Invalid character in name. Only letters, spaces, and hyphens are allowed." << std::endl;
            return false;
        }
    }
    return true;
}

bool Contact::checkPhoneNumber(const std::string& phone) const
{
    if (phone.empty()) {
        std::cout << "Field cannot be empty. Please try again." << std::endl;
        return false;
    }
    if (phone[0] != '+' && !std::isdigit(phone[0]))
    {
        std::cout << "Invalid character in phone number. Only digits and '+' at beginning are allowed." << std::endl;
        return false;
    }
    int length = std::strlen(phone.c_str());
    for (int i = 1; i < length; ++i) {
        if (!std::isdigit(phone[i])) {
            std::cout << "Invalid character in phone number. Only digits and '+' at beginning are allowed." << std::endl;
            return false;
        }
    }
    return true;
}
bool Contact::checkContact()
{
    std::cout << "Enter First Name: ";
    std::getline(std::cin, firstName);
    if (!checkName(firstName)) return false;

    std::cout << "Enter Last Name: ";
    std::getline(std::cin, lastName);
    if (!checkName(lastName)) return false;

    std::cout << "Enter Nickname: ";
    std::getline(std::cin, nickname);
    if (nickname.empty()) return false;

    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, phoneNumber);
    if (!checkPhoneNumber(phoneNumber)) return false;

    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, darkestSecret);
    if (darkestSecret.empty()) return false;

    return true;
}

void Contact::detailedContact() const {
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getDarkestSecret() const { return darkestSecret; }