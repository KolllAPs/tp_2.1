#pragma once 

#include<string>

class characters {
protected:
	std::string name;
public:
	characters();
	characters(std::string);
	characters(const characters&);
	~characters();
	void setName();
	std::string getName();
	virtual void someFunction();
};

