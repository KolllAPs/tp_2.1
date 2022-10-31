#include<iostream>
#include"characters.h"

Ñharacters::Ñharacters(): name("") {}

Ñharacters::Ñharacters(std::string _name): name(_name) {}

Ñharacters::Ñharacters(const Ñharacters& _characters) {
	this->name = _characters.name;
}

Ñharacters::~Ñharacters(){
	std::cout << "Characters del" << std::endl;
}

void Ñharacters::setName() {
	std::cout << "Input name" << std::endl;
	std::cin.ignore();
	std::getline(std::cin, this->name);
}

std::string Ñharacters::getName() {
	return this->name;
}

