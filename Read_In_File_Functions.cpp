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
