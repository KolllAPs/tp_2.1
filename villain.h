#pragma once

#include"characters.h"

class Villain : public Ñharacters {
	const int charType = 2;
	std::string weaponType;
	std::string baseAttack;
	std::string powerAttack;
	std::string crime;
	std::string location;

public:
	Villain();
	Villain(std::string, std::string, std::string, std::string, std::string, std::string);
	Villain(const Villain&);
	~Villain();

	Villain& operator=(const Villain&);

	void setWeaponType();
	void setBaseAttack();
	void setPowerAttack();
	void setCrime();
	void setLocation();

	std::string getWeaponType();
	std::string getbaseAttack();
	std::string getPowerAttack();
	std::string getCrime();
	std::string getLocation();

	std::string info();
	void changer();
};