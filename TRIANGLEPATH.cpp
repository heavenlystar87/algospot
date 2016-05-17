#include <iostream>
using namespace std;

int main()
{
  int testCase;
  scanf("%d", &testCase);
  int *result = new int[testCase];

  for(int numTest = 0; numTest < testCase; numTest++)
  {
    int depth;
    scanf("%d", &depth);
    
    int **a = new int*[depth];

    for(int i = 0; i < depth; i++)
    {
      a[i] = new int [i + 1];
      
      for(int j = 0; j < i + 1; j++)
      {
        scanf("%d", &a[i][j]);
      }
    }
    
    for(int i = depth - 2; i >= 0; i--)
    {
      for(int j = 0; j <= i; j++)
      {
        a[i][j] += ((a[i+1][j] > a[i+1][j+1])? a[i+1][j] : a[i+1][j+1]);
      }
    }
    result[numTest] = a[0][0];
    for(int i = 0; i < depth; i++)
    {
       delete [] a[i];
    }
    delete [] a;
  }

  for(int i = 0; i < testCase; i++)
  {
    printf("%d\n", result[i]);
  }
  delete [] result;
  return 0;
}