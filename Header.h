/*
Author: Curtis Wartenberg, Kyle Schwarz
Class : 281-04
Assignment : Apriori
Date Assigned : 11/11/16
Due Date : 11/22/16 11am
Description :
Use Apriori Algorithm to analyze the data from the Titanic
	Certification of Authenticity :
I certify that this is entirely my own work, except where I have given
	fully - documented references to the work of others.I understand the
	definition and consequences of plagiarism and acknowledge that the assessor
	of this assignment may, for the purpose of assessing this assignment :
	-Reproduce this assignment and provide a copy to another member of
	academic staff; and / or
	- Communicate a copy of this assignment to a plagiarism checking
	service(which may then retain a copy of this assignment on its
	database for the purpose of future plagiarism checking)
*/

#ifndef _Header_
#define _Header_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/*enum Rooming { Crew = 0, First, Second, Third, RoomTypes };

const string LivingArragnementStrings(RoomTypes) {
	"Crew", "First", "Second", "Third"
}*/

//ifstream ExcelFile("titanic.csv");
const string FileName = "titanic.csv";

int assignRooming(string);
int assignSex(string);
int assignAge(string);
int assignSurvived(string);

struct Titanic
{
	vector<int> trooming; // Crew = 0, 1st = 1, 2nd = 2, 3rd = 3
	vector<int> tsex; // Male = 0, Female = 1
	vector<int> tage; // Adult = 0, Child = 1
	vector<int> tsurvived; // No = 0, Yes = 1
};

/*struct Titanic
{
	int trooming; // Crew = 0, 1st = 1, 2nd = 2, 3rd = 3
	bool tsex; // Male = 0, Female = 1
	bool tage; // Adult = 0, Child = 1
	bool tsurvived; // No = 0, Yes = 1
};*/

#endif