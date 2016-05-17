#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int testCase;
	int* aimElecUse;
	bool* result;
	
	scanf("%d", &testCase);
	aimElecUse = new int[testCase];
	result = new bool[testCase];
	
	for(int i = 0; i < testCase; i++)
	{
		scanf("%d", &aimElecUse[i]);
		
		int sum = 0;
		int temp = 0;
		
		for(int j = 0; j < 9; j++)
		{
			scanf("%d", &temp);
			sum += temp;
		}
		result[i] = (aimElecUse[i] >= sum);
	}
	
	for(int i = 0; i < testCase; i++)
	{
		if(result[i])
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	delete [] aimElecUse;
	delete [] result;
	
	return 0;
}