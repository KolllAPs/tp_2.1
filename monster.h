#pragma once

#include"characters.h"


class monster : characters {
	std::string appearane;

	monster();
	monster(std::string);
	monster(const monster&);
	~monster();

	void setAppearance();

	std::string getAppearance();

	virtual void someFunction();

};