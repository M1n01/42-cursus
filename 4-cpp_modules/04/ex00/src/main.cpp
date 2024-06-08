/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:45:01 by minabe            #+#    #+#             */
/*   Updated: 2023/12/03 15:51:23 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	Animal	*animals[5];

	// DogとCatのオブジェクトを作成
	animals[0] = new Dog();
	animals[1] = new Cat();

	// DogとCatのコピーを作成
	animals[2] = new Dog(*static_cast<Dog *>(animals[0]));
	animals[3] = new Cat(*static_cast<Cat *>(animals[1]));

	animals[4] = new Animal();

	for (int i = 0; i < 5; i++)
	{
		std::cout << "===animals[" << i << "]===" << std::endl;

		Dog	*dog = dynamic_cast<Dog *>(animals[i]);
		if (dog)
		{
			std::cout << "Dog: ";
			dog->makeSound();
			continue ;
		}

		Cat	*cat = dynamic_cast<Cat *>(animals[i]);
		if (cat)
		{
			std::cout << "Cat:  ";
			cat->makeSound();
			continue ;
		}

		std::cout << "Animal:  ";
		animals[i]->makeSound();
	}

	// メモリの解放
	for (int i = 0; i < 5; i++)
		delete animals[i];

	std::cout << "---------------------" << std::endl;

	const WrongAnimal	*wrongCat = new WrongCat();

	std::cout << wrongCat->getType() << ": ";
	wrongCat->makeSound();

	delete wrongCat;

	return (0);
}

__attribute__((destructor))
static void destructor(void)
{
	system("leaks -q ex00");
}
