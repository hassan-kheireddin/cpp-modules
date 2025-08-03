/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:27:21 by hkheired          #+#    #+#             */
/*   Updated: 2025/07/08 12:27:21 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0) {}

void PhoneBook::addContact() {
    int index = contactCount % 8;
    std::cout << "\nAdding contact at slot " << index << std::endl;
    if (contacts[index].checkContact()) {
        std::cout << "Contact added successfully!\n";
        contactCount++;
    }
}

static std::string formatField(const std::string& str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return std::string(10 - str.length(), ' ') + str;
}

void PhoneBook::searchContacts() const {
    std::cout << "\n|     Index|First Name| Last Name|  Nickname|\n";
    std::cout << "-------------------------------------------\n";
    for (int i = 0; i < 8 && i < contactCount; ++i) {
        std::cout << "|" << std::setw(10) << i << "|"
                  << formatField(contacts[i].getFirstName()) << "|"
                  << formatField(contacts[i].getLastName()) << "|"
                  << formatField(contacts[i].getNickname()) << "|" << std::endl;
    }

    std::cout << "\nEnter index to view details: ";
    int index;
    if (!(std::cin >> index) || std::cin.peek() != '\n' || index < 0 || index >= contactCount || index >= 8) {
        std::cout << "Invalid index.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    contacts[index].detailedContact();

}

void PhoneBook::run() {
    std::string command;
    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        if (std::cin.eof())
            break;

        if (command == "ADD") {
            addContact();
        } else if (command == "SEARCH") {
            searchContacts();
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command. Try again.\n";
        }
    }
}
