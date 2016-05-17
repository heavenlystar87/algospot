#include <iostream>
using namespace std;

int main()
{
	int testCase;
	scanf("%d", &testCase);

	int** testSeq = new int*[testCase];
	int* result = new int[testCase];

	for(int i = 0; i < testCase; i++)
	{
		int numIdx;
		scanf("%d", &numIdx);

		testSeq[i] = new int[numIdx];
		result[i] = 0;

		for(int j = 0; j < numIdx; j++)
		{
			scanf("%d", &testSeq[i][j]);
			if(testSeq[i][j] == j + 1)
				result[i]++;
		}
	}

	for(int i = 0; i < testCase; i++)
	{
		printf("%d\n", result[i]);
	}
	return 0;
}