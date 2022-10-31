#include<iostream>
#include"villain.h"


Villain::Villain() :weaponType(""), baseAttack(""), powerAttack(""), crime(""), location("") {}

Villain::Villain(std::string n, std::string wt, std::string ba, std::string pa, std::string c, std::string l) :
	weaponType(wt), baseAttack(ba), powerAttack(pa), crime(c), location(l) {
	this->name = n;
}

Villain::Villain(const Villain& _villian) {
	this->weaponType = _villian.weaponType;
	this->baseAttack = _villian.baseAttack;
	this->powerAttack = _villian.powerAttack;
	this->crime = _villian.crime;
	this->location = _villian.location;
}

Villain::~Villain() {}

Villain& Villain::operator=(const Villain& villian) {
	this->name = villian.name;
	this->weaponType = villian.weaponType;
	this->baseAttack = villian.baseAttack;
	this->powerAttack = villian.powerAttack;
	this->crime = villian.crime;
	this->location = villian.location;
	return*this;
}

void Villain::setWeaponType() {
	std::cout << "Input weapon type" << std::endl;
	std::getline(std::cin, this->weaponType);
}

void Villain::setBaseAttack() {
	std::cout << "Input base attack" << std::endl;
	std::getline(std::cin, this->baseAttack);
}

void Villain::setPowerAttack() {
	std::cout << "Input power attack" << std::endl;
	std::getline(std::cin, this->powerAttack);
}

void Villain::setCrime() {
	std::cout << "Input crime" << std::endl;
	std::getline(std::cin, this->crime);
}

void Villain::setLocation() {
	std::cout << "Input location" << std::endl;
	std::getline(std::cin, this->location);
}

std::string Villain::getWeaponType() {
	return this->weaponType;
}

std::string Villain::getbaseAttack() {
	return this->baseAttack;
}

std::string Villain::getPowerAttack() {
	return this->powerAttack;
}

std::string Villain::getCrime() {
	return this->crime;
}

std::string Villain::getLocation() {
	return this->location;
}

std::string Villain::info() {
	std::string info;
	info = std::to_string(charType) + "\n" + getName() + "\n" + getWeaponType() + "\n" +
		getbaseAttack() + "\n" + getPowerAttack() + "\n" + getCrime() + "\n" +
		getLocation() + "\n";
	return info;
}

void Villain::changer() {
	std::cout << "Type of character you're changing: " << this->charType << std::endl;
	std::cout << "Name of the character: " << this->name << std::endl;
	setName();
	setWeaponType();
	setBaseAttack();
	setPowerAttack();
	setCrime();
	setLocation();
}