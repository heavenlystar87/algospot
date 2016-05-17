#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calcStrJoinMinCost(int iNumStr, int* aiNumChar);
bool comp(int i, int j);

int main()
{
	int iNumTestCase = 0;
	int iNumStr = 0;
	int** imatNumChar = 0;
	int* aiResult = 0;

	//get test case
	cin >> iNumTestCase;

	imatNumChar = new int*[iNumTestCase];
	aiResult = new int[iNumTestCase];

	for(int i = 0; i < iNumTestCase; i++)
	{
		//get num of strings
		cin >> iNumStr;

		imatNumChar[i] = new int[iNumStr];
		
		for(int j = 0; j < iNumStr; j++)
		{
			cin >> imatNumChar[i][j];
		}
		aiResult[i] = calcStrJoinMinCost(iNumStr, imatNumChar[i]);

		delete[] imatNumChar[i];
	}

	for(int i = 0; i < iNumTestCase; i++)
	{
		cout <<  aiResult[i] << endl;
	}

	delete[] imatNumChar;
	delete[] aiResult;
	return 0;
}

bool comp(int i, int j)
{
	return (i > j);
}

int calcStrJoinMinCost(int iNumStr, int* aiNumChar)
{
	int result = 0;

	int min = 1001;
	int minIdx = -1;
	int nextMin = 1002;
	int nextMinIdx = -1;
	int cost = 0;
	int iterator = iNumStr - 1;

	//copy array
	int* tempArray = new int[iNumStr];

	vector<int> vec_data;

	for(int i = 0; i < iNumStr; i++)
	{
		vec_data.push_back(aiNumChar[i]);
	}

	do{
		cost = 0;
		sort(vec_data.begin(), vec_data.end(), comp);
		cost += vec_data.back();
		vec_data.pop_back();
		cost += vec_data.back();
		vec_data.pop_back();
		vec_data.insert(vec_data.end(), cost);
		result += cost;
	}while(vec_data.size() > 1);
	return result;
}