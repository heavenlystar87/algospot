#include <iostream>
using namespace std;

int main()
{
	int testCase;
	int** scoreBoard;
	int* result;

	scanf("%d", &testCase);
	
	scoreBoard = new int*[testCase];
	result = new int[testCase];

	for(int i = 0; i < testCase; i++)
	{
		scoreBoard[i] = new int[2];

		scanf("%d", &scoreBoard[i][0]);
		scanf("%d", &scoreBoard[i][1]);

		int diffScore = scoreBoard[i][1] - scoreBoard[i][0];

		if(diffScore >= 0)
			result[i] = diffScore + 4;
		else
			result[i] = 0;
	}



	for(int i = 0; i < testCase; i++)
	{
		printf("%d\n", result[i]);
		delete [] scoreBoard[i];
	}
	delete [] scoreBoard;
	delete [] result;
	return 0;
}