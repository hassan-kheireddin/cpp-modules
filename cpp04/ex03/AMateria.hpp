/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Am.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 20:11:06 by hkheired          #+#    #+#             */
/*   Updated: 2025/07/15 20:11:06 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class AMateria {
protected:
    std::string type;

public:
    // Orthodox Canonical Form
    AMateria(std::string const& type);
    AMateria(const AMateria& other);
    AMateria& operator=(const AMateria& other);
    virtual ~AMateria();

    // Getter for type
    std::string const& getType() const;

    // Pure virtual functions
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target) = 0;
};

#endif