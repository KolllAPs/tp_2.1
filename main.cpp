#include<iostream>
#include"keeper.h"
#include"characters.h"
#include"hero.h"
#include"villain.h"
#include"monster.h"

bool flag = true;

void printMenu();
void getAnswer(Keeper&, int);
void addCharacter(Keeper&, int);

int main(void) {
	Keeper contain;
	int numCase;
	while (flag) {
		printMenu();
		std::cin >> numCase;
		getAnswer(contain, numCase);
		system("pause");
	}

	return 0;
}

void printMenu() {
	system("cls");
	std::cout << "List of characters\n"
		<< "1. Add character\n"
		<< "2. Delete character\n"
		<< "3. Delete character by number\n"
		<< "4. Get info about character\n"
		<< "5. Save list to file\n"
		<< "6. Extract list from file\n"
		<< "7. Change character by number\n"
		<< "8. Quit\n" 
		<< "> ";
}

void addCharacter(Keeper& keeper, int charType) {
	std::string 
		name, weaponType,
		baseAttack, powerAttack,
		ultimateAttack, crime,
		location, appearance;
	Ñharacters* buffer = NULL;
	switch(charType) {
	case 1:
		std::cin.ignore(); 
		std::cout << "Input name" << std::endl;
		getline(std::cin, name, '\n');
		std::cout << "Input type of weapon" << std::endl;
		getline(std::cin, weaponType, '\n');
		std::cout << "Input base attack" << std::endl;
		getline(std::cin, baseAttack, '\n');
		std::cout << "Input power attack" << std::endl;
		getline(std::cin, powerAttack, '\n');
		std::cout << "Input ultimate attack" << std::endl;
		getline(std::cin, ultimateAttack,'\n');
		buffer = new Hero(name, weaponType, baseAttack, powerAttack, ultimateAttack);
		keeper.push(*buffer);
		break;
	case 2:
		std::cin.ignore(); 
		std::cout << "Input name" << std::endl;
		getline(std::cin, name, '\n');
		std::cout << "Input type of weapon" << std::endl;
		getline(std::cin, weaponType, '\n');
		std::cout << "Input base attack" << std::endl;
		getline(std::cin, baseAttack, '\n');
		std::cout << "Input power attack" << std::endl;
		getline(std::cin, powerAttack, '\n');
		std::cout << "Input crime" << std::endl;
		getline(std::cin, crime, '\n');
		std::cout << "Input location" << std::endl;
		getline(std::cin, location, '\n');
		buffer = new Villain(name, weaponType, baseAttack, powerAttack, crime, location);
		keeper.push(*buffer);
		break;
	case 3:
		std::cin.ignore();
		std::cout << "Input name" << std::endl;
		getline(std::cin, name, '\n');
		std::cout << "Input appearance" << std::endl;
		getline(std::cin, appearance, '\n');
		buffer = new Monster(name, appearance);
		keeper.push(*buffer);
		break;
	default:
		std::cout << "try again" << std::endl;
		break;
	}
}

void getAnswer(Keeper& keeper, int number) {
	int numer;
	switch (number) {
	case 1:
		int charType;
		std::cout << "Input number of characters type:" << std::endl;
		std::cout << "1. Hero\n"
			<< "2. Villain\n"
			<< "3. Monster\n" << std::endl;
		std::cin >> charType;
		addCharacter(keeper, charType);
		break;
	case 2:
		try {
			keeper.pop();
		}
		catch (const std::exception& ex) {
			std::cout << "Something went wrong. Error: " << ex.what() << std::endl;
		}
		break;
	case 3:
		std::cout << "Input number of character to delete" << std::endl;
		std::cin >> numer;
		try {
			keeper.popByNumber(numer);
		}
		catch (const std::exception& ex) {
			std::cout << "Something went wrong. Error: " << ex.what() << std::endl;
		}
		break;
	case 4:
		std::cout << "write number of element to get info" << std::endl;
		std::cin >> numer;
		try {
			keeper.getCharInfo(numer);
		}
		catch (const std::exception& ex) {
			std::cout << "Characters info can not be provided: " << ex.what() << std::endl;
		}
		break;
	case 5:
		keeper.saveToFile("Source.txt");
		break;
	case 6:
		keeper.getFromFile("Source.txt");
		break;

	case 7:
		std::cout << "Input number of character to change" << std::endl;
		std::cin >> numer;
		try {
			keeper.changeCharacter(numer);
		}
		catch (const std::exception& ex) {
			std::cout << "Character can not be changed: " << ex.what() << std::endl;
		}
		break;
	case 8:
		flag = false;
		break;
	default:
		std::cout << "Try another number" << std::endl;
	}
}
