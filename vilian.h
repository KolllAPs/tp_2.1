#pragma once

#include"characters.h"

class villian : public characters {
	const int id_ = 2;
	std::string weaponType;
	std::string baseAttack;
	std::string powerAttack;
	std::string crime;
	std::string location;

public:
	villian();
	villian(std::string, std::string, std::string, std::string, std::string, std::string);
	villian(const villian&);
	~villian();

	void setWeaponType();
	void setbaseAttack();
	void setPowerAttack();
	void setCrime();
	void setLocation();

	std::string getWeaponType();
	std::string getbaseAttack();
	std::string getPowerAttack();
	std::string getCrime();
	std::string getLocation();

	std::string info();
};