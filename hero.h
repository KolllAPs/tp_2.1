#pragma once
#include"characters.h"

class hero : public characters {
	const int id_ = 1;
	std::string weaponType;
	std::string baseAttack;
	std::string powerAttack;
	std::string ultimateAttack;

public:
	hero();
	hero(std::string, std::string, std::string, std::string, std::string);
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

	std::string info();
};


