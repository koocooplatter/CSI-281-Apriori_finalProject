#include "Header.h"
#include "apriori.h"

int main()
{
	string roomIn, sexIn, ageIn, survivedIn, skipLine;
	int i = 0;
	int rooming;
	bool sex, age, survived;
	Titanic titanic;
	ifstream ExcelFile(FileName);

	// check if file is open
	if (ExcelFile.good()){
		getline(ExcelFile, skipLine);
		cout << skipLine << endl;
		while (!ExcelFile.eof())
		{
			getline(ExcelFile, roomIn, ',');
			getline(ExcelFile, sexIn, ',');
			getline(ExcelFile, ageIn, ',');
			getline(ExcelFile, survivedIn);

			/*cout << roomIn << ":";
			cout << sexIn << ":";
			cout << ageIn << ":";
			cout << survivedIn << ":" << endl;*/

			/*cout << assignRooming(roomIn) << ":";
			cout << assignSex(sexIn) << ":";
			cout << assignAge(ageIn) << ":";
			cout << assignSurvived(survivedIn) << ":" << endl;*/

			/*rooming = assignRooming(roomIn);
			sex = assignSex(sexIn);
			age = assignAge(ageIn);
			survived = assignSurvived(survivedIn);*/

			/*cout << rooming << ":";
			cout << sex << ":";
			cout << age << ":";
			cout << survived << ":" << endl;*/

			titanic.trooming.push_back(assignRooming(roomIn));
			titanic.tsex.push_back(assignSex(sexIn));
			titanic.tage.push_back(assignAge(ageIn));
			titanic.tsurvived.push_back(assignSurvived(survivedIn));

			i++;
		}
	}
	cout << "people on the ship: " << i << endl;

	cout << "1526:" << titanic.trooming[1526] << ":" << titanic.tsex[1526] << ":" << titanic.tage[1526] << ":" << titanic.tsurvived[1526] << ":" << endl;
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/*Apriori Testing*/
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	int min_support = 10; //Can have cin for defining min_support; for testing purposes, hardcode
	int confidence;
	int j = 0;
	int k = 0;
	int rows = 2201;
	int columns = 2;
	vector<vector<int>> C1/*, C2, C3, C4, C5, C6, C7, C8, C9, C10, C11, C12, C13, C14*/; //14 vector<int>'s declared because we have a total of 14 combinations with 2-itemsets
	C1.resize(rows, vector<int>(columns, 0)); //Resize empty vector

	//Compare itemsets (Class & Sex) || Eventually place this in seperate function
	for(j = 0; j < i; j++)
	{
		C1[j][k] = titanic.trooming[j]; //Place Passenger class data in first column of C1
	}
	k++;
	for(j = 0; j < i; j++)
	{
		C1[j][k] = titanic.tsex[j]; //Place gender data in second colum of C1
	}								// C1[35][1] =  3 (3rd class) || C1[35][2] = 0 (Male)
	  								// C1[36][1] =  3 (3rd class) || C1[36][2] = 1 (Female)


	cin.get();
	cin.ignore();
	
	return 0;
}