#pragma once 

#include<string>

class �haracters {
protected:
	std::string name;
public:
	�haracters();
	�haracters(std::string);
	�haracters(const �haracters&);
	~�haracters();
	void setName();
	std::string getName();
	virtual std::string info() = 0;
	virtual void changer() = 0;
};

