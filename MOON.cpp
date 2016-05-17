#include <iostream>
#include <math.h>
using namespace std;

double PI = acos(-1.0);
double getAngleFromCosLaw2(double rad1, double rad2, double rad3);

int main() {
	// your code goes here
	int testCase;
	
	scanf("%d", &testCase);
	
	int *M = new int[testCase];
	int *S = new int[testCase];
	int *C = new int[testCase];
	double* result = new double[testCase];
	
	for(int i = 0; i < testCase; i++)
	{
		scanf("%d %d %d", &M[i], &S[i], &C[i]);
	}
	
	for(int i = 0; i < testCase; i++)
	{
		//M ¹ÝÁö¸§ È£ÀÇ ³ÐÀÌ - »ï°¢ÇüÀÇ ³ÐÀÌ * 2
		double angleM = getAngleFromCosLaw2(S[i], M[i], C[i]);
		double arcSquareM = M[i] * M[i] * angleM;
		double triSquareM = M[i] * cos(angleM) * M[i] * sin(angleM);
		double diffM = arcSquareM - triSquareM;
		
		//S ¹ÝÁö¸§ È£ÀÇ ³ÐÀÌ - »ï°¢ÇüÀÇ ³ÐÀÌ * 2
		double angleS = getAngleFromCosLaw2(M[i], S[i], C[i]);
		double arcSquareS = S[i] * S[i] * angleS;
		double triSquareS = S[i] * cos(angleS) * S[i] * sin(angleS);
		double diffS = arcSquareS - triSquareS;
		
		result[i] = M[i] * M[i] * PI - diffM - diffS;
	}
	
	for(int i = 0; i < testCase; i++)
	{
		printf("%.3f\n", result[i]);
	}
	delete []M;
	delete []S;
	delete []C;
	delete []result;
	
	return 0;
}

double getAngleFromCosLaw2(double rad1, double rad2, double rad3)
{
	return acos(((rad2 * rad2 + rad3 * rad3 - rad1 * rad1)) / (2*rad2*rad3));
}