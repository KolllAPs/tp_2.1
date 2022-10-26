#include<iostream>
#include"hero.h"

hero::hero(): weaponType(""), baseAttack(""), powerAttack(""), ultimateAttack(""){}

hero::hero(std::string n, std::string wt, std::string ba, std::string pa, std::string ua) : weaponType(wt),
baseAttack(ba), powerAttack(pa), ultimateAttack(ua) {
	this->name = n;
}

hero::hero(const hero& _hero) {
	this->weaponType = _hero.weaponType;
	this->baseAttack = _hero.baseAttack;
	this->powerAttack = _hero.powerAttack;
	this->ultimateAttack = _hero.ultimateAttack;
}

hero::~hero(){}

void hero::setWeaponType() {
	std::getline(std::cin, this->weaponType);
}

void hero::setbaseAttack() {
	std::getline(std::cin, this->baseAttack);
}

void hero::setPowerAttack() {
	std::getline(std::cin, this->powerAttack);
}

void hero::setUltimateAttack() {
	std::getline(std::cin, this->ultimateAttack);
}

std::string hero::getWeaponType() {
	return this->weaponType;
}

std::string hero::getBaseAttack() {
	return this->baseAttack;
}

std::string hero::getPowerAttack() {
	return this->powerAttack;
}

std::string hero::getUltimateAttack() {
	return this->ultimateAttack;
}

std::string hero::info() {
	std::string info;
	info = std::to_string(id_) + "\n" + getName() + "\n" + getWeaponType() + "\n"
		+ getBaseAttack() + "\n" + getBaseAttack() + "\n" + getUltimateAttack() + "\n";
	return info;
}