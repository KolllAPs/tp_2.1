#pragma once 

#include<string>

class Ñharacters {
protected:
	std::string name;
public:
	Ñharacters();
	Ñharacters(std::string);
	Ñharacters(const Ñharacters&);
	~Ñharacters();
	void setName();
	std::string getName();
	virtual std::string info() = 0;
	virtual void changer() = 0;
};

