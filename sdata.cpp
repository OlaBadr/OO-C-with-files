#include "sdata.h"

void sdata::setcode(string c)
{
	code = c;
}

void sdata::setname(string n)
{
	name = n;
}

void sdata::setage(string a)
{
	age = a;
}

void sdata::setgender(string g)
{
	gender = g;
}

string sdata::getcode()
{
	return code;
}

string sdata::getname()
{
	return name;

}

string sdata::getage()
{
	return age;
}

string sdata::getgender()
{
	return gender;
}
