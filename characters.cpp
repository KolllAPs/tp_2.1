#include<iostream>
#include"characters.h"

�haracters::�haracters(): name("") {}

�haracters::�haracters(std::string _name): name(_name) {}

�haracters::�haracters(const �haracters& _characters) {
	this->name = _characters.name;
}

�haracters::~�haracters(){
	std::cout << "Characters del" << std::endl;
}

void �haracters::setName() {
	std::cout << "Input name" << std::endl;
	std::cin.ignore();
	std::getline(std::cin, this->name);
}

std::string �haracters::getName() {
	return this->name;
}

