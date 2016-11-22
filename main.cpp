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
	if (ExcelFile.good()) {
		getline(ExcelFile, skipLine);
		cout << skipLine << endl;
		while (!ExcelFile.eof())
		{
			getline(ExcelFile, roomIn, ',');
			getline(ExcelFile, sexIn, ',');
			getline(ExcelFile, ageIn, ',');
			getline(ExcelFile, survivedIn);

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
	int min_support = 0; //Can have cin for defining min_support; for testing purposes, hardcode
	int support_count = 0;
	float confidence = 0.0;
	float userConfidence = 0.0;
	int j = 0;
	int k = 0;
	int rows = titanic.trooming.size();
	int columns = 2;
	
	vector<vector<int>> C2;
	C2.resize(rows, vector<int>(columns, 0)); //Resize empty vector
	
	vector<vector<int>> I1, I2, I3, I4, I5, I6, I7, I8, I9, I10, I11, I12, I13, I14, I15, I16, I17, I18, I19, I20, I21, I22, I23, I24, I25, I26, I27, I28, I29, I30, I31, I32; //32 vector<int>'s declared because we have a total of 32 combinations with 2-itemsets
	//Simplify into function || In main to ease workflow
	I1.resize(rows, vector<int>(columns, 0)); //Resize empty vector
	I2.resize(rows, vector<int>(columns, 0)); //Resize empty vector
	I3.resize(rows, vector<int>(columns, 0)); //Resize empty vector
	I4.resize(rows, vector<int>(columns, 0)); //Resize empty vector
	I5.resize(rows, vector<int>(columns, 0)); //Resize empty vector
	I6.resize(rows, vector<int>(columns, 0)); //Resize empty vector
	I7.resize(rows, vector<int>(columns, 0)); //Resize empty vector
	I8.resize(rows, vector<int>(columns, 0)); //Resize empty vector
	I9.resize(rows, vector<int>(columns, 0)); //Resize empty vector
	I10.resize(rows, vector<int>(columns, 0)); //Resize empty vector
	I11.resize(rows, vector<int>(columns, 0)); //Resize empty vector
	I12.resize(rows, vector<int>(columns, 0)); //Resize empty vector
	I13.resize(rows, vector<int>(columns, 0)); //Resize empty vector
	I14.resize(rows, vector<int>(columns, 0)); //Resize empty vector
	I15.resize(rows, vector<int>(columns, 0)); //Resize empty vector
	I16.resize(rows, vector<int>(columns, 0)); //Resize empty vector
	I17.resize(rows, vector<int>(columns, 0)); //Resize empty vector
	I18.resize(rows, vector<int>(columns, 0)); //Resize empty vector
	I19.resize(rows, vector<int>(columns, 0)); //Resize empty vector
	I20.resize(rows, vector<int>(columns, 0)); //Resize empty vector
	I21.resize(rows, vector<int>(columns, 0)); //Resize empty vector
	I22.resize(rows, vector<int>(columns, 0)); //Resize empty vector
	I23.resize(rows, vector<int>(columns, 0)); //Resize empty vector
	I24.resize(rows, vector<int>(columns, 0)); //Resize empty vector
	I25.resize(rows, vector<int>(columns, 0)); //Resize empty vector
	I26.resize(rows, vector<int>(columns, 0)); //Resize empty vector
	I27.resize(rows, vector<int>(columns, 0)); //Resize empty vector
	I28.resize(rows, vector<int>(columns, 0)); //Resize empty vector
	I29.resize(rows, vector<int>(columns, 0)); //Resize empty vector
	I30.resize(rows, vector<int>(columns, 0)); //Resize empty vector
	I31.resize(rows, vector<int>(columns, 0)); //Resize empty vector
	I32.resize(rows, vector<int>(columns, 0)); //Resize empty vector

	////////////
	//Preface://
	////////////
	cout << "Enter your desired minimum support:  ";
	cin >> min_support;

	///////////////////////
	//Manifest 2-Itemsets// || Fill Itemset, then get min_support
	///////////////////////

	//I1 - {Crew, Male}
	I1 = assembleItemSet(I1, titanic.trooming, titanic.tsex);
	I1 = pruneItemSet_crewMale(I1, rows, columns, min_support);
	cout << "\nI1 Complete\n";
	//I2 - {Crew, Female}
	I2 = assembleItemSet(I2, titanic.trooming, titanic.tsex);
	I2 = pruneItemSet_crewFemale(I2, rows, columns, min_support);
	cout << "\nI2 Complete\n";
	//I3 - {Crew, Adult}
	I3 = assembleItemSet(I3, titanic.trooming, titanic.tage);
	I3 = pruneItemSet_crewAdult(I3, rows, columns, min_support);
	cout << "\nI3 Complete\n";
	//I4 - {Crew, Child}
	I4 = assembleItemSet(I4, titanic.trooming, titanic.tage);
	I4 = pruneItemSet_crewChild(I4, rows, columns, min_support);
	cout << "\nI4 Complete\n";
	//I5 - {Crew, Survived}
	I5 = assembleItemSet(I5, titanic.trooming, titanic.tsurvived);
	I5 = pruneItemSet_crewSurvived(I5, rows, columns, min_support);
	cout << "\nI5 Complete\n";
	//I6 - {Crew, Dead}
	I6 = assembleItemSet(I6, titanic.trooming, titanic.tsurvived);
	I6 = pruneItemSet_crewDead(I6, rows, columns, min_support);
	cout << "\nI6 Complete\n";
	//I7 - {1st, Male}
	I7 = assembleItemSet(I7, titanic.trooming, titanic.tsex);
	I7 = pruneItemSet_1stMale(I7, rows, columns, min_support);
	cout << "\nI7 Complete\n";
	//I8 - {1st, Female}
	I8 = assembleItemSet(I8, titanic.trooming, titanic.tsex);
	I8 = pruneItemSet_1stFemale(I8, rows, columns, min_support);
	cout << "\nI8 Complete\n";
	//I9 - {1st, Adult}
	I9 = assembleItemSet(I9, titanic.trooming, titanic.tage);
	I9 = pruneItemSet_1stAdult(I9, rows, columns, min_support);
	cout << "\nI9 Complete\n";
	//I10 - {1st, Child}
	I10 = assembleItemSet(I10, titanic.trooming, titanic.tage);
	I10 = pruneItemSet_1stChild(I10, rows, columns, min_support);
	cout << "\nI10 Complete\n";
	//I11 - {1st, Survived}
	I11 = assembleItemSet(I11, titanic.trooming, titanic.tsurvived);
	I11 = pruneItemSet_1stSurvived(I11, rows, columns, min_support);
	cout << "\nI11 Complete\n";
	//I12 - {1st, Dead}
	I12 = assembleItemSet(I12, titanic.trooming, titanic.tsurvived);
	I12 = pruneItemSet_1stDead(I12, rows, columns, min_support);
	cout << "\nI12 Complete\n";
	//I13 {2nd, Male}
	I13 = assembleItemSet(I13, titanic.trooming, titanic.tsex);
	I13 = pruneItemSet_2ndMale(I13, rows, columns, min_support);
	cout << "\nI13 Complete\n";
	//I14 {2nd, Female}
	I14 = assembleItemSet(I14, titanic.trooming, titanic.tsex);
	I14 = pruneItemSet_2ndFemale(I14, rows, columns, min_support);
	cout << "\nI14 Complete\n";
	//I15 {2nd, Adult}
	I15 = assembleItemSet(I15, titanic.trooming, titanic.tage);
	I15 = pruneItemSet_2ndAdult(I15, rows, columns, min_support);
	cout << "\nI15 Complete\n";
	//I16 {2nd, Child}
	I16 = assembleItemSet(I16, titanic.trooming, titanic.tage);
	I16 = pruneItemSet_2ndChild(I16, rows, columns, min_support);
	cout << "\nI16 Complete\n";
	//I17 {2nd, Survived}
	I17 = assembleItemSet(I17, titanic.trooming, titanic.tsurvived);
	I17 = pruneItemSet_2ndSurvived(I17, rows, columns, min_support);
	cout << "\nI17 Complete\n";
	//I18 {2nd, Dead}
	I18 = assembleItemSet(I18, titanic.trooming, titanic.tsurvived);
	I18 = pruneItemSet_2ndDead(I18, rows, columns, min_support);
	cout << "\nI18 Complete\n";
	//I19 {3rd, Male}
	I19 = assembleItemSet(I19, titanic.trooming, titanic.tsex);
	I19 = pruneItemSet_3rdMale(I19, rows, columns, min_support);
	cout << "\nI19 Complete\n";
	//I20 {3rd, Female}
	I20 = assembleItemSet(I20, titanic.trooming, titanic.tsex);
	I20 = pruneItemSet_3rdFemale(I20, rows, columns, min_support);
	cout << "\nI20 Complete\n";
	//I21 {3rd, Adult}
	I21 = assembleItemSet(I21, titanic.trooming, titanic.tage);
	I21 = pruneItemSet_3rdAdult(I21, rows, columns, min_support);
	cout << "\nI21 Complete\n";
	//I22 {3rd, Child}
	I22 = assembleItemSet(I22, titanic.trooming, titanic.tage);
	I22 = pruneItemSet_3rdChild(I22, rows, columns, min_support);
	cout << "\nI22 Complete\n";
	//I23 {3rd, Survived}
	I23 = assembleItemSet(I23, titanic.trooming, titanic.tsurvived);
	I23 = pruneItemSet_3rdSurvived(I23, rows, columns, min_support);
	cout << "\nI23 Complete\n";
	//I24 {3rd, Dead}
	I24 = assembleItemSet(I24, titanic.trooming, titanic.tsurvived);
	I24 = pruneItemSet_3rdDead(I24, rows, columns, min_support);
	cout << "\nI24 Complete\n";
	//I25 {Survived, Male}
	I25 = assembleItemSet(I25, titanic.tsurvived, titanic.tsex);
	I25 = pruneItemSet_survivedMale(I25, rows, columns, min_support);
	cout << "\nI25 Complete\n";
	//I26 {Survived, Female}
	I26 = assembleItemSet(I26, titanic.tsurvived, titanic.tsex);
	I26 = pruneItemSet_survivedFemale(I26, rows, columns, min_support);
	cout << "\nI26 Complete\n";
	//I27 {Survived, Adult}
	I27 = assembleItemSet(I27, titanic.tsurvived, titanic.tage);
	I27 = pruneItemSet_survivedAdult(I27, rows, columns, min_support);
	cout << "\nI27 Complete\n";
	//I28 {Survived, Child}
	I28 = assembleItemSet(I28, titanic.tsurvived, titanic.tage);
	I28 = pruneItemSet_survivedChild(I28, rows, columns, min_support);
	cout << "\nI28 Complete\n";
	//I29 {Dead, Male}
	I29 = assembleItemSet(I29, titanic.tsurvived, titanic.tsex);
	I29 = pruneItemSet_deadMale(I29, rows, columns, min_support);
	cout << "\nI29 Complete\n";
	//I30 {Dead, Female}
	I30 = assembleItemSet(I30, titanic.tsurvived, titanic.tsex);
	I30 = pruneItemSet_deadFemale(I30, rows, columns, min_support);
	cout << "\nI30 Complete\n";
	//I31 {Dead, Adult}
	I31 = assembleItemSet(I31, titanic.tsurvived, titanic.tage);
	I31 = pruneItemSet_deadAdult(I31, rows, columns, min_support);
	cout << "\nI31 Complete\n";
	//I32 {Dead, Child}
	I32 = assembleItemSet(I32, titanic.tsurvived, titanic.tage);
	I32 = pruneItemSet_deadChild(I32, rows, columns, min_support);
	cout << "\nI32 Complete\n";


	//Create F1 - F32 for Frequent-Itemsets || F1 = pruneItemSet_etc?
	confidence = 0;
	float antecedent = 0.0;
	float consequent = 0.0;
	
	cout << "\n\nEnter minimum confidence percentage (# between 0 & 100): ";
	cin >> userConfidence;
	userConfidence /= 100;

	//Confidence {Crew, Male}
	confidence = getConfidence_crewMale(confidence, antecedent, consequent, I1);
	if(confidence < userConfidence)
	{
		I1.clear();
		cout << "\n{Crew, Male} itemset does not exceed minimum confidence, removing..." << endl;
	}
	
	//Confidence {Crew, Female}
	confidence = getConfidence_crewFemale(confidence, antecedent, consequent, I2);
	if(confidence < userConfidence)
	{
		I2.clear();
		cout << "\n{Crew, Female} itemset does not exceed minimum confidence, removing..." << endl;
	}
		
	//Confidence {Crew, Adult}
	confidence = getConfidence_crewAdult(confidence, antecedent, consequent, I3);
	if(confidence < userConfidence)
	{
		I3.clear();
		cout << "\n{Crew, Adult} itemset does not exceed minimum confidence, removing..." << endl;
	}
	
	//Confidence {Crew, Child}
	confidence = getConfidence_crewChild(confidence, antecedent, consequent, I4);
	if(confidence < userConfidence)
	{
		I4.clear();
		cout << "\n{Crew, Child} itemset does not exceed minimum confidence, removing..." << endl;
	}
		
	//Confidence {Crew, Survived}
	confidence = getConfidence_crewSurvived(confidence, antecedent, consequent, I5);
	if(confidence < userConfidence)
	{
		I5.clear();
		cout << "\n{Crew, Survived} itemset does not exceed minimum confidence, removing..." << endl;
	}
			
	//Confidence {Crew, Dead}
	confidence = getConfidence_crewDead(confidence, antecedent, consequent, I6);
	if(confidence < userConfidence)
	{
		I6.clear();
		cout << "\n{Crew, Dead} itemset does not exceed minimum confidence, removing..." << endl;
	}

	//Confidence {1st, Male}
	confidence = getConfidence_1stMale(confidence, antecedent, consequent, I7);
	if(confidence < userConfidence)
	{
		I7.clear();
		cout << "\n{1st, Male} itemset does not exceed minimum confidence, removing..." << endl;
	}
	
	//Confidence {1st, Female}
	confidence = getConfidence_1stFemale(confidence, antecedent, consequent, I8);
	if(confidence < userConfidence)
	{
		I8.clear();
		cout << "\n{1st, Female} itemset does not exceed minimum confidence, removing..." << endl;
	}
		
	//Confidence {1st, Adult}
	confidence = getConfidence_1stAdult(confidence, antecedent, consequent, I9);
	if(confidence < userConfidence)
	{
		I9.clear();
		cout << "\n{1st, Adult} itemset does not exceed minimum confidence, removing..." << endl;
	}
	
	//Confidence {1st, Child}
	confidence = getConfidence_1stChild(confidence, antecedent, consequent, I10);
	if(confidence < userConfidence)
	{
		I10.clear();
		cout << "\n{1st, Child} itemset does not exceed minimum confidence, removing..." << endl;
	}
		
	//Confidence {1st, Survived}
	confidence = getConfidence_1stSurvived(confidence, antecedent, consequent, I11);
	if(confidence < userConfidence)
	{
		I11.clear();
		cout << "\n{1st, Survived} itemset does not exceed minimum confidence, removing..." << endl;
	}
			
	//Confidence {1st, Dead}
	confidence = getConfidence_1stDead(confidence, antecedent, consequent, I12);
	if(confidence < userConfidence)
	{
		I12.clear();
		cout << "\n{1st, Dead} itemset does not exceed minimum confidence, removing..." << endl;
	}

	//Confidence {2nd, Male}
	confidence = getConfidence_2ndMale(confidence, antecedent, consequent, I13);
	if(confidence < userConfidence)
	{
		I13.clear();
		cout << "\n{2nd, Male} itemset does not exceed minimum confidence, removing..." << endl;
	}
	
	//Confidence {2nd, Female}
	confidence = getConfidence_2ndFemale(confidence, antecedent, consequent, I14);
	if(confidence < userConfidence)
	{
		I14.clear();
		cout << "\n{2nd, Female} itemset does not exceed minimum confidence, removing..." << endl;
	}
		
	//Confidence {2nd, Adult}
	confidence = getConfidence_2ndAdult(confidence, antecedent, consequent, I15);
	if(confidence < userConfidence)
	{
		I15.clear();
		cout << "\n{2nd, Adult} itemset does not exceed minimum confidence, removing..." << endl;
	}
	
	//Confidence {2nd, Child}
	confidence = getConfidence_2ndChild(confidence, antecedent, consequent, I16);
	if(confidence < userConfidence)
	{
		I16.clear();
		cout << "\n{2nd, Child} itemset does not exceed minimum confidence, removing..." << endl;
	}
		
	//Confidence {2nd, Survived}
	confidence = getConfidence_2ndSurvived(confidence, antecedent, consequent, I17);
	if(confidence < userConfidence)
	{
		I17.clear();
		cout << "\n{2nd, Survived} itemset does not exceed minimum confidence, removing..." << endl;
	}
			
	//Confidence {2nd, Dead}
	confidence = getConfidence_2ndDead(confidence, antecedent, consequent, I18);
	if(confidence < userConfidence)
	{
		I18.clear();
		cout << "\n{2nd, Dead} itemset does not exceed minimum confidence, removing..." << endl;
	}

	//Confidence {3rd, Male}
	confidence = getConfidence_3rdMale(confidence, antecedent, consequent, I19);
	if(confidence < userConfidence)
	{
		I19.clear();
		cout << "\n{3rd, Male} itemset does not exceed minimum confidence, removing..." << endl;
	}
	
	//Confidence {3rd, Female}
	confidence = getConfidence_3rdFemale(confidence, antecedent, consequent, I20);
	if(confidence < userConfidence)
	{
		I20.clear();
		cout << "\n{3rd, Female} itemset does not exceed minimum confidence, removing..." << endl;
	}
		
	//Confidence {3rd, Adult}
	confidence = getConfidence_3rdAdult(confidence, antecedent, consequent, I21);
	if(confidence < userConfidence)
	{
		I21.clear();
		cout << "\n{3rd, Adult} itemset does not exceed minimum confidence, removing..." << endl;
	}
	
	//Confidence {3rd, Child}
	confidence = getConfidence_3rdChild(confidence, antecedent, consequent, I22);
	if(confidence < userConfidence)
	{
		I22.clear();
		cout << "\n{3rd, Child} itemset does not exceed minimum confidence, removing..." << endl;
	}
		
	//Confidence {3rd, Survived}
	confidence = getConfidence_3rdSurvived(confidence, antecedent, consequent, I23);
	if(confidence < userConfidence)
	{
		I23.clear();
		cout << "\n{3rd, Survived} itemset does not exceed minimum confidence, removing..." << endl;
	}
			
	//Confidence {3rd, Dead}
	confidence = getConfidence_3rdDead(confidence, antecedent, consequent, I24);
	if(confidence < userConfidence)
	{
		I24.clear();
		cout << "\n{3rd, Dead} itemset does not exceed minimum confidence, removing..." << endl;
	}
				
	//Confidence {Survived, Male}
	confidence = getConfidence_survivedMale(confidence, antecedent, consequent, I25);
	if(confidence < userConfidence)
	{
		I25.clear();
		cout << "\n{Survived, Male} itemset does not exceed minimum confidence, removing..." << endl;
	}
				
	//Confidence {Survived, Female}
	confidence = getConfidence_survivedFemale(confidence, antecedent, consequent, I26);
	if(confidence < userConfidence)
	{
		I26.clear();
		cout << "\n{Survived, Female} itemset does not exceed minimum confidence, removing..." << endl;
	}
				
	//Confidence {Survived, Adult}
	confidence = getConfidence_survivedAdult(confidence, antecedent, consequent, I27);
	if(confidence < userConfidence)
	{
		I27.clear();
		cout << "\n{Survived, Adult} itemset does not exceed minimum confidence, removing..." << endl;
	}
					
	//Confidence {Survived, Child}
	confidence = getConfidence_survivedChild(confidence, antecedent, consequent, I28);
	if(confidence < userConfidence)
	{
		I28.clear();
		cout << "\n{Survived, Child} itemset does not exceed minimum confidence, removing..." << endl;
	}
				
	//Confidence {Dead, Male}
	confidence = getConfidence_deadMale(confidence, antecedent, consequent, I29);
	if(confidence < userConfidence)
	{
		I29.clear();
		cout << "\n{Dead, Male} itemset does not exceed minimum confidence, removing..." << endl;
	}
				
	//Confidence {Dead, Female}
	confidence = getConfidence_deadFemale(confidence, antecedent, consequent, I30);
	if(confidence < userConfidence)
	{
		I30.clear();
		cout << "\n{Dead, Female} itemset does not exceed minimum confidence, removing..." << endl;
	}
				
	//Confidence {Dead, Adult}
	confidence = getConfidence_deadAdult(confidence, antecedent, consequent, I31);
	if(confidence < userConfidence)
	{
		I31.clear();
		cout << "\n{Dead, Adult} itemset does not exceed minimum confidence, removing..." << endl;
	}
					
	//Confidence {Dead, Child}
	confidence = getConfidence_deadChild(confidence, antecedent, consequent, I32);
	if(confidence < userConfidence)
	{
		I32.clear();
		cout << "\n{Dead, Child} itemset does not exceed minimum confidence, removing..." << endl;
	}

	cin.get();
	cin.ignore();
	
	return 0;
}