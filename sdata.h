#pragma once
#include <iostream>
#include "sgrades.h"
using namespace std;

class sdata : public sgrades 
{
private:
	string code;
	string name;
	string age;
	string gender;

public:
	//setters
	void setcode(string c);
	void setname(string n);
	void setage(string a);
	void setgender(string g);

	//getters
	string getcode();
	string getname();
	string getage();
	string getgender();


};

