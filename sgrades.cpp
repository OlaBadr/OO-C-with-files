#include "sgrades.h"

void sgrades::setmath(float m)
{
	math = m;
}

void sgrades::setph(float p)
{
	ph = p;
}

void sgrades::setcomp(float c)
{
	comp = c;
}

void sgrades::setdraw(float d)
{
	drawing = d;
}

void sgrades::setch(float ch)
{
	chem = ch;
}

float sgrades::getmath()
{
	return math;
}

float sgrades::getph()
{
	return ph;
}

float sgrades::getcomp()
{
	return comp;
}

float sgrades::getdraw()
{
	return drawing;
}

float sgrades::getch()
{
	return chem;
}

float sgrades::getmean()
{
	float mean = (math + ph + comp + drawing + chem) / 5;
	return mean;
}

float sgrades::getdev()
{
	float mean = (math + ph + comp + drawing + chem) / 5 ;
	float sq_each_dev = pow((math - mean), 2) + pow((ph - mean), 2) + pow((comp - mean), 2) + pow((drawing - mean), 2) + pow((chem - mean), 2);
	float dev = sqrtf(sq_each_dev / 4);
	return dev;
}

string sgrades::symgrades(float x)
{
	if (x >= 90)
		return "A";

	else if (x >= 85 && x < 90)
		return "B+";

	else if (x >= 80 && x < 85)
		return "B";

	else if (x >= 75 && x < 80)
		return "C+";

	else if (x >= 70 && x < 75)
		return "C";

	else if (x >= 65 && x < 70)
		return "D+";

	else if (x >= 60 && x < 65)
		return "D";
	else
		return "F";
	
}

