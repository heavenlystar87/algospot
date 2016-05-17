#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int testCase;
	
	scanf("%d", &testCase);

	int** xCoord = new int*[testCase];
	int** yCoord = new int*[testCase];
	
	int* resultX = new int[testCase];
	int* resultY = new int[testCase];
	
	for(int i = 0; i < testCase; i++)
	{
		xCoord[i] = new int [3];	
		yCoord[i] = new int [3];
		for(int j = 0; j < 3; j++)
			scanf("%d %d", &xCoord[i][j], &yCoord[i][j]);
	}
	
	for(int i = 0; i < testCase; i++)
	{
		
		if(xCoord[i][0] == xCoord[i][1])
		{
			resultX[i] = xCoord[i][2];
		}
		else if(xCoord[i][1] == xCoord[i][2])
		{
			resultX[i] = xCoord[i][0];
		}
		else
		{
			resultX[i] = xCoord[i][1];
		}
		
		if(yCoord[i][0] == yCoord[i][1])
		{
			resultY[i] = yCoord[i][2];
		}
		else if(yCoord[i][1] == yCoord[i][2])
		{
			resultY[i] = yCoord[i][0];
		}
		else
		{
			resultY[i] = yCoord[i][1];
		}
	}
	
	for(int i = 0; i < testCase; i++)
	{
		printf("%d %d\n", resultX[i], resultY[i]);
		delete[] xCoord[i];
		delete[] yCoord[i];
	}
	
	delete[] xCoord;
	delete[] yCoord;
	
	return 0;
}