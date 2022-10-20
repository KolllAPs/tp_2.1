#include<iostream>
#include"monster.h"

monster::monster(): appearane(""){}

monster::monster(std::string a): appearane(a){}

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

void monster::someFunction() {
	std::cout << "i do something four" << std::endl;
}