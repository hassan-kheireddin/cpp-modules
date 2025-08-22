/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:35:54 by hkheired          #+#    #+#             */
/*   Updated: 2025/08/13 15:35:54 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void testAnimalSound(const Animal& animal) {
    std::cout << "Type: " << animal.getType() << std::endl;
    animal.makeSound();
}

void testWrongAnimalSound(const WrongAnimal& animal) {
    std::cout << "Type: " << animal.getType() << std::endl;
    animal.makeSound();
}

int main() {
    std::cout <<"===== ANIMAL TESTS =====" <<std::endl << std::endl;
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();

        delete meta;
        delete j;
        delete i;
    }

    
    std::cout << "\n===== WRONG ANIMAL TESTS =====" << std::endl << std::endl;
    {
        WrongAnimal wrongAnimal;
        WrongCat wrongCat;
        
        testWrongAnimalSound(wrongAnimal);
        testWrongAnimalSound(wrongCat);
    }

    std::cout << "\n===== POLYMORPHISM TESTS =====" << std::endl << std::endl;
    {
        Animal* animals[4];
        
        animals[0] = new Animal();
        animals[1] = new Dog();
        animals[2] = new Cat();
        animals[3] = new Dog();
        
        for (int i = 0; i < 4; i++) {
            testAnimalSound(*animals[i]);
            delete animals[i];
        }
    }

    std::cout << "\n===== WRONG POLYMORPHISM TESTS =====" << std::endl << std::endl;
    {
        WrongAnimal* wrongAnimals[2];
        
        wrongAnimals[0] = new WrongAnimal();
        wrongAnimals[1] = new WrongCat();
        
        for (int i = 0; i < 2; i++) {
            testWrongAnimalSound(*wrongAnimals[i]);
            delete wrongAnimals[i];
        }
    }
    
    return 0;
}