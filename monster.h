#pragma once

#include"characters.h"


class monster : public characters {
	const int id_ = 3;
	std::string appearane;

public:
	monster();
	monster(std::string, std::string);
	monster(const monster&);
	~monster();

	void setAppearance();

	std::string getAppearance();

	virtual std::string info();

};