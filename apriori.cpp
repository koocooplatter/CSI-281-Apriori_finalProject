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
#include "apriori.h"

//////////////////////
///Assemble Function//
//////////////////////
vector<vector<int>> assembleItemSet(vector<vector<int>> I_, vector<int> data1, vector<int> data2)
{
	int j = 0;
	//Fill itemsets
	for(j = 0; j < data1.size(); j++)
	{
		I_[j][0] = data1[j]; //Fill first column
		I_[j][1] = data2[j]; //Fill second column || Creates 2-itemset
	}

	return I_;
}

///////////////////
//Prune Functions//
///////////////////

//Crew :: Male
vector<vector<int>> pruneItemSet_crewMale(vector<vector<int>> I1, int rows, int columns, int min_support)
{
	int j = 0;
	int C2_supportCount_crewMale = 0;
	vector<vector<int>> I1_temp;
	I1_temp.resize(rows, vector<int>(columns, 0));
	I1_temp = I1;
	I1.clear();
	I1.resize(rows, vector<int>(columns, 0));

	//if Crew & Male, add to crewMale support count
	for(j = 0; j < I1_temp.size(); j++)
	{
		if(I1_temp[j][0] == 0 && I1_temp[j][1] == 0)
		{
			C2_supportCount_crewMale++;
		}
	}

	if(C2_supportCount_crewMale >= min_support)
	{
		//Prune itemsets (Crew & Male) || Fill I1 with ONLY Crew & Male
		for(j = 0; j < I1_temp.size(); j++)
		{
			if(I1_temp[j][0] == 0 && I1_temp[j][1] == 0)//if data = Crew class & Male, prune data & merge into I1
			{
				int i = 0;
				I1[i][0] = I1_temp[j][0];
				I1[i][1] = I1_temp[j][1];
				i++;
			}
		}
	}
	else
	{
		cout << "\n{Crew, Male} itemset does not exceed minimum support, ignoring..." << endl;
		I1.clear();
	}

	return I1;
}

//Crew :: Female
vector<vector<int>> pruneItemSet_crewFemale(vector<vector<int>> I2, int rows, int columns, int min_support)
{
	int j = 0;
	int C2_supportCount_crewFemale = 0;
	vector<vector<int>> I2_temp;
	I2_temp.resize(rows, vector<int>(columns, 0));
	I2_temp = I2;
	I2.clear();
	I2.resize(rows, vector<int>(columns, 0));

	//if Crew & Female, add to crewFemale support count
	for(j = 0; j < I2_temp.size(); j++)
	{
		if(I2_temp[j][0] == 0 && I2_temp[j][1] == 1)
		{
			C2_supportCount_crewFemale++;
		}
	}

	if(C2_supportCount_crewFemale >= min_support)
	{
		//Prune itemsets (Crew & Female) || Fill I2 with ONLY Crew & Female
		for(j = 0; j < I2_temp.size(); j++)
		{
			if(I2_temp[j][0] == 0 && I2_temp[j][1] == 1)//if data = Crew class & Female, prune data & merge into I2
			{
				int i = 0;
				I2[i][0] = I2_temp[j][0];
				I2[i][1] = I2_temp[j][1];
				i++;
			}
		}
	}
	else
	{
		cout << "\n{Crew, Female} itemset does not exceed minimum support, ignoring..." << endl;
		I2.clear();
	}

	return I2;
}

//Crew :: Adult
vector<vector<int>> pruneItemSet_crewAdult(vector<vector<int>> I3, int rows, int columns, int min_support)
{
	int j = 0;
	int C2_supportCount_crewAdult = 0;
	vector<vector<int>> I3_temp;
	I3_temp.resize(rows, vector<int>(columns, 0));
	I3_temp = I3;
	I3.clear();
	I3.resize(rows, vector<int>(columns, 0));

	//if Crew & Adult, add to crewAdult support count
	for (j = 0; j < I3_temp.size(); j++)
	{
		if (I3_temp[j][0] == 0 && I3_temp[j][1] == 0)
		{
			C2_supportCount_crewAdult++;
		}
	}

	if(C2_supportCount_crewAdult >= min_support)
	{
		//Prune itemsets (Crew & Adult) || Fill I3 with ONLY Crew & Adult
		for(j = 0; j < I3_temp.size(); j++)
		{
			if(I3_temp[j][0] == 0 && I3_temp[j][1] == 0)//if data = Crew class & Adult, prune data & merge into I3
			{
				int i = 0;
				I3[i][0] = I3_temp[j][0];
				I3[i][1] = I3_temp[j][1];
				i++;
			}
		}
	}
	else
	{
		cout << "\n{Crew, Adult} itemset does not exceed minimum support, ignoring..." << endl;
	}

	return I3;
}

//Crew :: Child
vector<vector<int>> pruneItemSet_crewChild(vector<vector<int>> I4, int rows, int columns, int min_support)
{
	int j = 0;
	int C2_supportCount_crewChild = 0;
	vector<vector<int>> I4_temp;
	I4_temp.resize(rows, vector<int>(columns, 0));
	I4_temp = I4;
	I4.clear();
	I4.resize(rows, vector<int>(columns, 0));

	//if Crew & Child, add to crewChild support count
	for (j = 0; j < I4_temp.size(); j++)
	{
		if (I4_temp[j][0] == 0 && I4_temp[j][1] == 1)
		{
			C2_supportCount_crewChild++;
		}
	}

	if(C2_supportCount_crewChild >= min_support)
	{
		//Prune itemsets (Crew & Child) || Fill I4 with ONLY Crew & Child
		for(j = 0; j < I4_temp.size(); j++)
		{
			if(I4_temp[j][0] == 0 && I4_temp[j][1] == 1)//if data = Crew class & Child, prune data & merge into I4
			{
				int i = 0;
				I4[i][0] = I4_temp[j][0];
				I4[i][1] = I4_temp[j][1];
				i++;
			}
		}
	}
	else
	{
		cout << "\n{Crew, Child} itemset does not exceed minimum support, ignoring..." << endl;
	}

	return I4;
}

//Crew :: Survived
vector<vector<int>> pruneItemSet_crewSurvived(vector<vector<int>> I5, int rows, int columns, int min_support)
{
	int j = 0;
	int C2_supportCount_crewSurvived = 0;
	vector<vector<int>> I5_temp;
	I5_temp.resize(rows, vector<int>(columns, 0));
	I5_temp = I5;
	I5.clear();
	I5.resize(rows, vector<int>(columns, 0));
	
	//if Crew & Survived, add to crewSurvived support count
	for (j = 0; j < I5_temp.size(); j++)
	{
		if (I5_temp[j][0] == 0 && I5_temp[j][1] == 1)
		{
			C2_supportCount_crewSurvived++;
		}
	}

	if(C2_supportCount_crewSurvived >= min_support)
	{
		//Prune itemsets (Crew & Survived) || Fill I5 with ONLY Crew & Survived
		for(j = 0; j < I5_temp.size(); j++)
		{
			if(I5_temp[j][0] == 0 && I5_temp[j][1] == 1)//if data = Crew class & Survived, prune data & merge into I5
			{
				int i = 0;
				I5[i][0] = I5_temp[j][0];
				I5[i][1] = I5_temp[j][1];
				i++;
			}
		}
	}
	else
	{
		cout << "\n{Crew, Survived} itemset does not exceed minimum support, ignoring..." << endl;
	}

	return I5;
}

//Crew :: Dead
vector<vector<int>> pruneItemSet_crewDead(vector<vector<int>> I6, int rows, int columns, int min_support)
{
	int j = 0;
	int C2_supportCount_crewDead = 0;
	vector<vector<int>> I6_temp;
	I6_temp.resize(rows, vector<int>(columns, 0));
	I6_temp = I6;
	I6.clear();
	I6.resize(rows, vector<int>(columns, 0));

	//if Crew & Dead, add to crewDead support count
	for (j = 0; j < I6_temp.size(); j++)
	{
		if (I6_temp[j][0] == 0 && I6_temp[j][1] == 0)
		{
			C2_supportCount_crewDead++;
		}
	}

	if(C2_supportCount_crewDead >= min_support)
	{
		//Prune itemsets (Crew & Dead) || Fill I6 with ONLY Crew & Dead
		for(j = 0; j < I6_temp.size(); j++)
		{
			if(I6_temp[j][0] == 0 && I6_temp[j][1] == 1)//if data = Crew class & Dead, prune data & merge into I6
			{
				int i = 0;
				I6[i][0] = I6_temp[j][0];
				I6[i][1] = I6_temp[j][1];
				i++;
			}
		}
	}
	else
	{
		cout << "\n{Crew, Dead} itemset does not exceed minimum support, ignoring..." << endl;
	}

	return I6;
}

//1st :: Male
vector<vector<int>> pruneItemSet_1stMale(vector<vector<int>> I7, int rows, int columns, int min_support)
{
	int j = 0;
	int C2_supportCount_1stMale = 0;
	vector<vector<int>> I7_temp;
	I7_temp.resize(rows, vector<int>(columns, 0));
	I7_temp = I7;
	I7.clear();
	I7.resize(rows, vector<int>(columns, 0));

	//if 1st & Male, add to 1stMale support count
	for (j = 0; j < I7_temp.size(); j++)
	{
		if (I7_temp[j][0] == 1 && I7_temp[j][1] == 0)
		{
			C2_supportCount_1stMale++;
		}
	}

	if(C2_supportCount_1stMale >= min_support)
	{
		//Prune itemsets (1st & Male) || Fill I7 with ONLY 1st & Male
		for(j = 0; j < I7_temp.size(); j++)
		{
			if(I7_temp[j][0] == 1 && I7_temp[j][1] == 0)//if data = 1st class & Male, prune data & merge into I7
			{
				int i = 0;
				I7[i][0] = I7_temp[j][0];
				I7[i][1] = I7_temp[j][1];
				i++;
			}
		}
	}
	else
	{
		cout << "\n{1st, Male} itemset does not exceed minimum support, ignoring..." << endl;
	}

	return I7;
}

//1st :: Female
vector<vector<int>> pruneItemSet_1stFemale(vector<vector<int>> I8, int rows, int columns, int min_support)
{
	int j = 0;
	int C2_supportCount_1stFemale = 0;
	vector<vector<int>> I8_temp;
	I8_temp.resize(rows, vector<int>(columns, 0));
	I8_temp = I8;
	I8.clear();
	I8.resize(rows, vector<int>(columns, 0));

	//if 1st & Female, add to 1stFemale support count
	for (j = 0; j < I8_temp.size(); j++)
	{
		if (I8_temp[j][0] == 1 && I8_temp[j][1] == 1)
		{
			C2_supportCount_1stFemale++;
		}
	}

	if(C2_supportCount_1stFemale >= min_support)
	{
		//Prune itemsets (1st & Female) || Fill I8 with ONLY 1st & Female
		for(j = 0; j < I8_temp.size(); j++)
		{
			if(I8_temp[j][0] == 1 && I8_temp[j][1] == 1)//if data = 1st class & Female, prune data & merge into I8
			{
				int i = 0;
				I8[i][0] = I8_temp[j][0];
				I8[i][1] = I8_temp[j][1];
				i++;
			}
		}
	}
	else
	{
		cout << "\n{1st, Female} itemset does not exceed minimum support, ignoring..." << endl;
	}

	return I8;
}

//1st :: Adult
vector<vector<int>> pruneItemSet_1stAdult(vector<vector<int>> I9, int rows, int columns, int min_support)
{
	int j = 0;
	int C2_supportCount_1stAdult = 0;
	vector<vector<int>> I9_temp;
	I9_temp.resize(rows, vector<int>(columns, 0));
	I9_temp = I9;
	I9.clear();
	I9.resize(rows, vector<int>(columns, 0));
	
	//if 1st & Adult, add to 1stAdult support count
	for (j = 0; j < I9_temp.size(); j++)
	{
		if (I9_temp[j][0] == 1 && I9_temp[j][1] == 0)
		{
			C2_supportCount_1stAdult++;
		}
	}

	if(C2_supportCount_1stAdult >= min_support)
	{
		//Prune itemsets (1st & Adult) || Fill I9 with ONLY 1st & Adult
		for(j = 0; j < I9_temp.size(); j++)
		{
			if(I9_temp[j][0] == 1 && I9_temp[j][1] == 0)//if data = 1st class & Adult, prune data & merge into I9
			{
				int i = 0;
				I9[i][0] = I9_temp[j][0];
				I9[i][1] = I9_temp[j][1];
				i++;
			}
		}
	}
	else
	{
		cout << "\n{1st, Adult} itemset does not exceed minimum support, ignoring..." << endl;
	}

	return I9;
}

//1st :: Child
vector<vector<int>> pruneItemSet_1stChild(vector<vector<int>> I10, int rows, int columns, int min_support)
{
	int j = 0;
	int C2_supportCount_1stChild = 0;
	vector<vector<int>> I10_temp;
	I10_temp.resize(rows, vector<int>(columns, 0));
	I10_temp = I10;
	I10.clear();
	I10.resize(rows, vector<int>(columns, 0));
	
	//if 1st & Child, add to 1stChild support count
	for (j = 0; j < I10_temp.size(); j++)
	{
		if (I10_temp[j][0] == 1 && I10_temp[j][1] == 1)
		{
			C2_supportCount_1stChild++;
		}
	}

	if(C2_supportCount_1stChild >= min_support)
	{
		//Prune itemsets (1st & Child) || Fill I10 with ONLY 1st & Child
		for(j = 0; j < I10_temp.size(); j++)
		{
			if(I10_temp[j][0] == 1 && I10_temp[j][1] == 1)//if data = 1st class & Child, prune data & merge into I10
			{
				int i = 0;
				I10[i][0] = I10_temp[j][0];
				I10[i][1] = I10_temp[j][1];
				i++;
			}
		}
	}
	else
	{
		cout << "\n{1st, Child} itemset does not exceed minimum support, ignoring..." << endl;
	}

	return I10;
}

//1st :: Survived
vector<vector<int>> pruneItemSet_1stSurvived(vector<vector<int>> I11, int rows, int columns, int min_support)
{
	int j = 0;
	int C2_supportCount_1stSurvived = 0;
	vector<vector<int>> I11_temp;
	I11_temp.resize(rows, vector<int>(columns, 0));
	I11_temp = I11;
	I11.clear();
	I11.resize(rows, vector<int>(columns, 0));

	//if 1st & Survived, add to 1stSurvived support count
	for (j = 0; j < I11_temp.size(); j++)
	{
		if (I11_temp[j][0] == 1 && I11_temp[j][1] == 1)
		{
			C2_supportCount_1stSurvived++;
		}
	}

	if(C2_supportCount_1stSurvived >= min_support)
	{
		//Prune itemsets (1st & Survived) || Fill I11 with ONLY 1st & Survived
		for(j = 0; j < I11_temp.size(); j++)
		{
			if(I11_temp[j][0] == 1 && I11_temp[j][1] == 1)//if data = 1st class & Survived, prune data & merge into I11
			{
				int i = 0;
				I11[i][0] = I11_temp[j][0];
				I11[i][1] = I11_temp[j][1];
				i++;
			}
		}
	}
	else
	{
		cout << "\n{1st, Survived} itemset does not exceed minimum support, ignoring..." << endl;
	}

	return I11;
}

//1st :: Dead
vector<vector<int>> pruneItemSet_1stDead(vector<vector<int>> I12, int rows, int columns, int min_support)
{
	int j = 0;
	int C2_supportCount_1stDead = 0;
	vector<vector<int>> I12_temp;
	I12_temp.resize(rows, vector<int>(columns, 0));
	I12_temp = I12;
	I12.clear();
	I12.resize(rows, vector<int>(columns, 0));
	

	//if 1st & Dead, add to 1stSurvived support count
	for (j = 0; j < I12_temp.size(); j++)
	{
		if (I12_temp[j][0] == 1 && I12_temp[j][1] == 0)
		{
			C2_supportCount_1stDead++;
		}
	}

	if(C2_supportCount_1stDead >= min_support)
	{
		//Prune itemsets (1st & Dead) || Fill I12 with ONLY 1st & Dead
		for(j = 0; j < I12_temp.size(); j++)
		{
			if(I12_temp[j][0] == 1 && I12_temp[j][1] == 1)//if data = 1st class & Dead, prune data & merge into I12
			{
				int i = 0;
				I12[i][0] = I12_temp[j][0];
				I12[i][1] = I12_temp[j][1];
				i++;
			}
		}
	}
	else
	{
		cout << "\n{1st, Dead} itemset does not exceed minimum support, ignoring..." << endl;
	}

	return I12;
}

//2nd :: Male
vector<vector<int>> pruneItemSet_2ndMale(vector<vector<int>> I13, int rows, int columns, int min_support)
{
	int j = 0;
	int C2_supportCount_2ndMale = 0;
	vector<vector<int>> I13_temp;
	I13_temp.resize(rows, vector<int>(columns, 0));
	I13_temp = I13;
	I13.clear();
	I13.resize(rows, vector<int>(columns, 0));

	//if 2nd & Male, add to 2ndMale support count
	for (j = 0; j < I13_temp.size(); j++)
	{
		if (I13_temp[j][0] == 2 && I13_temp[j][1] == 0)
		{
			C2_supportCount_2ndMale++;
		}
	}

	if(C2_supportCount_2ndMale >= min_support)
	{
		//Prune itemsets (2nd & Male) || Fill I13 with ONLY 2nd & Male
		for(j = 0; j < I13_temp.size(); j++)
		{
			if(I13_temp[j][0] == 2 && I13_temp[j][1] == 0)//if data = 2nd class & Male, prune data & merge into I13
			{
				int i = 0;
				I13[i][0] = I13_temp[j][0];
				I13[i][1] = I13_temp[j][1];
				i++;
			}
		}
	}
	else
	{
		cout << "\n{2nd, Male} itemset does not exceed minimum support, ignoring..." << endl;
	}

	return I13;
}

//2nd :: Female
vector<vector<int>> pruneItemSet_2ndFemale(vector<vector<int>> I14, int rows, int columns, int min_support)
{
	int j = 0;
	int C2_supportCount_2ndFemale = 0;
	vector<vector<int>> I14_temp;
	I14_temp.resize(rows, vector<int>(columns, 0));
	I14_temp = I14;
	I14.clear();
	I14.resize(rows, vector<int>(columns, 0));

	//if 2nd & Female, add to 2ndFemale support count
	for (j = 0; j < I14_temp.size(); j++)
	{
		if (I14_temp[j][0] == 2 && I14_temp[j][1] == 1)
		{
			C2_supportCount_2ndFemale++;
		}
	}

	if(C2_supportCount_2ndFemale >= min_support)
	{
		//Prune itemsets (2nd & Female) || Fill I14 with ONLY 2nd & Female
		for(j = 0; j < I14_temp.size(); j++)
		{
			if(I14_temp[j][0] == 2 && I14_temp[j][1] == 1)//if data = 2nd class & Female, prune data & merge into I14
			{
				int i = 0;
				I14[i][0] = I14_temp[j][0];
				I14[i][1] = I14_temp[j][1];
				i++;
			}
		}
	}
	else
	{
		cout << "\n{2nd, Female} itemset does not exceed minimum support, ignoring..." << endl;
	}

	return I14;
}

//2nd :: Adult
vector<vector<int>> pruneItemSet_2ndAdult(vector<vector<int>> I15, int rows, int columns, int min_support)
{
	int j = 0;
	int C2_supportCount_2ndAdult = 0;
	vector<vector<int>> I15_temp;
	I15_temp.resize(rows, vector<int>(columns, 0));
	I15_temp = I15;
	I15.clear();
	I15.resize(rows, vector<int>(columns, 0));

	//if 2nd & Adult, add to 2ndAdult support count
	for (j = 0; j < I15_temp.size(); j++)
	{
		if (I15_temp[j][0] == 2 && I15_temp[j][1] == 0)
		{
			C2_supportCount_2ndAdult++;
		}
	}

	if(C2_supportCount_2ndAdult >= min_support)
	{
		//Prune itemsets (2nd & Adult) || Fill I15 with ONLY 2nd & Adult
		for(j = 0; j < I15_temp.size(); j++)
		{
			if(I15_temp[j][0] == 2 && I15_temp[j][1] == 0)//if data = 2nd class & Adult, prune data & merge into I15
			{
				int i = 0;
				I15[i][0] = I15_temp[j][0];
				I15[i][1] = I15_temp[j][1];
				i++;
			}
		}
	}
	else
	{
		cout << "\n{2nd, Adult} itemset does not exceed minimum support, ignoring..." << endl;
	}

	return I15;
}

//2nd :: Child
vector<vector<int>> pruneItemSet_2ndChild(vector<vector<int>> I16, int rows, int columns, int min_support)
{
	int j = 0;
	int C2_supportCount_2ndChild = 0;
	vector<vector<int>> I16_temp;
	I16_temp.resize(rows, vector<int>(columns, 0));
	I16_temp = I16;
	I16.clear();
	I16.resize(rows, vector<int>(columns, 0));

	//if 2nd & Child, add to 2ndChild support count
	for (j = 0; j < I16_temp.size(); j++)
	{
		if (I16_temp[j][0] == 2 && I16_temp[j][1] == 1)
		{
			C2_supportCount_2ndChild++;
		}
	}
	
	if(C2_supportCount_2ndChild >= min_support)
	{
		//Prune itemsets (2nd & Child) || Fill I16 with ONLY 2nd & Child
		for(j = 0; j < I16_temp.size(); j++)
		{
			if(I16_temp[j][0] == 2 && I16_temp[j][1] == 1)//if data = 2nd class & Child, prune data & merge into I16
			{
				int i = 0;
				I16[i][0] = I16_temp[j][0];
				I16[i][1] = I16_temp[j][1];
				i++;
			}
		}
	}
	else
	{
		cout << "\n{2nd, Child} itemset does not exceed minimum support, ignoring..." << endl;
	}

	return I16;
}

//2nd :: Survived
vector<vector<int>> pruneItemSet_2ndSurvived(vector<vector<int>> I17, int rows, int columns, int min_support)
{
	int j = 0;
	int C2_supportCount_2ndSurvived = 0;
	vector<vector<int>> I17_temp;
	I17_temp.resize(rows, vector<int>(columns, 0));
	I17_temp = I17;
	I17.clear();
	I17.resize(rows, vector<int>(columns, 0));

	//if 2nd & Survived, add to 2ndSurvived support count
	for (j = 0; j < I17_temp.size(); j++)
	{
		if (I17_temp[j][0] == 2 && I17_temp[j][1] == 1)
		{
			C2_supportCount_2ndSurvived++;
		}
	}

	if(C2_supportCount_2ndSurvived >= min_support)
	{
		//Prune itemsets (2nd & Survived) || Fill I17 with ONLY 2nd & Survived
		for(j = 0; j < I17_temp.size(); j++)
		{
			if(I17_temp[j][0] == 2 && I17_temp[j][1] == 1)//if data = 2nd class & Survived, prune data & merge into I17
			{
				int i = 0;
				I17[i][0] = I17_temp[j][0];
				I17[i][1] = I17_temp[j][1];
				i++;
			}
		}
	}
	else
	{
		cout << "\n{2nd, Survived} itemset does not exceed minimum support, ignoring..." << endl;
	}

	return I17;
}

//2nd :: Dead
vector<vector<int>> pruneItemSet_2ndDead(vector<vector<int>> I18, int rows, int columns, int min_support)
{
	int j = 0;
	int C2_supportCount_2ndDead = 0;
	vector<vector<int>> I18_temp;
	I18_temp.resize(rows, vector<int>(columns, 0));
	I18_temp = I18;
	I18.clear();
	I18.resize(rows, vector<int>(columns, 0));

	//if 2nd & Dead, add to 2ndSurvived support count
	for (j = 0; j < I18_temp.size(); j++)
	{
		if (I18_temp[j][0] == 2 && I18_temp[j][1] == 0)
		{
			C2_supportCount_2ndDead++;
		}
	}

	if(C2_supportCount_2ndDead >= min_support)
	{
		//Prune itemsets (2nd & Dead) || Fill I18 with ONLY 2nd & Dead
		for(j = 0; j < I18_temp.size(); j++)
		{
			if(I18_temp[j][0] == 2 && I18_temp[j][1] == 1)//if data = 2nd class & Dead, prune data & merge into I18
			{
				int i = 0;
				I18[i][0] = I18_temp[j][0];
				I18[i][1] = I18_temp[j][1];
				i++;
			}
		}
	}
	else
	{
		cout << "\n{2nd, Dead} itemset does not exceed minimum support, ignoring..." << endl;
	}

	return I18;
}

//3rd :: Male
vector<vector<int>> pruneItemSet_3rdMale(vector<vector<int>> I19, int rows, int columns, int min_support)
{
	int j = 0;
	int C2_supportCount_3rdMale = 0;
	vector<vector<int>> I19_temp;
	I19_temp.resize(rows, vector<int>(columns, 0));
	I19_temp = I19;
	I19.clear();
	I19.resize(rows, vector<int>(columns, 0));

	//if 3rd & Male, add to 3rdMale support count
	for (j = 0; j < I19_temp.size(); j++)
	{
		if (I19_temp[j][0] == 3 && I19_temp[j][1] == 0)
		{
			C2_supportCount_3rdMale++;
		}
	}

	if(C2_supportCount_3rdMale >= min_support)
	{
		//Prune itemsets (3rd & Male) || Fill I19 with ONLY 3rd & Male
		for(j = 0; j < I19_temp.size(); j++)
		{
			if(I19_temp[j][0] == 3 && I19_temp[j][1] == 0)//if data = 3rd class & Male, prune data & merge into I19
			{
				int i = 0;
				I19[i][0] = I19_temp[j][0];
				I19[i][1] = I19_temp[j][1];
				i++;
			}
		}
	}
	else
	{
		cout << "\n{3rd, Male} itemset does not exceed minimum support, ignoring..." << endl;
	}

	return I19;
}

//3rd :: Female
vector<vector<int>> pruneItemSet_3rdFemale(vector<vector<int>> I20, int rows, int columns, int min_support)
{
	int j = 0;
	int C2_supportCount_3rdFemale = 0;
	vector<vector<int>> I20_temp;
	I20_temp.resize(rows, vector<int>(columns, 0));
	I20_temp = I20;
	I20.clear();
	I20.resize(rows, vector<int>(columns, 0));

	//if 3rd & Female, add to 3rdFemale support count
	for (j = 0; j < I20_temp.size(); j++)
	{
		if (I20_temp[j][0] == 3 && I20_temp[j][1] == 1)
		{
			C2_supportCount_3rdFemale++;
		}
	}

	if(C2_supportCount_3rdFemale >= min_support)
	{
		//Prune itemsets (3rd & Female) || Fill I20 with ONLY 3rd & Female
		for(j = 0; j < I20_temp.size(); j++)
		{
			if(I20_temp[j][0] == 3 && I20_temp[j][1] == 1)//if data = 3rd class & Female, prune data & merge into I20
			{
				int i = 0;
				I20[i][0] = I20_temp[j][0];
				I20[i][1] = I20_temp[j][1];
				i++;
			}
		}
	}
	else
	{
		cout << "\n{3rd, Female} itemset does not exceed minimum support, ignoring..." << endl;
	}

	return I20;
}

//3rd :: Adult
vector<vector<int>> pruneItemSet_3rdAdult(vector<vector<int>> I21, int rows, int columns, int min_support)
{
	int j = 0;
	int C2_supportCount_3rdAdult = 0;
	vector<vector<int>> I21_temp;
	I21_temp.resize(rows, vector<int>(columns, 0));
	I21_temp = I21;
	I21.clear();
	I21.resize(rows, vector<int>(columns, 0));

	//if 3rd & Adult, add to 3rdAdult support count
	for (j = 0; j < I21_temp.size(); j++)
	{
		if (I21_temp[j][0] == 3 && I21_temp[j][1] == 0)
		{
			C2_supportCount_3rdAdult++;
		}
	}

	if(C2_supportCount_3rdAdult >= min_support)
	{
		//Prune itemsets (3rd & Adult) || Fill I21 with ONLY 3rd & Adult
		for(j = 0; j < I21_temp.size(); j++)
		{
			if(I21_temp[j][0] == 3 && I21_temp[j][1] == 0)//if data = 3rd class & Adult, prune data & merge into I21
			{
				int i = 0;
				I21[i][0] = I21_temp[j][0];
				I21[i][1] = I21_temp[j][1];
				i++;
			}
		}
	}
	else
	{
		cout << "\n{3rd, Adult} itemset does not exceed minimum support, ignoring..." << endl;
	}

	return I21;
}

//3rd :: Child
vector<vector<int>> pruneItemSet_3rdChild(vector<vector<int>> I22, int rows, int columns, int min_support)
{
	int j = 0;
	int C2_supportCount_3rdChild = 0;
	vector<vector<int>> I22_temp;
	I22_temp.resize(rows, vector<int>(columns, 0));
	I22_temp = I22;
	I22.clear();
	I22.resize(rows, vector<int>(columns, 0));

	//if 3rd & Child, add to 3rdChild support count
	for (j = 0; j < I22_temp.size(); j++)
	{
		if (I22_temp[j][0] == 3 && I22_temp[j][1] == 1)
		{
			C2_supportCount_3rdChild++;
		}
	}
	if(C2_supportCount_3rdChild >= min_support)
	{
		//Prune itemsets (3rd & Child) || Fill I22 with ONLY 3rd & Child
		for(j = 0; j < I22_temp.size(); j++)
		{
			if(I22_temp[j][0] == 3 && I22_temp[j][1] == 1)//if data = 3rd class & Child, prune data & merge into I22
			{
				int i = 0;
				I22[i][0] = I22_temp[j][0];
				I22[i][1] = I22_temp[j][1];
				i++;
			}
		}
	}
	else
	{
		cout << "\n{3rd, Child} itemset does not exceed minimum support, ignoring..." << endl;
	}

	return I22;
}

//3rd :: Survived
vector<vector<int>> pruneItemSet_3rdSurvived(vector<vector<int>> I23, int rows, int columns, int min_support)
{
	int j = 0;
	int C2_supportCount_3rdSurvived = 0;
	vector<vector<int>> I23_temp;
	I23_temp.resize(rows, vector<int>(columns, 0));
	I23_temp = I23;
	I23.clear();
	I23.resize(rows, vector<int>(columns, 0));

	//if 3rd & Survived, add to 3rdSurvived support count
	for (j = 0; j < I23_temp.size(); j++)
	{
		if (I23_temp[j][0] == 3 && I23_temp[j][1] == 1)
		{
			C2_supportCount_3rdSurvived++;
		}
	}

	if(C2_supportCount_3rdSurvived >= min_support)
	{
		//Prune itemsets (3rd & Survived) || Fill I23 with ONLY 3rd & Survived
		for(j = 0; j < I23_temp.size(); j++)
		{
			if(I23_temp[j][0] == 3 && I23_temp[j][1] == 1)//if data = 3rd class & Survived, prune data & merge into I23
			{
				int i = 0;
				I23[i][0] = I23_temp[j][0];
				I23[i][1] = I23_temp[j][1];
				i++;
			}
		}
	}
	else
	{
		cout << "\n{3rd, Survived} itemset does not exceed minimum support, ignoring..." << endl;
	}

	return I23;
}

//3rd :: Dead
vector<vector<int>> pruneItemSet_3rdDead(vector<vector<int>> I24, int rows, int columns, int min_support)
{
	int j = 0;
	int C2_supportCount_3rdDead = 0;
	vector<vector<int>> I24_temp;
	I24_temp.resize(rows, vector<int>(columns, 0));
	I24_temp = I24;
	I24.clear();
	I24.resize(rows, vector<int>(columns, 0));

	//if 3rd & Dead, add to 3rdSurvived support count
	for (j = 0; j < I24_temp.size(); j++)
	{
		if (I24_temp[j][0] == 3 && I24_temp[j][1] == 0)
		{
			C2_supportCount_3rdDead++;
		}
	}

	if(C2_supportCount_3rdDead >= min_support)
	{
		//Prune itemsets (3rd & Dead) || Fill I24 with ONLY 3rd & Dead
		for(j = 0; j < I24_temp.size(); j++)
		{
			if(I24_temp[j][0] == 3 && I24_temp[j][1] == 1)//if data = 3rd class & Dead, prune data & merge into I24
			{
				int i = 0;
				I24[i][0] = I24_temp[j][0];
				I24[i][1] = I24_temp[j][1];
				i++;
			}
		}
	}
	else
	{
		cout << "\n{3rd, Dead} itemset does not exceed minimum support, ignoring..." << endl;
	}

	return I24;
}

//Survived :: Male
vector<vector<int>> pruneItemSet_survivedMale(vector<vector<int>> I25, int rows, int columns, int min_support)
{
	int j = 0;
	int C2_supportCount_survivedMale = 0;
	vector<vector<int>> I25_temp;
	I25_temp.resize(rows, vector<int>(columns, 0));
	I25_temp = I25;
	I25.clear();
	I25.resize(rows, vector<int>(columns, 0));

	//if Survived & Male, add to survivedDead support count
	for (j = 0; j < I25_temp.size(); j++)
	{
		if (I25_temp[j][0] == 1 && I25_temp[j][1] == 0)
		{
			C2_supportCount_survivedMale++;
		}
	}

	if(C2_supportCount_survivedMale >= min_support)
	{
		//Prune itemsets (Survived & Male) || Fill I25 with ONLY Survived & Male
		for(j = 0; j < I25_temp.size(); j++)
		{
			if(I25_temp[j][0] == 1 && I25_temp[j][1] == 0)//if data = Survived & Male, prune data & merge into I25
			{
				int i = 0;
				I25[i][0] = I25_temp[j][0];
				I25[i][1] = I25_temp[j][1];
				i++;
			}
		}
	}
	else
	{
		cout << "\n{Survived, Male} itemset does not exceed minimum support, ignoring..." << endl;
	}

	return I25;
}

//Survived :: Female
vector<vector<int>> pruneItemSet_survivedFemale(vector<vector<int>> I26, int rows, int columns, int min_support)
{
	int j = 0;
	int C2_supportCount_survivedFemale = 0;
	vector<vector<int>> I26_temp;
	I26_temp.resize(rows, vector<int>(columns, 0));
	I26_temp = I26;
	I26.clear();
	I26.resize(rows, vector<int>(columns, 0));

	//if Survived & Female, add to survivedDead support count
	for (j = 0; j < I26_temp.size(); j++)
	{
		if (I26_temp[j][0] == 1 && I26_temp[j][1] == 1)
		{
			C2_supportCount_survivedFemale++;
		}
	}

	if(C2_supportCount_survivedFemale >= min_support)
	{
		//Prune itemsets (Survived & Female) || Fill I26 with ONLY Survived & Female
		for(j = 0; j < I26_temp.size(); j++)
		{
			if(I26_temp[j][0] == 1 && I26_temp[j][1] == 1)//if data = Survived & Female, prune data & merge into I26
			{
				int i = 0;
				I26[i][0] = I26_temp[j][0];
				I26[i][1] = I26_temp[j][1];
				i++;
			}
		}
	}
	else
	{
		cout << "\n{Survived, Female} itemset does not exceed minimum support, ignoring..." << endl;
	}

	return I26;
}

//Survived :: Adult
vector<vector<int>> pruneItemSet_survivedAdult(vector<vector<int>> I27, int rows, int columns, int min_support)
{
	int j = 0;
	int C2_supportCount_survivedAdult = 0;
	vector<vector<int>> I27_temp;
	I27_temp.resize(rows, vector<int>(columns, 0));
	I27_temp = I27;
	I27.clear();
	I27.resize(rows, vector<int>(columns, 0));

	//if Survived & Adult, add to survivedDead support count
	for (j = 0; j < I27_temp.size(); j++)
	{
		if (I27_temp[j][0] == 1 && I27_temp[j][1] == 0)
		{
			C2_supportCount_survivedAdult++;
		}
	}

	if(C2_supportCount_survivedAdult >= min_support)
	{
		//Prune itemsets (Survived & Adult) || Fill I27 with ONLY Survived & Adult
		for(j = 0; j < I27_temp.size(); j++)
		{
			if(I27_temp[j][0] == 1 && I27_temp[j][1] == 0)//if data = Survived & Adult, prune data & merge into I27
			{
				int i = 0;
				I27[i][0] = I27_temp[j][0];
				I27[i][1] = I27_temp[j][1];
				i++;
			}
		}
	}
	else
	{
		cout << "\n{Survived, Adult} itemset does not exceed minimum support, ignoring..." << endl;
	}

	return I27;
}

//Survived :: Child
vector<vector<int>> pruneItemSet_survivedChild(vector<vector<int>> I28, int rows, int columns, int min_support)
{
	int j = 0;
	int C2_supportCount_survivedChild = 0;
	vector<vector<int>> I28_temp;
	I28_temp.resize(rows, vector<int>(columns, 0));
	I28_temp = I28;
	I28.clear();
	I28.resize(rows, vector<int>(columns, 0));

	//if Survived & Child, add to survivedDead support count
	for (j = 0; j < I28_temp.size(); j++)
	{
		if (I28_temp[j][0] == 1 && I28_temp[j][1] == 1)
		{
			C2_supportCount_survivedChild++;
		}
	}

	if(C2_supportCount_survivedChild >= min_support)
	{
		//Prune itemsets (Survived & Child) || Fill I28 with ONLY Survived & Child
		for(j = 0; j < I28_temp.size(); j++)
		{
			if(I28_temp[j][0] == 1 && I28_temp[j][1] == 1)//if data = Survived & Child, prune data & merge into I28
			{
				int i = 0;
				I28[i][0] = I28_temp[j][0];
				I28[i][1] = I28_temp[j][1];
				i++;
			}
		}
	}
	else
	{
		cout << "\n{Survived, Child} itemset does not exceed minimum support, ignoring..." << endl;
	}

	return I28;
}

//Dead :: Male
vector<vector<int>> pruneItemSet_deadMale(vector<vector<int>> I29, int rows, int columns, int min_support)
{
	int j = 0;
	int C2_supportCount_deadMale = 0; 
	vector<vector<int>> I29_temp;
	I29_temp.resize(rows, vector<int>(columns, 0));
	I29_temp = I29;
	I29.clear();
	I29.resize(rows, vector<int>(columns, 0));

	//if Dead & Male, add to deadMale support count
	for (j = 0; j < I29_temp.size(); j++)
	{
		if (I29_temp[j][0] == 0 && I29_temp[j][1] == 0)
		{
			C2_supportCount_deadMale++;
		}
	}

	if(C2_supportCount_deadMale >= min_support)
	{
		//Prune itemsets (Dead & Male) || Fill I29 with ONLY Dead & Male
		for(j = 0; j < I29_temp.size(); j++)
		{
			if(I29_temp[j][0] == 0 && I29_temp[j][1] == 0)//if data = Dead & Male, prune data & merge into I29
			{
				int i = 0;
				I29[i][0] = I29_temp[j][0];
				I29[i][1] = I29_temp[j][1];
				i++;
			}
		}
	}
	else
	{
		cout << "\n{Dead, Male} itemset does not exceed minimum support, ignoring..." << endl;
	}

	return I29;
}

//Dead :: Female
vector<vector<int>> pruneItemSet_deadFemale(vector<vector<int>> I30, int rows, int columns, int min_support)
{
	int j = 0;
	int C2_supportCount_deadFemale = 0;
	vector<vector<int>> I30_temp;
	I30_temp.resize(rows, vector<int>(columns, 0));
	I30_temp = I30;
	I30.clear();
	I30.resize(rows, vector<int>(columns, 0));

	//if Dead & Female, add to deadFemale support count
	for (j = 0; j < I30_temp.size(); j++)
	{
		if (I30_temp[j][0] == 0 && I30_temp[j][1] == 1)
		{
			C2_supportCount_deadFemale++;
		}
	}

	if(C2_supportCount_deadFemale >= min_support)
	{
		//Prune itemsets (Dead & Female) || Fill I30 with ONLY Dead & Female
		for(j = 0; j < I30_temp.size(); j++)
		{
			if(I30_temp[j][0] == 0 && I30_temp[j][1] == 1)//if data = Dead & Female, prune data & merge into I30
			{
				int i = 0;
				I30[i][0] = I30_temp[j][0];
				I30[i][1] = I30_temp[j][1];
				i++;
			}
		}
	}
	else
	{
		cout << "\n{Dead, Female} itemset does not exceed minimum support, ignoring..." << endl;
	}

	return I30;
}

//Dead :: Adult
vector<vector<int>> pruneItemSet_deadAdult(vector<vector<int>> I31, int rows, int columns, int min_support)
{
	int j = 0;
	int C2_supportCount_deadAdult = 0;
	vector<vector<int>> I31_temp;
	I31_temp.resize(rows, vector<int>(columns, 0));
	I31_temp = I31;
	I31.clear();
	I31.resize(rows, vector<int>(columns, 0));

	//if Dead & Adult, add to deadAdult support count
	for (j = 0; j < I31_temp.size(); j++)
	{
		if (I31_temp[j][0] == 0 && I31_temp[j][1] == 0)
		{
			C2_supportCount_deadAdult++;
		}
	}

	if(C2_supportCount_deadAdult >= min_support)
	{
		//Prune itemsets (Dead & Adult) || Fill I31 with ONLY Dead & Adult
		for(j = 0; j < I31_temp.size(); j++)
		{
			if(I31_temp[j][0] == 0 && I31_temp[j][1] == 0)//if data = Dead & Adult, prune data & merge into I31
			{
				int i = 0;
				I31[i][0] = I31_temp[j][0];
				I31[i][1] = I31_temp[j][1];
				i++;
			}
		}
	}
	else
	{
		cout << "\n{Dead, Adult} itemset does not exceed minimum support, ignoring..." << endl;
	}

	return I31;
}

//Dead :: Child
vector<vector<int>> pruneItemSet_deadChild(vector<vector<int>> I32, int rows, int columns, int min_support)
{
	int j = 0;
	int C2_supportCount_deadChild = 0;
	vector<vector<int>> I32_temp;
	I32_temp.resize(rows, vector<int>(columns, 0));
	I32_temp = I32;
	I32.clear();
	I32.resize(rows, vector<int>(columns, 0));
	
	//if Dead & Child, add to deadChild support count
	for (j = 0; j < I32_temp.size(); j++)
	{
		if (I32_temp[j][0] == 0 && I32_temp[j][1] == 1)
		{
			C2_supportCount_deadChild++;
		}
	}

	if(C2_supportCount_deadChild >= min_support)
	{
		//Prune itemsets (Dead & Child) || Fill I32 with ONLY Dead & Child
		for(j = 0; j < I32_temp.size(); j++)
		{
			if(I32_temp[j][0] == 0 && I32_temp[j][1] == 1)//if data = Dead & Child, prune data & merge into I32
			{
				int i = 0;
				I32[i][0] = I32_temp[j][0];
				I32[i][1] = I32_temp[j][1];
				i++;
			}
		}
	}
	else
	{
		cout << "\n{Dead, Child} itemset does not exceed minimum support, ignoring..." << endl;
	}

	return I32;
}

//////////////////
//Get Confidence//
//////////////////

//Crew :: Male
float getConfidence_crewMale(float confidence, float antecedent, float consequent, vector<vector<int>> I_)
{
	//Calc Antecedent & Consequent
	int antecedentCount = 0;
	int consequentCount = 0;
	for(int i = 0; i < I_.size(); i++)
	{
		//If {Crew, Male} 
		if(I_[i][0] == 0 && I_[i][1] == 0)
		{
			antecedentCount++;
		}
		if(I_[i][1] == 0)
		{
			consequentCount++;
		}
	}
	//Calc Confidence
	if(consequentCount != 0)
	{
		return (antecedentCount / consequentCount);
	}
	else
	{
		"\nConsequent count is equal to zero, cannot divide by zero!\n";
		return 0.0;
	}
}

//Crew :: Female
float getConfidence_crewFemale(float confidence, float antecedent, float consequent, vector<vector<int>> I_)
{
	//Calc Antecedent & Consequent
	int antecedentCount = 0;
	int consequentCount = 0;
	for(int i = 0; i < I_.size(); i++)
	{
		//If {Crew, Female} 
		if(I_[i][0] == 0 && I_[i][1] == 1)
		{
			antecedentCount++;
		}
		if(I_[i][1] == 1)
		{
			consequentCount++;
		}
	}
	//Calc Confidence
	if(consequentCount != 0)
	{
		return (antecedentCount / consequentCount);
	}
	else
	{
		"\nConsequent count is equal to zero, cannot divide by zero!\n";
		return 0.0;
	}
}

//Crew :: Adult
float getConfidence_crewAdult(float confidence, float antecedent, float consequent, vector<vector<int>> I_)
{
	//Calc Antecedent & Consequent
	int antecedentCount = 0;
	int consequentCount = 0;
	for(int i = 0; i < I_.size(); i++)
	{
		//If {Crew, Adult} 
		if(I_[i][0] == 0 && I_[i][1] == 0)
		{
			antecedentCount++;
		}
		if(I_[i][1] == 0)
		{
			consequentCount++;
		}
	}
	//Calc Confidence
	if(consequentCount != 0)
	{
		return (antecedentCount / consequentCount);
	}
	else
	{
		"\nConsequent count is equal to zero, cannot divide by zero!\n";
		return 0.0;
	}
}

//Crew :: Child
float getConfidence_crewChild(float confidence, float antecedent, float consequent, vector<vector<int>> I_)
{
	//Calc Antecedent & Consequent
	int antecedentCount = 0;
	int consequentCount = 0;
	for(int i = 0; i < I_.size(); i++)
	{
		//If {Crew, Child} 
		if(I_[i][0] == 0 && I_[i][1] == 1)
		{
			antecedentCount++;
		}
		if(I_[i][1] == 1)
		{
			consequentCount++;
		}
	}
	//Calc Confidence
	if(consequentCount != 0)
	{
		return (antecedentCount / consequentCount);
	}
	else
	{
		"\nConsequent count is equal to zero, cannot divide by zero!\n";
		return 0.0;
	}
}

//Crew :: Survived
float getConfidence_crewSurvived(float confidence, float antecedent, float consequent, vector<vector<int>> I_)
{
	//Calc Antecedent & Consequent
	int antecedentCount = 0;
	int consequentCount = 0;
	for(int i = 0; i < I_.size(); i++)
	{
		//If {Crew, Survived} 
		if(I_[i][0] == 0 && I_[i][1] == 1)
		{
			antecedentCount++;
		}
		if(I_[i][1] == 1)
		{
			consequentCount++;
		}
	}
	//Calc Confidence
	if(consequentCount != 0)
	{
		return (antecedentCount / consequentCount);
	}
	else
	{
		"\nConsequent count is equal to zero, cannot divide by zero!\n";
		return 0.0;
	}
}

//Crew :: Dead
float getConfidence_crewDead(float confidence, float antecedent, float consequent, vector<vector<int>> I_)
{
	//Calc Antecedent & Consequent
	int antecedentCount = 0;
	int consequentCount = 0;
	for(int i = 0; i < I_.size(); i++)
	{
		//If {Crew, Dead} 
		if(I_[i][0] == 0 && I_[i][1] == 0)
		{
			antecedentCount++;
		}
		if(I_[i][1] == 0)
		{
			consequentCount++;
		}
	}
	//Calc Confidence
	if(consequentCount != 0)
	{
		return (antecedentCount / consequentCount);
	}
	else
	{
		"\nConsequent count is equal to zero, cannot divide by zero!\n";
		return 0.0;
	}
}

//1st :: Male
float getConfidence_1stMale(float confidence, float antecedent, float consequent, vector<vector<int>> I_)
{
	//Calc Antecedent & Consequent
	int antecedentCount = 0;
	int consequentCount = 0;
	for(int i = 0; i < I_.size(); i++)
	{
		//If {1st, Male} 
		if(I_[i][0] == 1 && I_[i][1] == 0)
		{
			antecedentCount++;
		}
		if(I_[i][1] == 0)
		{
			consequentCount++;
		}
	}
	//Calc Confidence
	if(consequentCount != 0)
	{
		return (antecedentCount / consequentCount);
	}
	else
	{
		"\nConsequent count is equal to zero, cannot divide by zero!\n";
		return 0.0;
	}
}

//1st :: Female
float getConfidence_1stFemale(float confidence, float antecedent, float consequent, vector<vector<int>> I_)
{
	//Calc Antecedent & Consequent
	int antecedentCount = 0;
	int consequentCount = 0;
	for(int i = 0; i < I_.size(); i++)
	{
		//If {1st, Female} 
		if(I_[i][0] == 1 && I_[i][1] == 1)
		{
			antecedentCount++;
		}
		if(I_[i][1] == 1)
		{
			consequentCount++;
		}
	}
	//Calc Confidence
	if(consequentCount != 0)
	{
		return (antecedentCount / consequentCount);
	}
	else
	{
		"\nConsequent count is equal to zero, cannot divide by zero!\n";
		return 0.0;
	}
}

//1st :: Adult
float getConfidence_1stAdult(float confidence, float antecedent, float consequent, vector<vector<int>> I_)
{
	//Calc Antecedent & Consequent
	int antecedentCount = 0;
	int consequentCount = 0;
	for(int i = 0; i < I_.size(); i++)
	{
		//If {1st, Adult} 
		if(I_[i][0] == 1 && I_[i][1] == 0)
		{
			antecedentCount++;
		}
		if(I_[i][1] == 0)
		{
			consequentCount++;
		}
	}
	//Calc Confidence
	if(consequentCount != 0)
	{
		return (antecedentCount / consequentCount);
	}
	else
	{
		"\nConsequent count is equal to zero, cannot divide by zero!\n";
		return 0.0;
	}
}

//1st :: Child
float getConfidence_1stChild(float confidence, float antecedent, float consequent, vector<vector<int>> I_)
{
	//Calc Antecedent & Consequent
	int antecedentCount = 0;
	int consequentCount = 0;
	for(int i = 0; i < I_.size(); i++)
	{
		//If {1st, Child} 
		if(I_[i][0] == 1 && I_[i][1] == 1)
		{
			antecedentCount++;
		}
		if(I_[i][1] == 1)
		{
			consequentCount++;
		}
	}
	//Calc Confidence
	if(consequentCount != 0)
	{
		return (antecedentCount / consequentCount);
	}
	else
	{
		"\nConsequent count is equal to zero, cannot divide by zero!\n";
		return 0.0;
	}
}

//1st :: Survived
float getConfidence_1stSurvived(float confidence, float antecedent, float consequent, vector<vector<int>> I_)
{
	//Calc Antecedent & Consequent
	int antecedentCount = 0;
	int consequentCount = 0;
	for(int i = 0; i < I_.size(); i++)
	{
		//If {1st, Survived} 
		if(I_[i][0] == 1 && I_[i][1] == 1)
		{
			antecedentCount++;
		}
		if(I_[i][1] == 1)
		{
			consequentCount++;
		}
	}
	//Calc Confidence
	if(consequentCount != 0)
	{
		return (antecedentCount / consequentCount);
	}
	else
	{
		"\nConsequent count is equal to zero, cannot divide by zero!\n";
		return 0.0;
	}
}

//1st :: Dead
float getConfidence_1stDead(float confidence, float antecedent, float consequent, vector<vector<int>> I_)
{
	//Calc Antecedent & Consequent
	int antecedentCount = 0;
	int consequentCount = 0;
	for(int i = 0; i < I_.size(); i++)
	{
		//If {1st, Dead} 
		if(I_[i][0] == 1 && I_[i][1] == 0)
		{
			antecedentCount++;
		}
		if(I_[i][1] == 0)
		{
			consequentCount++;
		}
	}
	//Calc Confidence
	if(consequentCount != 0)
	{
		return (antecedentCount / consequentCount);
	}
	else
	{
		"\nConsequent count is equal to zero, cannot divide by zero!\n";
		return 0.0;
	}
}

//2nd :: Male
float getConfidence_2ndMale(float confidence, float antecedent, float consequent, vector<vector<int>> I_)
{
	//Calc Antecedent & Consequent
	int antecedentCount = 0;
	int consequentCount = 0;
	for(int i = 0; i < I_.size(); i++)
	{
		//If {2nd, Male} 
		if(I_[i][0] == 2 && I_[i][1] == 0)
		{
			antecedentCount++;
		}
		if(I_[i][1] == 0)
		{
			consequentCount++;
		}
	}
	//Calc Confidence
	if(consequentCount != 0)
	{
		return (antecedentCount / consequentCount);
	}
	else
	{
		"\nConsequent count is equal to zero, cannot divide by zero!\n";
		return 0.0;
	}
}

//2nd :: Female
float getConfidence_2ndFemale(float confidence, float antecedent, float consequent, vector<vector<int>> I_)
{
	//Calc Antecedent & Consequent
	int antecedentCount = 0;
	int consequentCount = 0;
	for(int i = 0; i < I_.size(); i++)
	{
		//If {2nd, Female} 
		if(I_[i][0] == 2 && I_[i][1] == 1)
		{
			antecedentCount++;
		}
		if(I_[i][1] == 1)
		{
			consequentCount++;
		}
	}
	//Calc Confidence
	if(consequentCount != 0)
	{
		return (antecedentCount / consequentCount);
	}
	else
	{
		"\nConsequent count is equal to zero, cannot divide by zero!\n";
		return 0.0;
	}
}

//2nd :: Adult
float getConfidence_2ndAdult(float confidence, float antecedent, float consequent, vector<vector<int>> I_)
{
	//Calc Antecedent & Consequent
	int antecedentCount = 0;
	int consequentCount = 0;
	for(int i = 0; i < I_.size(); i++)
	{
		//If {2nd, Adult} 
		if(I_[i][0] == 2 && I_[i][1] == 0)
		{
			antecedentCount++;
		}
		if(I_[i][1] == 0)
		{
			consequentCount++;
		}
	}
	//Calc Confidence
	if(consequentCount != 0)
	{
		return (antecedentCount / consequentCount);
	}
	else
	{
		"\nConsequent count is equal to zero, cannot divide by zero!\n";
		return 0.0;
	}
}

//2nd :: Child
float getConfidence_2ndChild(float confidence, float antecedent, float consequent, vector<vector<int>> I_)
{
	//Calc Antecedent & Consequent
	int antecedentCount = 0;
	int consequentCount = 0;
	for(int i = 0; i < I_.size(); i++)
	{
		//If {2nd, Child} 
		if(I_[i][0] == 2 && I_[i][1] == 1)
		{
			antecedentCount++;
		}
		if(I_[i][1] == 1)
		{
			consequentCount++;
		}
	}
	//Calc Confidence
	if(consequentCount != 0)
	{
		return (antecedentCount / consequentCount);
	}
	else
	{
		"\nConsequent count is equal to zero, cannot divide by zero!\n";
		return 0.0;
	}
}

//2nd :: Survived
float getConfidence_2ndSurvived(float confidence, float antecedent, float consequent, vector<vector<int>> I_)
{
	//Calc Antecedent & Consequent
	int antecedentCount = 0;
	int consequentCount = 0;
	for(int i = 0; i < I_.size(); i++)
	{
		//If {2nd, Survived} 
		if(I_[i][0] == 2 && I_[i][1] == 1)
		{
			antecedentCount++;
		}
		if(I_[i][1] == 1)
		{
			consequentCount++;
		}
	}
	//Calc Confidence
	if(consequentCount != 0)
	{
		return (antecedentCount / consequentCount);
	}
	else
	{
		"\nConsequent count is equal to zero, cannot divide by zero!\n";
		return 0.0;
	}
}

//2nd :: Dead
float getConfidence_2ndDead(float confidence, float antecedent, float consequent, vector<vector<int>> I_)
{
	//Calc Antecedent & Consequent
	int antecedentCount = 0;
	int consequentCount = 0;
	for(int i = 0; i < I_.size(); i++)
	{
		//If {2nd, Dead} 
		if(I_[i][0] == 2 && I_[i][1] == 0)
		{
			antecedentCount++;
		}
		if(I_[i][1] == 0)
		{
			consequentCount++;
		}
	}
	//Calc Confidence
	if(consequentCount != 0)
	{
		return (antecedentCount / consequentCount);
	}
	else
	{
		"\nConsequent count is equal to zero, cannot divide by zero!\n";
		return 0.0;
	}
}

//3rd :: Male
float getConfidence_3rdMale(float confidence, float antecedent, float consequent, vector<vector<int>> I_)
{
	//Calc Antecedent & Consequent
	int antecedentCount = 0;
	int consequentCount = 0;
	for(int i = 0; i < I_.size(); i++)
	{
		//If {3rd, Male} 
		if(I_[i][0] == 3 && I_[i][1] == 0)
		{
			antecedentCount++;
		}
		if(I_[i][1] == 0)
		{
			consequentCount++;
		}
	}
	//Calc Confidence
	if(consequentCount != 0)
	{
		return (antecedentCount / consequentCount);
	}
	else
	{
		"\nConsequent count is equal to zero, cannot divide by zero!\n";
		return 0.0;
	}
}

//3rd :: Female
float getConfidence_3rdFemale(float confidence, float antecedent, float consequent, vector<vector<int>> I_)
{
	//Calc Antecedent & Consequent
	int antecedentCount = 0;
	int consequentCount = 0;
	for(int i = 0; i < I_.size(); i++)
	{
		//If {3rd, Female} 
		if(I_[i][0] == 3 && I_[i][1] == 1)
		{
			antecedentCount++;
		}
		if(I_[i][1] == 1)
		{
			consequentCount++;
		}
	}
	//Calc Confidence
	if(consequentCount != 0)
	{
		return (antecedentCount / consequentCount);
	}
	else
	{
		"\nConsequent count is equal to zero, cannot divide by zero!\n";
		return 0.0;
	}
}

//3rd :: Adult
float getConfidence_3rdAdult(float confidence, float antecedent, float consequent, vector<vector<int>> I_)
{
	//Calc Antecedent & Consequent
	int antecedentCount = 0;
	int consequentCount = 0;
	for(int i = 0; i < I_.size(); i++)
	{
		//If {3rd, Adult} 
		if(I_[i][0] == 3 && I_[i][1] == 0)
		{
			antecedentCount++;
		}
		if(I_[i][1] == 0)
		{
			consequentCount++;
		}
	}
	//Calc Confidence
	if(consequentCount != 0)
	{
		return (antecedentCount / consequentCount);
	}
	else
	{
		"\nConsequent count is equal to zero, cannot divide by zero!\n";
		return 0.0;
	}
}

//3rd :: Child
float getConfidence_3rdChild(float confidence, float antecedent, float consequent, vector<vector<int>> I_)
{
	//Calc Antecedent & Consequent
	int antecedentCount = 0;
	int consequentCount = 0;
	for(int i = 0; i < I_.size(); i++)
	{
		//If {3rd, Child} 
		if(I_[i][0] == 3 && I_[i][1] == 1)
		{
			antecedentCount++;
		}
		if(I_[i][1] == 1)
		{
			consequentCount++;
		}
	}
	//Calc Confidence
	if(consequentCount != 0)
	{
		return (antecedentCount / consequentCount);
	}
	else
	{
		"\nConsequent count is equal to zero, cannot divide by zero!\n";
		return 0.0;
	}
}

//3rd :: Survived
float getConfidence_3rdSurvived(float confidence, float antecedent, float consequent, vector<vector<int>> I_)
{
	//Calc Antecedent & Consequent
	int antecedentCount = 0;
	int consequentCount = 0;
	for(int i = 0; i < I_.size(); i++)
	{
		//If {3rd, Survived} 
		if(I_[i][0] == 3 && I_[i][1] == 1)
		{
			antecedentCount++;
		}
		if(I_[i][1] == 1)
		{
			consequentCount++;
		}
	}
	//Calc Confidence
	if(consequentCount != 0)
	{
		return (antecedentCount / consequentCount);
	}
	else
	{
		"\nConsequent count is equal to zero, cannot divide by zero!\n";
		return 0.0;
	}
}

//3rd :: Dead
float getConfidence_3rdDead(float confidence, float antecedent, float consequent, vector<vector<int>> I_)
{
	//Calc Antecedent & Consequent
	int antecedentCount = 0;
	int consequentCount = 0;
	for(int i = 0; i < I_.size(); i++)
	{
		//If {3rd, Dead} 
		if(I_[i][0] == 3 && I_[i][1] == 0)
		{
			antecedentCount++;
		}
		if(I_[i][1] == 0)
		{
			consequentCount++;
		}
	}
	//Calc Confidence
	if(consequentCount != 0)
	{
		return (antecedentCount / consequentCount);
	}
	else
	{
		"\nConsequent count is equal to zero, cannot divide by zero!\n";
		return 0.0;
	}
}

//Survived :: Male
float getConfidence_survivedMale(float confidence, float antecedent, float consequent, vector<vector<int>> I_)
{
	//Calc Antecedent & Consequent
	int antecedentCount = 0;
	int consequentCount = 0;
	for(int i = 0; i < I_.size(); i++)
	{
		//If {Survived, Male} 
		if(I_[i][0] == 1 && I_[i][1] == 0)
		{
			antecedentCount++;
		}
		if(I_[i][1] == 0)
		{
			consequentCount++;
		}
	}
	//Calc Confidence
	if(consequentCount != 0)
	{
		return (antecedentCount / consequentCount);
	}
	else
	{
		"\nConsequent count is equal to zero, cannot divide by zero!\n";
		return 0.0;
	}
}

//Survived :: Female
float getConfidence_survivedFemale(float confidence, float antecedent, float consequent, vector<vector<int>> I_)
{
	//Calc Antecedent & Consequent
	int antecedentCount = 0;
	int consequentCount = 0;
	for(int i = 0; i < I_.size(); i++)
	{
		//If {Survived, Female} 
		if(I_[i][0] == 1 && I_[i][1] == 1)
		{
			antecedentCount++;
		}
		if(I_[i][1] == 1)
		{
			consequentCount++;
		}
	}
	//Calc Confidence
	if(consequentCount != 0)
	{
		return (antecedentCount / consequentCount);
	}
	else
	{
		"\nConsequent count is equal to zero, cannot divide by zero!\n";
		return 0.0;
	}
}

//Survived :: Adult
float getConfidence_survivedAdult(float confidence, float antecedent, float consequent, vector<vector<int>> I_)
{
	//Calc Antecedent & Consequent
	int antecedentCount = 0;
	int consequentCount = 0;
	for(int i = 0; i < I_.size(); i++)
	{
		//If {Survived, Adult} 
		if(I_[i][0] == 1 && I_[i][1] == 0)
		{
			antecedentCount++;
		}
		if(I_[i][1] == 0)
		{
			consequentCount++;
		}
	}
	//Calc Confidence
	if(consequentCount != 0)
	{
		return (antecedentCount / consequentCount);
	}
	else
	{
		"\nConsequent count is equal to zero, cannot divide by zero!\n";
		return 0.0;
	}
}

//Survived :: Child
float getConfidence_survivedChild(float confidence, float antecedent, float consequent, vector<vector<int>> I_)
{
	//Calc Antecedent & Consequent
	int antecedentCount = 0;
	int consequentCount = 0;
	for(int i = 0; i < I_.size(); i++)
	{
		//If {Survived, Child} 
		if(I_[i][0] == 1 && I_[i][1] == 1)
		{
			antecedentCount++;
		}
		if(I_[i][1] == 1)
		{
			consequentCount++;
		}
	}
	//Calc Confidence
	if(consequentCount != 0)
	{
		return (antecedentCount / consequentCount);
	}
	else
	{
		"\nConsequent count is equal to zero, cannot divide by zero!\n";
		return 0.0;
	}
}


//Dead :: Male
float getConfidence_deadMale(float confidence, float antecedent, float consequent, vector<vector<int>> I_)
{
	//Calc Antecedent & Consequent
	int antecedentCount = 0;
	int consequentCount = 0;
	for(int i = 0; i < I_.size(); i++)
	{
		//If {Dead, Male} 
		if(I_[i][0] == 0 && I_[i][1] == 0)
		{
			antecedentCount++;
		}
		if(I_[i][1] == 0)
		{
			consequentCount++;
		}
	}
	//Calc Confidence
	if(consequentCount != 0)
	{
		return (antecedentCount / consequentCount);
	}
	else
	{
		"\nConsequent count is equal to zero, cannot divide by zero!\n";
		return 0.0;
	}
}

//Dead :: Female
float getConfidence_deadFemale(float confidence, float antecedent, float consequent, vector<vector<int>> I_)
{
	//Calc Antecedent & Consequent
	int antecedentCount = 0;
	int consequentCount = 0;
	for(int i = 0; i < I_.size(); i++)
	{
		//If {Dead, Female} 
		if(I_[i][0] == 0 && I_[i][1] == 1)
		{
			antecedentCount++;
		}
		if(I_[i][1] == 1)
		{
			consequentCount++;
		}
	}
	//Calc Confidence
	if(consequentCount != 0)
	{
		return (antecedentCount / consequentCount);
	}
	else
	{
		"\nConsequent count is equal to zero, cannot divide by zero!\n";
		return 0.0;
	}
}

//Dead :: Adult
float getConfidence_deadAdult(float confidence, float antecedent, float consequent, vector<vector<int>> I_)
{
	//Calc Antecedent & Consequent
	int antecedentCount = 0;
	int consequentCount = 0;
	for(int i = 0; i < I_.size(); i++)
	{
		//If {Dead, Adult} 
		if(I_[i][0] == 0 && I_[i][1] == 0)
		{
			antecedentCount++;
		}
		if(I_[i][1] == 0)
		{
			consequentCount++;
		}
	}
	//Calc Confidence
	if(consequentCount != 0)
	{
		return (antecedentCount / consequentCount);
	}
	else
	{
		"\nConsequent count is equal to zero, cannot divide by zero!\n";
		return 0.0;
	}
}

//Dead :: Child
float getConfidence_deadChild(float confidence, float antecedent, float consequent, vector<vector<int>> I_)
{
	//Calc Antecedent & Consequent
	int antecedentCount = 0;
	int consequentCount = 0;
	for(int i = 0; i < I_.size(); i++)
	{
		//If {Dead, Child} 
		if(I_[i][0] == 0 && I_[i][1] == 1)
		{
			antecedentCount++;
		}
		if(I_[i][1] == 1)
		{
			consequentCount++;
		}
	}
	//Calc Confidence
	if(consequentCount != 0)
	{
		return (antecedentCount / consequentCount);
	}
	else
	{
		"\nConsequent count is equal to zero, cannot divide by zero!\n";
		return 0.0;
	}
}