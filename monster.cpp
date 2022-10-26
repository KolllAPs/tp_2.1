#include<iostream>
#include"monster.h"

monster::monster(): appearane(""){}

monster::monster(std::string n, std::string a) : appearane(a) { this->name = n; }

monster::monster(const monster& _monster) {
	this->appearane = _monster.appearane;
}

monster::~monster(){}

void monster::setAppearance() {
	std::getline(std::cin, this->appearane);
}

std::string monster::getAppearance() {
	return this->appearane;
}

std::string monster::info() {
	std::string info;
	info = std::to_string(id_) + "\n" + getName() + "\n" + getAppearance() + "\n";
	return info;
}