/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:45:01 by minabe            #+#    #+#             */
/*   Updated: 2023/12/03 20:34:01 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	Animal	*animals[4];

	// DogとCatのオブジェクトを作成
	animals[0] = new Dog();
	animals[1] = new Cat();

	// ideaをセット
	for (int i = 0; i < 100; i++)
	{
		static_cast<Dog *>(animals[0])->getBrain()->setIdea(i, "Bone!!");
		static_cast<Cat *>(animals[1])->getBrain()->setIdea(i, "Tuna!!");
	}

	// DogとCatのコピーを作成
	animals[2] = new Dog(*static_cast<Dog *>(animals[0]));
	animals[3] = new Cat(*static_cast<Cat *>(animals[1]));

	// それぞれのideaを取得
	for (int i = 0; i < 4; i++)
	{
		std::cout << "animals[" << i << "]" << std::endl;

		Dog	*dog = dynamic_cast<Dog *>(animals[i]);
		if (dog)
			std::cout << "Dog Brain: " << dog->getBrain()->getIdea(0) << std::endl;

		Cat	*cat = dynamic_cast<Cat *>(animals[i]);
		if (cat)
			std::cout << "Cat Brain: " << cat->getBrain()->getIdea(0) << std::endl;
	}

	// メモリの解放
	for (int i = 0; i < 4; i++)
		delete animals[i];

	return (0);
}

__attribute__((destructor))
static void destructor(void)
{
	system("leaks -q ex01");
}
