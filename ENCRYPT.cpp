#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int testCase;

	char inputStr[10][101];
	char outputStr[10][101];

	scanf("%d", &testCase);

	for(int i = 0; i < testCase; i++)
	{
		scanf("%s", inputStr[i]);

		int strLen = strlen(inputStr[i]);
		int idx = 0;
		int preIdx = 0;
		int postIdx = 0;
		char postStr[101];

		while(inputStr[i][idx] != '\0')
		{
			if(idx%2 == 0)
				outputStr[i][preIdx++] = inputStr[i][idx++];
			else
				postStr[postIdx++] = inputStr[i][idx++];
		}
		outputStr[i][preIdx] = '\0';
		postStr[postIdx] = '\0';
		strcat(outputStr[i], postStr);
	}

	for(int i = 0; i < testCase; i++)
	{
		printf("%s\n", outputStr[i]);
	}

	return 0;
}