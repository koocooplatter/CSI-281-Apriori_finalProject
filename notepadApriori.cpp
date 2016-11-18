	Attributes to deal with: Crew, 1st, 2nd, 3rd, Male, Female, Adult, Child, Survived, Dead
	
	C1  = {crew, male}
	C2  = {crew, female}
	C3  = {crew, adult}
	C4  = {crew, child}
	C5  = {crew, survived}
	C6  = {crew, dead}
	C7  = {1st, male} 
	C8  = {1st, female}
	C9  = {1st, adult}
	C10 = {1st, child}
	C11 = {1st, survived}
	C12 = {1st, dead}
	C13 = {2nd, male}
	C14 = {2nd, female}
	C15 = {2nd, adult}
	C16 = {2nd, child}
	C17 = {2nd, survived}
	C18 = {2nd, dead}
	C19 = {3rd, male}
	C20 = {3rd, female}
	C21 = {3rd, adult}
	C22 = {3rd, child}
	C23 = {3rd, survived}
	C24 = {3rd, dead}
	C25 = {survived, male}
	C26 = {survived, female}
	C27 = {survived, adult}
	C28 = {survived, child}
	
	
	//Compare itemsets (Sex & Survived) || Eventually place this in seperate function
	for(j = 0; j < (i+1); j++)
	{
		C1[j][k] = titanic.tsex[j]; //Place Passenger class data in first column of C1
	}
	k++;
	for (j = 0; j < (i+1); j++)
	{
		C1[j][k] = titanic.tsurvived[j]; //Place gender data in second column of C1
	}								     // C1[35][1] =  0 (Male)   || C1[35][2] = 0 (!survived)
	  									 // C1[36][1] =  1 (Female) || C1[36][2] = 0 (!survived)

	int min_support = 50;
	vector<int> L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, L13, L14;
	
	int C1_supportCount_maleDead = 0;
	int C1_supportCount_femaleDead = 0;
	int C1_supportCount_maleSurvived = 0;
	int C1_supportCount_femaleSurvived = 0;
	
	//if male and dead, add to maleDead support count
	if(C1[j][1] == 0 && C1[j][2] == 0)
	{
		C1_supportCount_maleDead++;
	}
	//if male and survived, add to maleSurvived support count
	else if (C1[j][1] == 0 && C1[j][2] == 1)
	{
		C1_supportCount_maleSurvived++;
	}
	//if female and dead, add to femaleDead support count
	else if(C1[j][1] == 1 && C1[j][2] == 0)
	{
		C1_supportCount_femaleDead++;
	}
	//if female and survived, add to femaleSurvived support count
	else if(C1[j][1] == 1 && C1[j][2] == 1)
	{
		C1_supportCount_femaleSurvived++;
	}
	
	//Compare supportCount with min_support
	if(C1_supportCount_maleDead >= min_support)
	{
		L1 = C1;
	}
	if(C1_supportCount_maleSurvived >= min_support)
	{
		L1 = C1;
	}
	if(C1_supportCount_femaleDead >= min_support)
	{
		L1 = C1;
	}
	if(C1_supportCount_femaleSurvived >= min_support)
	{
		L1 = C1;
	}