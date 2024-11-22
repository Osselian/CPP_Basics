#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal *animal = new Animal();
	const Animal *cat = new Cat();
	const Animal *dog = new Dog();
	const WrongAnimal *wrongAnimal = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();

	std::cout << "Animal: type - " << animal->getType() << ", sound";
	animal->makeSound();
	std::cout << "Cat: type - " << cat->getType() << ", sound";
	cat->makeSound();
	std::cout << "Dog: type - " << dog->getType() << ", sound";
	dog->makeSound();
	std::cout << "WrongAnimal: type - " << wrongAnimal->getType() << ", sound";
	wrongAnimal->makeSound();
	std::cout << "WrongCat: type - " << wrongCat->getType() << ", sound";
	wrongCat->makeSound();

	delete animal;
	delete cat;
	delete dog;
	delete wrongAnimal;
	delete wrongCat;
}