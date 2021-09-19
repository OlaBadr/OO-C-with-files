#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class sgrades 
{
private :
    float math, ph, comp, drawing, chem;
    float mean, dev;
public :
    //setters

    void setmath(float m);
    void setph(float p);
    void setcomp(float c);
    void setdraw(float d);
    void setch(float ch);

    //getters 
    float getmath();
    float getph();
    float getcomp();
    float getdraw();
    float getch();

    //calculations 
    float getmean();
    float getdev();
    string symgrades(float x);

};

