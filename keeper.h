#include<iostream>
#include"characters.h"

class Keeper {
	int maxSize;
	int currentSize;
	�haracters** container;

public:
	Keeper();
	Keeper(int, int);
	Keeper(const Keeper&);
	~Keeper();

	friend std::ostream& operator<< (std::ostream& out, const Keeper& keeper);

	void push(�haracters&);
	void pop();
	void popByNumber(int);

	void saveToFile(std::string);
	void getFromFile(std::string);
	void changeCharacter(int);
	void getCharInfo(int);
};