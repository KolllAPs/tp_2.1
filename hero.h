#pragma once
#include"characters.h"

class Hero : public Ñharacters {
	const int charType = 1;
	std::string weaponType;
	std::string baseAttack;
	std::string powerAttack;
	std::string ultimateAttack;

public:
	Hero();
	Hero(std::string, std::string, std::string, std::string, std::string);
	Hero(const Hero&);
	~Hero();

	Hero& operator=(const Hero&);

	void setWeaponType();
	void setBaseAttack();
	void setPowerAttack();
	void setUltimateAttack();

	std::string getWeaponType();
	std::string getBaseAttack();
	std::string getPowerAttack();
	std::string getUltimateAttack();

	std::string info();
	void changer();
};


