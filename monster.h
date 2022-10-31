#pragma once

#include"characters.h"


class Monster : public Ñharacters {
	const int charType = 3;
	std::string appearane;

public:
	Monster();
	Monster(std::string, std::string);
	Monster(const Monster&);
	~Monster();

	Monster& operator=(const Monster&);

	void setAppearance();

	std::string getAppearance();

	std::string info();
	void changer();

};