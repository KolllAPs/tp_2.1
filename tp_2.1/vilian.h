#pragma once

#include"characters.h"

class vilian : characters {
	std::string weaponType;
	std::string baseAttack;
	std::string powerAttack;
	std::string crime;
	std::string location;

	vilian();
	vilian(std::string, std::string, std::string, std::string, std::string);
	vilian(const vilian&);
	~vilian();

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

	virtual void someFunction();
};