#pragma once

#include"characters.h"

class hero : characters {
	std::string weaponType;
	std::string baseAttack;
	std::string powerAttack;
	std::string ultimateAttack;

	hero();
	hero(std::string, std::string, std::string, std::string);
	hero(const hero&);
	~hero();

	void setWeaponType();
	void setbaseAttack();
	void setPowerAttack();
	void setUltimateAttack();

	std::string getWeaponType();
	std::string getBaseAttack();
	std::string getPowerAttack();
	std::string getUltimateAttack();

	virtual void someFunction();
};


