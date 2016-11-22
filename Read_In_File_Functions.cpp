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

#include "Header.h"

int assignRooming(string roomIn)
{
	//int roomingType;

	if (roomIn == "Crew")
	{
		return 0;
	}
	else if (roomIn == "1st")
	{
		return 1;
	}
	else if (roomIn == "2nd")
	{
		return 2;
	}
	else if (roomIn == "3rd")
	{
		return 3;
	}
	else
	{
		return -1;
	}
}

int assignSex(string sexIn)
{
	if (sexIn == "Male")
		return 0;
	else
		return 1;
}

int assignAge(string ageIn)
{
	if (ageIn == "Adult")
		return 0;
	else
		return 1;
}

int assignSurvived(string survivedIn)
{
	if (survivedIn == "No")
		return 0;
	else
		return 1;
}
