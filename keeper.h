#include<iostream>
#include"characters.h"

class Keeper {
	int maxSize;
	int currentSize;
	characters** container;

public:
	Keeper();
	Keeper(int, int);
	Keeper(const Keeper&);
	~Keeper();

	friend std::ostream& operator<< (std::ostream& out, const Keeper& keeper);

	void push(characters&);
	void pop();
	void popByNumber(int);

	void saveToFile(std::string);
	void getFromFile(std::string);
};