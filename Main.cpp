#include "Header.h"

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

	cin.get();
	cin.ignore();
	
	return 0;
}