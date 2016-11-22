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

#ifndef __APRIORI__H__
#define __APRIORI__H__

#include "Header.h"
//////////////////////
//Function Prototype//
//////////////////////
//Assembler
vector<vector<int>> assembleItemSet(vector<vector<int>>, vector<int>, vector<int>);
//Pruner
vector<vector<int>> pruneItemSet_crewMale(vector<vector<int>>, int, int, int);
vector<vector<int>> pruneItemSet_crewFemale(vector<vector<int>>, int, int, int);
vector<vector<int>> pruneItemSet_crewAdult(vector<vector<int>>, int, int, int);
vector<vector<int>> pruneItemSet_crewChild(vector<vector<int>>, int, int, int);
vector<vector<int>> pruneItemSet_crewSurvived(vector<vector<int>>, int, int, int);
vector<vector<int>> pruneItemSet_crewDead(vector<vector<int>>, int, int, int);
vector<vector<int>> pruneItemSet_1stMale(vector<vector<int>>, int, int, int);
vector<vector<int>> pruneItemSet_1stFemale(vector<vector<int>>, int, int, int);
vector<vector<int>> pruneItemSet_1stAdult(vector<vector<int>>, int, int, int);
vector<vector<int>> pruneItemSet_1stChild(vector<vector<int>>, int, int, int);
vector<vector<int>> pruneItemSet_1stSurvived(vector<vector<int>>, int, int, int);
vector<vector<int>> pruneItemSet_1stDead(vector<vector<int>>, int, int, int);
vector<vector<int>> pruneItemSet_2ndMale(vector<vector<int>>, int, int, int);
vector<vector<int>> pruneItemSet_2ndFemale(vector<vector<int>>, int, int, int);
vector<vector<int>> pruneItemSet_2ndAdult(vector<vector<int>>, int, int, int);
vector<vector<int>> pruneItemSet_2ndChild(vector<vector<int>>, int, int, int);
vector<vector<int>> pruneItemSet_2ndSurvived(vector<vector<int>>, int, int, int);
vector<vector<int>> pruneItemSet_2ndDead(vector<vector<int>>, int, int, int);
vector<vector<int>> pruneItemSet_3rdMale(vector<vector<int>>, int, int, int);
vector<vector<int>> pruneItemSet_3rdFemale(vector<vector<int>>, int, int, int);
vector<vector<int>> pruneItemSet_3rdAdult(vector<vector<int>>, int, int, int);
vector<vector<int>> pruneItemSet_3rdChild(vector<vector<int>>, int, int, int);
vector<vector<int>> pruneItemSet_3rdSurvived(vector<vector<int>>, int, int, int);
vector<vector<int>> pruneItemSet_3rdDead(vector<vector<int>>, int, int, int);
vector<vector<int>> pruneItemSet_survivedMale(vector<vector<int>>, int, int, int);
vector<vector<int>> pruneItemSet_survivedFemale(vector<vector<int>>, int, int, int);
vector<vector<int>> pruneItemSet_survivedAdult(vector<vector<int>>, int, int, int);
vector<vector<int>> pruneItemSet_survivedChild(vector<vector<int>>, int, int, int);
vector<vector<int>> pruneItemSet_deadMale(vector<vector<int>>, int, int, int);
vector<vector<int>> pruneItemSet_deadFemale(vector<vector<int>>, int, int, int);
vector<vector<int>> pruneItemSet_deadAdult(vector<vector<int>>, int, int, int);
vector<vector<int>> pruneItemSet_deadChild(vector<vector<int>>, int, int, int);
//Confidence
float getConfidence_crewMale(float, float, float, vector<vector<int>>);
float getConfidence_crewFemale(float, float, float, vector<vector<int>>);
float getConfidence_crewAdult(float, float, float, vector<vector<int>>);
float getConfidence_crewChild(float, float, float, vector<vector<int>>);
float getConfidence_crewSurvived(float, float, float, vector<vector<int>>);
float getConfidence_crewDead(float, float, float, vector<vector<int>>);
float getConfidence_1stMale(float, float, float, vector<vector<int>>);
float getConfidence_1stFemale(float, float, float, vector<vector<int>>);
float getConfidence_1stAdult(float, float, float, vector<vector<int>>);
float getConfidence_1stChild(float, float, float, vector<vector<int>>);
float getConfidence_1stSurvived(float, float, float, vector<vector<int>>);
float getConfidence_1stDead(float, float, float, vector<vector<int>>);
float getConfidence_2ndMale(float, float, float, vector<vector<int>>);
float getConfidence_2ndFemale(float, float, float, vector<vector<int>>);
float getConfidence_2ndAdult(float, float, float, vector<vector<int>>);
float getConfidence_2ndChild(float, float, float, vector<vector<int>>);
float getConfidence_2ndSurvived(float, float, float, vector<vector<int>>);
float getConfidence_2ndDead(float, float, float, vector<vector<int>>);
float getConfidence_3rdMale(float, float, float, vector<vector<int>>);
float getConfidence_3rdFemale(float, float, float, vector<vector<int>>);
float getConfidence_3rdAdult(float, float, float, vector<vector<int>>);
float getConfidence_3rdChild(float, float, float, vector<vector<int>>);
float getConfidence_3rdSurvived(float, float, float, vector<vector<int>>);
float getConfidence_3rdDead(float, float, float, vector<vector<int>>);
float getConfidence_survivedMale(float, float, float, vector<vector<int>>);
float getConfidence_survivedFemale(float, float, float, vector<vector<int>>);
float getConfidence_survivedAdult(float, float, float, vector<vector<int>>);
float getConfidence_survivedChild(float, float, float, vector<vector<int>>);
float getConfidence_deadMale(float, float, float, vector<vector<int>>);
float getConfidence_deadFemale(float, float, float, vector<vector<int>>);
float getConfidence_deadAdult(float, float, float, vector<vector<int>>);
float getConfidence_deadChild(float, float, float, vector<vector<int>>);

#endif//__APRIORI__H__