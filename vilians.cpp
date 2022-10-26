#include<iostream>
#include"vilian.h"

villian::villian():weaponType(""), baseAttack(""), powerAttack(""), crime(""), location(""){}

villian::villian(std::string n, std::string wt, std::string ba, std::string pa, std::string c, std::string l):
	weaponType(wt), baseAttack(ba), powerAttack(pa), crime(c), location(l) {
	this->name = n;
}

villian::villian(const villian& _villian) {
	this->weaponType = _villian.weaponType;
	this->baseAttack = _villian.baseAttack;
	this->powerAttack = _villian.powerAttack;
	this->crime = _villian.crime;
	this->location = _villian.location;
}

villian::~villian(){}

void villian::setWeaponType() {
	std::getline(std::cin, this->weaponType);
}

void villian::setbaseAttack() {
	std::getline(std::cin, this->baseAttack);
}

void villian::setPowerAttack() {
	std::getline(std::cin, this->powerAttack);
}

void villian::setCrime() {
	std::getline(std::cin, this->crime);
}

void villian::setLocation() {
	std::getline(std::cin, this->location);
}

std::string villian::getWeaponType() {
	return this->weaponType;
}

std::string villian::getbaseAttack() {
	return this->baseAttack;
}

std::string villian::getPowerAttack() {
	return this->powerAttack;
}

std::string villian::getCrime() {
	return this->crime;
}

std::string villian::getLocation() {
	return this->location;
}

std::string villian::info() {
	std::string info;
	info = std::to_string(id_) + "\n" + getName() + "\n" + getWeaponType() + "\n" + getCrime() + "\n" +
		getLocation() + "\n" + getbaseAttack() + "\n" + getPowerAttack() + "n";
	return info;
}