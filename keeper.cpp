#include <iostream>
#include <fstream>
#include"keeper.h"
#include "characters.h"
#include "hero.h"
#include "vilian.h"
#include "monster.h"

using namespace std;

Keeper::Keeper(): maxSize(0), currentSize(0), container(NULL){}

Keeper::Keeper(int _maxSize, int _currentSize) : maxSize(_maxSize),
currentSize(_currentSize), container(new characters* [_maxSize]) {}

Keeper::Keeper(const Keeper& keeper) {
	this->maxSize = keeper.maxSize;
	this->currentSize = keeper.currentSize;
	this->container = keeper.container;
}

Keeper::~Keeper() {
	for (int i = 0; i < currentSize; i++) {
		delete container[i];
	}
	delete[] container;
	maxSize = 0;
	currentSize = 0;
}

void Keeper::push(characters& character) {
	if (maxSize == currentSize) {
		maxSize++;
		characters** tempContainer = new characters * [maxSize];
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
	if (!currentSize)
		return;
	delete container[currentSize - 1];
	currentSize--;
}

void Keeper::popByNumber(int del_id) {
	del_id--;

	characters** tmp = new characters * [maxSize];
	for (int i = 0, j = 0; j < currentSize; i++, j++) {
		if (del_id == i)
			j++;
		tmp[i] = container[j];
	}
	container = tmp;
	currentSize -= 1;
}

void Keeper::saveToFile(std::string pth) {
	ofstream f(pth);
	f << currentSize << '\n';
	for (int i = 0; i < currentSize; i++)
		f << container[i]->info();
	f.close();
}

void Keeper::getFromFile(std::string pth) {
	//шаблон
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
	int id_;
	f >> curSz;
	characters* buf = NULL;
	for (int i = 0; i < curSz; i++) {
		f >> id_;
		switch (id_) {
		case 1: //hero
			f.ignore(); getline(f, name);
			f.ignore(); getline(f, typeWeapon);
			f.ignore(); getline(f, baseAttack);
			f.ignore(); getline(f, powerAttack);
			f.ignore(); getline(f, ultimateAttack);
			buf = new hero(name, typeWeapon, baseAttack, powerAttack, ultimateAttack);
			break;
		case 2:
			f.ignore(); getline(f, name);
			f.ignore(); getline(f, typeWeapon);
			f.ignore(); getline(f, crime);
			f.ignore(); getline(f, location);
			f.ignore(); getline(f, baseAttack);
			f.ignore(); getline(f, powerAttack);
			buf = new villian(name, typeWeapon, crime, location, baseAttack, powerAttack);	
			break;
		case 3:
			f.ignore(); getline(f, name);
			f.ignore(); getline(f, app);
			buf = new monster(name, app);
			break;
		}
		push(*buf);
	}

	f.close();
}

std::ostream& operator<<(std::ostream& out, const Keeper& keeper) {
	if (keeper.currentSize)
		for (int i = 0; i < keeper.currentSize; i++) {
			out << i + 1 << ". ";
			out << keeper.container[i]->info();
		}
	return out;
}