#include<iostream>
#include"characters.h"

characters::characters(): name("") {}

characters::characters(std::string _name): name(_name) {}

characters::characters(const characters& _characters) {
	this->name = _characters.name;
}

characters::~characters(){}

void characters::setName() {
	std::getline(std::cin, this->name);
}

std::string characters::getName() {
	return this->name;
}

