#include<iostream>
#include"hero.h"

Hero::Hero():  weaponType(""), baseAttack(""), powerAttack(""), ultimateAttack("") {
	this->name = "";
}

Hero::Hero(std::string n, std::string wt, std::string ba, std::string pa, std::string ua) : weaponType(wt),
baseAttack(ba), powerAttack(pa), ultimateAttack(ua) {
	this->name = n;
}

Hero::Hero(const Hero& _hero) {
	this->weaponType = _hero.weaponType;
	this->baseAttack = _hero.baseAttack;
	this->powerAttack = _hero.powerAttack;
	this->ultimateAttack = _hero.ultimateAttack;
}

Hero::~Hero(){}

void Hero::setWeaponType() {

	std::cout << "Input weapon type" << std::endl;
	std::getline(std::cin, this->weaponType);
}

void Hero::setBaseAttack() {

	std::cout << "Input base attack" << std::endl;
	std::getline(std::cin, this->baseAttack);
}

void Hero::setPowerAttack() {
	
	std::cout << "Input power attack" << std::endl;
	std::getline(std::cin, this->powerAttack);
}

void Hero::setUltimateAttack() {
	
	std::cout << "Input ultimate attack" << std::endl;
	std::getline(std::cin, this->ultimateAttack);
}

std::string Hero::getWeaponType() {
	return this->weaponType;
}

std::string Hero::getBaseAttack() {
	return this->baseAttack;
}

std::string Hero::getPowerAttack() {
	return this->powerAttack;
}

std::string Hero::getUltimateAttack() {
	return this->ultimateAttack;
}

std::string Hero::info() {
	std::string info;
	info = std::to_string(charType) + "\n" + getName() + "\n" + getWeaponType() + "\n"
		+ getBaseAttack() + "\n" + getPowerAttack() + "\n" + getUltimateAttack() + "\n";
	return info;
}

void Hero::changer() {
	std::cout << "Type of character you're changing: " << this->charType << std::endl;
	std::cout << "Name of the character: " << this->name << std::endl;
	setName();
	setWeaponType();
	setBaseAttack();
	setPowerAttack();
	setUltimateAttack();
}

Hero& Hero::operator= (const Hero& hero) {
	this->name = hero.name;
	this->weaponType = hero.weaponType;
	this->baseAttack = hero.baseAttack;
	this->powerAttack = hero.powerAttack;
	this->ultimateAttack = hero.ultimateAttack;
	return*this;
}