/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:02:29 by minabe            #+#    #+#             */
/*   Updated: 2023/12/03 21:33:58 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int	main(void)
{
	// MateriaSourceの作成とMateriaの学習
	IMateriaSource	*src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// Characterの作成
	ICharacter	*me = new Character("me");

	// Materiaの作成と装備
	AMateria	*ice = src->createMateria("ice");
	AMateria	*cure = src->createMateria("cure");
	// AMateria	*known = src->createMateria("known");

	me->equip(ice);
	me->equip(cure);

	// 不正な操作のテスト（存在しないMateriaの装備など）
	me->equip(NULL);
	// me->equip(known);
	me->equip(src->createMateria("unknown"));

	// 別のCharacterの作成
	ICharacter*	bob = new Character("bob");

	// // Materiaの使用
	me->use(0, *bob); // Iceの使用
	me->use(1, *bob); // Cureの使用
	me->use(2, *bob); // 何もしないはず（未装備）

	// unequipテスト
	me->unequip(0); // Iceをunequip
	me->use(0, *bob); // 何もしないはず（unequipされている）

	// ディープコピーのテスト
	ICharacter	*clone = new Character(*static_cast<Character*>(me));
	clone->use(1, *clone); // Cureの使用（ディープコピーされているはず）

	delete clone;
	delete bob;
	delete me;
	delete src;

	return (0);
}

__attribute__((destructor))
static void destructor(void)
{
	system("leaks -q ex03");
}
