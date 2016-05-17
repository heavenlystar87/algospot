#include <iostream>
using namespace std;

long buf[3] = {0};

long CALIVAL = 1000000007;

int Fibonacci(int num);

int main()
{
	int numCase = 0;
	int* numIter = 0;

	cin >> numCase;

	numIter = new int[numCase];

	for(int i = 0; i < numCase; i++)
	{
		cin >> numIter[i];
	}

	for(int i = 0; i < numCase; i++)
	{
		int lmt = numIter[i];
		if(lmt == 1)
		{
			cout << 1 << endl;
		}
		else if(lmt == 2)
		{
			cout << 2 << endl;
		}
		else
		{
			int cnt = 3;
			buf[1] = 1;
			buf[2] = 2;
			int arrIter = -1;
			while(cnt <= lmt)
			{
				arrIter = (arrIter + 1) % 3;
				buf[arrIter] = (buf[(arrIter + 1) % 3] + buf[(arrIter + 2) % 3])%CALIVAL;
				cnt++;
			}
			cout << buf[arrIter]<< endl;
		}
	}
	return 0;
}