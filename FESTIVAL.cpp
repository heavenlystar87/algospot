#include <iostream>
using namespace std;

double CalcMinCost(int iNumDays, int iNumTeam, int* aiCost);

int main()
{
	int iNumTestCase = 0;
	int* aiNumDays = 0;
	int* aiNumTeams = 0;
	int** aiCost = 0;

	//get test case number
	cin >> iNumTestCase;

	if(iNumTestCase > 100 || iNumTestCase < 1)
	{
		return 0;
	}

	aiNumDays = new int [iNumTestCase];
	aiNumTeams = new int [iNumTestCase];
	aiCost = new int*[iNumTestCase];

	for(int i = 0; i < iNumTestCase; i++)
	{
		//get number of days and team
		cin >> aiNumDays[i] >> aiNumTeams[i];

		if(aiNumDays[i] >= 1 && aiNumDays[i] <= 1000 
			&& aiNumTeams[i] >= 1 && aiNumTeams[i] <= aiNumDays[i])
		{
			aiCost[i] = new int[aiNumDays[i]];
			for(int j = 0; j < aiNumDays[i]; j++)
			{
				cin >> aiCost[i][j];
			}
		}
		else
		{
			return 0;
		}
	}

	for(int i = 0; i < iNumTestCase; i++)
	{
			printf("%.12f\n", CalcMinCost(aiNumDays[i], aiNumTeams[i], aiCost[i]));
			delete [] aiCost[i];
	}
	delete [] aiCost;
	delete [] aiNumTeams;
	delete [] aiNumDays;
	return 0;
}

double CalcMinCost(int iNumDays, int iNumTeam, int* aiCost)
{
	double dMinCost = 1000;
	double dCost = 0;
	int sum = 0;
	
	//최소 공연 일부터 최대 공연 일까지
	for(int iDays = iNumTeam; iDays < iNumDays + 1; iDays++)
	{	
		for(int i = 0; i + iDays - 1< iNumDays; i++)
		{
			sum = 0;
			for(int j = i; j < i + iDays; j++)
			{
				sum += aiCost[j];
			}
			dCost = ((double)sum/(double)iDays);
			if(dMinCost > dCost)
			{
				dMinCost = dCost;
			}
		}
	}
	return dMinCost;
}