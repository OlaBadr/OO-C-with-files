#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <vector>
#include "sdata.h"
using namespace std;

sdata datarray[800]; //make a global array of objects from class sdata
void read_grades(); //read grades from file "studentsGrade.csv"
void calc_normalize(int nos); //do normalizing calculation and export to "normalizedata.csv"
void symbols(int nos); //replace grades with grades symbola and export to "symbolsGrades.csv"
void statistics(int n); // do statistics for each course then export to "courseStatistics.csv"
void printdata(int nos); // print all data related to a student on CONSOLE window, when the ID is given 


int main()
{
	//reading data , Part 1 of project 
	int i = 0;
	ifstream studentsdata("studentsData.csv");
	if (studentsdata.is_open() == 1)
	{
		while (!studentsdata.eof())
		{
			string code, age, name, gender;
			getline(studentsdata, code, ',');
			datarray[i].setcode(code);

			getline(studentsdata, name, ',');
			datarray[i].setname(name);

			getline(studentsdata, age, ',');
			datarray[i].setage(age);

			getline(studentsdata, gender);
			datarray[i].setgender(gender);

			//test line to ensure that the data is read correctly and in the right order
			/*cout << datarray[i].getcode() << ","
				<< datarray[i].getname() << ","
				<< datarray[i].getage() << ","
				<< datarray[i].getgender() << endl; */
			i++;
		}
	}
	else
		cout << "can't open file" << endl;

	studentsdata.close();
	int nos = i - 1; //nos = number of students 



	// File for Normalizing , Part 2 of project
	read_grades();
	calc_normalize(nos);


	//File for grades symbols , Part 3 of project
	symbols(nos);


	//File for Statistics , Part 4 of project
	statistics(nos);


	//print data on console window , Part 5 of project
	printdata(nos);

	return 0;
}

void read_grades()
{
	ifstream studgrades("studentsGrade.csv");
	if (studgrades.is_open() == 1)
	{
		string line, code, r;
		int m, ph, dw, com, ch;
		char c;
		int i = 0;
		while (!studgrades.eof())
		{
			if (i == 0)
			{
				for (int j = 0; j < 5; j++)
					getline(studgrades, line, ',');

				getline(studgrades, line);
			}
			else
			{
				string r;
				getline(studgrades, r, ',');
				stringstream raw(r);
				raw >> code;

				getline(studgrades, r, ',');
				m = stof(r);
				datarray[i].setmath(m);

				getline(studgrades, r, ',');
				ph = stof(r);
				datarray[i].setph(ph);

				getline(studgrades, r, ',');
				dw = stof(r);
				datarray[i].setdraw(dw);

				getline(studgrades, r, ',');
				com = stof(r);
				datarray[i].setcomp(com);

				getline(studgrades, r);
				ch = stof(r);
				datarray[i].setch(ch);

				//test line to ensure that the data is read correctly and in the right order
				/*cout << datarray[i].getmath() << " ," << datarray[i].getph() << ", "
					<< datarray[i].getdraw() << "," << datarray[i].getcomp() << "," << datarray[i].getch() << endl;*/
			}
			i++;
		}
	}
	else
		cout << "\n Cannot open grades file" << endl;
}
void calc_normalize(int nos)
{
	ofstream normalizedata("normalizedata.csv");
	if (normalizedata.is_open() == 1)
	{
		normalizedata << "student code" << ','
			<< "norm math" << ','
			<< "norm physics" << ','
			<< "norm drawing " << ','
			<< "norm computer " << ','
			<< "norm chemistry" << endl;

		for (int i = 1; i <= nos; i++)
		{
			normalizedata << datarray[i].getcode() << ','
				<< (datarray[i].getmath() - datarray[i].getmean()) / datarray[i].getdev() << ','
				<< (datarray[i].getph() - datarray[i].getmean()) / datarray[i].getdev() << ','
				<< (datarray[i].getdraw() - datarray[i].getmean()) / datarray[i].getdev() << ','
				<< (datarray[i].getcomp() - datarray[i].getmean()) / datarray[i].getdev() << ','
				<< (datarray[i].getch() - datarray[i].getmean()) / datarray[i].getdev() << ',' << endl;
		}
	}
	else
		cout << " cannot open normalizing file" << endl;
}
void symbols(int nos)
{
	ofstream symbols("symbolsGrades.csv");
	if (symbols.is_open() == 1)
	{
		symbols << "student code" << ','
			<< "math" << ','
			<< "physics" << ','
			<< "drawing " << ','
			<< "computer " << ','
			<< "chemistry" << endl;
		for (int i = 1; i <= nos; i++)
		{
			symbols << datarray[i].getcode() << ','
				<< datarray[i].symgrades(datarray[i].getmath()) << ','
				<< datarray[i].symgrades(datarray[i].getph()) << ','
				<< datarray[i].symgrades(datarray[i].getdraw()) << ','
				<< datarray[i].symgrades(datarray[i].getcomp()) << ','
				<< datarray[i].symgrades(datarray[i].getch()) << ',' << endl;
		}
	}
	else
		cout << "\n can't open symbols file" << endl;
}
void statistics(int n)
{
	float nos = n;
	float countA = 0, countB = 0, countC = 0, countD = 0, countF = 0;
	ofstream stc("courseStatistics.csv");
	if (stc.is_open() == 1)
	{
		stc << "course name" << ','
			<< "Got A" << ','
			<< "Got B" << ','
			<< "Got C" << ','
			<< "Got D" << ','
			<< "Got F" << endl;

		//for Math 
		for (int i = 1; i <= nos; i++)
		{
			float x = datarray[i].getmath();
			if (x >= 90)
				countA++;
			else if (x >= 80 && x < 90)
				countB++;
			else if (x >= 70 && x < 80)
				countC++;
			else if (x >= 60 && x < 70)
				countD++;
			else
				countF++;
		}


		stc << "Math" << ','
			<< (countA / nos) * 100 << "%" << ','
			<< ((countB / nos) * 100) << "%" << ','
			<< ((countC / nos) * 100) << "%" << ','
			<< ((countD / nos) * 100) << "%" << ','
			<< ((countD / nos) * 100) << "%" << ',' << endl;

		//for Physics
		countA = 0, countB = 0, countC = 0, countD = 0, countF = 0;
		for (int i = 1; i <= nos; i++)
		{
			float x = datarray[i].getph();
			if (x >= 90)
				countA++;
			else if (x >= 80 && x < 90)
				countB++;
			else if (x >= 70 && x < 80)
				countC++;
			else if (x >= 60 && x < 70)
				countD++;
			else
				countF++;
		}
		stc << "Physics" << ','
			<< ((countA / nos) * 100) << "%" << ','
			<< (countB / nos) * 100 << "%" << ','
			<< (countC / nos) * 100 << "%" << ','
			<< (countD / nos) * 100 << "%" << ','
			<< (countF / nos) * 100 << "%" << ',' << endl;

		//for Drawing

		countA = 0, countB = 0, countC = 0, countD = 0, countF = 0;
		for (int i = 1; i <= nos; i++)
		{
			float x = datarray[i].getdraw();
			if (x >= 90)
				countA++;
			else if (x >= 80 && x < 90)
				countB++;
			else if (x >= 70 && x < 80)
				countC++;
			else if (x >= 60 && x < 70)
				countD++;
			else
				countF++;
		}
		stc << "Drawing" << ','
			<< (countA / nos) * 100 << "%" << ','
			<< (countB / nos) * 100 << "%" << ','
			<< (countC / nos) * 100 << "%" << ','
			<< (countD / nos) * 100 << "%" << ','
			<< (countF / nos) * 100 << "%" << ',' << endl;

		//for Computer 
		countA = 0, countB = 0, countC = 0, countD = 0, countF = 0;
		for (int i = 1; i <= nos; i++)
		{
			float x = datarray[i].getcomp();
			if (x >= 90)
				countA++;
			else if (x >= 80 && x < 90)
				countB++;
			else if (x >= 70 && x < 80)
				countC++;
			else if (x >= 60 && x < 70)
				countD++;
			else
				countF++;
		}

		stc << "Computer" << ','
			<< (countA / nos) * 100 << "%" << ','
			<< (countB / nos) * 100 << "%" << ','
			<< (countC / nos) * 100 << "%" << ','
			<< (countD / nos) * 100 << "%" << ','
			<< (countF / nos) * 100 << "%" << ',' << endl;

		//for Chemistiry

		countA = 0, countB = 0, countC = 0, countD = 0, countF = 0;
		for (int i = 1; i <= nos; i++)
		{
			float x = datarray[i].getch();
			if (x >= 90)
				countA++;
			else if (x >= 80 && x < 90)
				countB++;
			else if (x >= 70 && x < 80)
				countC++;
			else if (x >= 60 && x < 70)
				countD++;
			else
				countF++;
		}

		stc << "Chemistiry" << ','
			<< (countA / nos) * 100 << "%" << ','
			<< (countB / nos) * 100 << "%" << ','
			<< (countC / nos) * 100 << "%" << ','
			<< (countD / nos) * 100 << "%" << ','
			<< (countF / nos) * 100 << "%" << ',' << endl;
	}

	else
		cout << "can't open statistics file" << endl;
}
void printdata(int nos)
{
	string code;
	bool cont = 1;
	while (cont == 1)
	{
		cout << "Kindly Enter your code" << endl;
		cin >> code;

		for (int i = 1; i <= nos; i++)
		{
			if (code == datarray[i].getcode())
			{
				cout << "Name: " << datarray[i].getname() << "\n"
					<< "age: " << datarray[i].getage() << "\n"
					<< "gender: " << datarray[i].getgender() << "\n"
					<< "******** Grades *********" << "\n"
					<< "Math:  " << datarray[i].getmath() << "\n"
					<< "Physics:  " << datarray[i].getph() << "\n"
					<< "Drawing:  " << datarray[i].getdraw() << "\n"
					<< "Computer:  " << datarray[i].getcomp() << "\n"
					<< "Chemistiry:  " << datarray[i].getch() << "\n";
				break;
			}
			else
				continue;
		}
		cout << "if you want to type another code press: 1 , if you want to end press: 0" << endl;
		cin >> cont;
	}
}
