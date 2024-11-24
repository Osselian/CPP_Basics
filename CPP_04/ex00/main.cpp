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
	std::cout << std::endl;

	std::cout << "COMMON TEST:\n";
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
	std::cout << std::endl;

	{
		std::cout << "TEST1:\n";
		Animal kitty;
		Animal pups;

		kitty = pups;
		std::cout << "Kitty: type - " << kitty.getType() << ", sound";
		kitty.makeSound();
	}
	std::cout << std::endl;
	{
		std::cout << "\nTEST2:\n";
		Animal kitty = *new Cat();
		Animal pups = *new Dog();

		kitty = pups;
		std::cout << "Kitty: type - " << kitty.getType() << ", sound";
		kitty.makeSound();
	}
	std::cout << std::endl;
	{
		std::cout << "\nTEST3:\n";
		Animal *kitty = new Cat();
		Animal *pups = new Dog();

		*kitty = *pups;
		std::cout << "Kitty: type - " << kitty->getType() << ", sound";
		kitty->makeSound();
	}

	std::cout << std::endl << "MAIN SCOPE DESTRUCTION:\nAnimal:\n";
	delete animal;
	std::cout << std::endl << "Cat:\n";
	delete cat;
	std::cout << std::endl << "Dog:\n";
	delete dog;
	std::cout << std::endl << "WrongAnimal:\n";
	delete wrongAnimal;
	std::cout << std::endl << "WrongCat:\n";
	delete wrongCat;
}