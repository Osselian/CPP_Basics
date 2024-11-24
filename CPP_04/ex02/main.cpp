#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	{
		//const Animal *animal = new Animal();
		const Animal *cat = new Cat();
		const Animal *dog = new Dog();
		const WrongAnimal *wrongAnimal = new WrongAnimal();
		const WrongAnimal *wrongCat = new WrongCat();

		//std::cout << "\nAnimal: type - " << animal->getType() << ", sound";
		//animal->makeSound();
		std::cout << "Cat: type - " << cat->getType() << ", sound";
		cat->makeSound();
		std::cout << "Dog: type - " << dog->getType() << ", sound";
		dog->makeSound();
		std::cout << "WrongAnimal: type - " << wrongAnimal->getType() << ", sound";
		wrongAnimal->makeSound();
		std::cout << "WrongCat: type - " << wrongCat->getType() << ", sound";
		wrongCat->makeSound();

		std::cout << std::endl << "MAIN SCOPE DESTRUCTION:\nAnimal:\n";
		//delete animal;
		std::cout << std::endl << "Cat:\n";
		delete cat;
		std::cout << std::endl << "Dog:\n";
		delete dog;
		std::cout << std::endl << "WrongAnimal:\n";
		delete wrongAnimal;
		std::cout << std::endl << "WrongCat:\n";
		delete wrongCat;
		std::cout << std::endl << "MAIN SCOPE DESTRUCTION END\n\n";
	}

	{
		std::cout << "Pointer array test:\n";
		Animal *animals[4];
		for (int i = 0; i < 2; i++)
		{
			animals[i] = new Cat();
		}
		for (int i = 2; i < 4; i++)
		{
			animals[i] = new Dog();
		}
		std::cout <<std::endl;
		for (int i = 0; i < 4; i++)
		{
			std::cout << "Animal: type - " << animals[i]->getType() << ", sound";
	        animals[i]->makeSound();
			delete animals[i];
	    }
		std::cout <<std::endl;
	}

	//{
	//	std::cout << "\nTEST1:\n";
	//	Animal kitty;
	//	Animal pups;

	//	kitty = pups;
	//	std::cout << "Kitty: type - " << kitty.getType() << ", sound";
	//	kitty.makeSound();
	//}
	//std::cout << std::endl;
	//{
	//	std::cout << "\nTEST2:\n";
	//	Animal kitty = *new Cat();
	//	Animal pups = *new Dog();

	//	kitty = pups;
	//	std::cout << "Kitty: type - " << kitty.getType() << ", sound";
	//	kitty.makeSound();
	//}
	std::cout << std::endl;
	{
		std::cout << "\nTEST3:\n";
		Animal *kitty = new Cat();
		Animal *pups = new Dog();

		*kitty = *pups;
		std::cout << "Kitty: type - " << kitty->getType() << ", sound";
		kitty->makeSound();
	}

	{
	
		std::cout <<std::endl;
		std::cout << "Assignment test" <<std::endl;
		Dog korgy;
		{
			Dog spaniel = korgy;
		}
	}
	{
		std::cout << std::endl << "Copy test" <<std::endl;
		Dog korgy;
		Dog rex(korgy);
	}
}
