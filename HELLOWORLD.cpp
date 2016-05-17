#include <iostream>

using namespace std;

int main()
{
	int iTestCase;

	scanf("%d", &iTestCase);

	char nameList[50][50];

	for(int i = 0; i < iTestCase; i++)
	{
		scanf("%s", nameList[i]);
		printf("Hello, %s!\n", nameList[i]);
	}

	return 0;
}