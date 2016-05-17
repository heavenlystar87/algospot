#include <iostream>
using namespace std;
//temp
int main()
{
	char binaryArray[1000001];
	int countZeroOne[1000001];

	int testCase = 0;
	int lowIdx, highIdx;
	scanf("%s", binaryArray);
	scanf("%d", &testCase);
	bool* result = new bool[testCase];

	countZeroOne[0] = 1;

	for(int i = 0, j = 1; binaryArray[j]; j++)
	{
		if(binaryArray[i] != binaryArray[j])
		{
			i = j;
			countZeroOne[j] = 1;
		}
		else
		{
			countZeroOne[j] = countZeroOne[j-1] + 1;
		}
	}

	for(int i = 0; i < testCase; i++)
	{
		scanf("%d", &lowIdx);
		scanf("%d", &highIdx);

		int diff = abs(lowIdx - highIdx);
		
		result[i] = (diff < countZeroOne[(lowIdx > highIdx)? lowIdx:highIdx]);
	}

	for(int i = 0; i < testCase; i++)
	{
		if(result[i])
			printf("Yes\n");
		else
			printf("No\n");
	}
	delete[] result;
	
	return 0;
}
