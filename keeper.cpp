#include <iostream>
#include <fstream>
#include"keeper.h"
#include "characters.h"
#include "hero.h"
#include "villain.h"
#include "monster.h"

using namespace std;

Keeper::Keeper(): maxSize(0), currentSize(0), container(NULL){}

Keeper::Keeper(int _maxSize, int _currentSize) : maxSize(_maxSize),
currentSize(_currentSize), container(new Ñharacters* [_maxSize]) {}

Keeper::Keeper(const Keeper& keeper) {
	this->maxSize = keeper.maxSize;
	this->currentSize = keeper.currentSize;
	this->container = keeper.container;
}

Keeper::~Keeper() {
	if (container == NULL)
		return;
	for (int i = 0; i < currentSize; i++) {
		delete container[i];
	}
	delete[] container;

}

void Keeper::push(Ñharacters& character) {
	if (maxSize == currentSize) {
		maxSize++;
		Ñharacters** tempContainer = new Ñharacters * [maxSize];
		for (int i = 0; i < currentSize; i++) {
			tempContainer[i] = container[i];
		}
		tempContainer[currentSize] = &character;
		container = tempContainer;
		currentSize++;
	}

	else{
		container[currentSize] = &character;
		currentSize++;
	}
}

void Keeper::pop() {
	if (currentSize == 0)
		throw exception("There is nothing to delete");
		string name = container[currentSize-1]->getName();
		delete container[currentSize-1];
		currentSize--;
		std::cout << "Character " << name << " was removed" << std::endl;
}

void Keeper::popByNumber(int del_id) {
	del_id--;
	if (del_id<0 || del_id>currentSize)
		throw exception("Out of range");

		string name = container[del_id]->getName();
		Ñharacters** tmp = new Ñharacters * [maxSize];
		for (int i = 0, j = 0; j < currentSize; i++, j++) {
			if (del_id == i)
				j++;
			tmp[i] = container[j];
		}
		container = tmp;
		currentSize -= 1;
		std::cout << "Character " << name << " was removed" << std::endl;
	
}

void Keeper::saveToFile(std::string pth) {
	ofstream f(pth);
	f << currentSize << '\n';
	for (int i = 0; i < currentSize; i++)
		f << container[i]->info();
	f.close();
	std::cout << "Container was saved to file" << std::endl;
}

void Keeper::getFromFile(std::string pth) {
	//øàáëîí
	std::string name;
	std::string typeWeapon;
	std::string baseAttack, powerAttack, ultimateAttack;
	std::string crime;
	std::string location;
	std::string app;

	ifstream f(pth);
	if (!f.is_open())
		return;
	int curSz;
	int charType;
	f >> curSz;
	Ñharacters* buf = NULL;
	for (int i = 0; i < curSz; i++) {
		f >> charType;
		switch (charType) {
		case 1: //hero
			f.ignore(); getline(f, name);
			getline(f, typeWeapon);
			getline(f, baseAttack);
			getline(f, powerAttack);
			getline(f, ultimateAttack);
			buf = new Hero(name, typeWeapon, baseAttack, powerAttack, ultimateAttack);
			break;
		case 2:
			f.ignore(); getline(f, name);
			getline(f, typeWeapon);
			getline(f, baseAttack);
			getline(f, powerAttack);
			getline(f, crime);
			getline(f, location);
			
			buf = new Villain(name, typeWeapon, baseAttack, powerAttack, crime, location);
			break;
		case 3:
			f.ignore(); getline(f, name);
			getline(f, app);
			buf = new Monster(name, app);
			break;
		}
		push(*buf);
	}

	f.close();
	std::cout << "Container was extracted from file" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Keeper& keeper) {
	if (keeper.currentSize)
		for (int i = 0; i < keeper.currentSize; i++) {
			out << i + 1 << ". ";
			out << keeper.container[i]->info();
		}
	return out;
}

void Keeper::changeCharacter(int number) {
	number--;
	if (number<0 || number>=currentSize)
		throw exception("Out of range");
	
		container[number]->changer();
		std::cout << "Character was changed" << std::endl;

}

void Keeper::getCharInfo(int number) {
	number--;
	if (number<0 || number>=currentSize)
		throw exception("Out of range");

		std::cout << container[number]->info(); 
}