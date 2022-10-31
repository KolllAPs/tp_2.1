#include<iostream>
#include"monster.h"

Monster::Monster(): appearane(""){}

Monster::Monster(std::string n, std::string a) : appearane(a) { this->name = n; }

Monster::Monster(const Monster& _monster) {
	this->appearane = _monster.appearane;
}

Monster::~Monster(){}

Monster& Monster::operator=(const Monster& monster) {
	this->name = monster.name;
	this->appearane = monster.appearane;
	return *this;
}

void Monster::setAppearance() {
	std::cout << "Input appearance" << std::endl;
	std::getline(std::cin, this->appearane);
}

std::string Monster::getAppearance() {
	return this->appearane;
}

std::string Monster::info() {
	std::string info;
	info = std::to_string(charType) + "\n" + getName() + "\n" + getAppearance() + "\n";
	return info;
}

void Monster::changer() {
	std::cout << "Type of character you're changing: " << this->charType << std::endl;
	std::cout << "Name of the character: " << this->name << std::endl;
	setName();
	setAppearance();
}