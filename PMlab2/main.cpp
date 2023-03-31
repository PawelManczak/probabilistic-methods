#include <cmath>
#include <iostream>
using namespace std;

int pr_distribution1[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int pr_distribution2[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
bool beginning[7] = { 1, 0, 0, 1, 0, 1, 1 };

int p = 7;
int c = 3;


int random1 (long int x, long int c, long int a, long int M, int counter)
{

  int interval = floor ((10 * x) / double (M));
  pr_distribution1[interval]++;

  if (counter == 0)
    return x;

  random1 ((a * x + c) % M, c, a, M, --counter);

}

unsigned int Mm = 2147483647;

int random2 (bool beginning[7], int counter)
{

  if (counter == 0)
    return 1;

  bool numberToReturn[31];
  for (int i = 0; i < 31; i++)
    numberToReturn[i] = 0;

  for (int i = 0; i < 7; i++)
    {
      numberToReturn[i] = beginning[i];
    }

  for (int i = 7; i < 31; i++)
    {
      numberToReturn[i] = numberToReturn[i - c] xor numberToReturn[i - p];
    }				


  unsigned int result = 0;
  for (int i = 0; i < 31; i++)
    {
      if (numberToReturn[i])
        	result += pow (2, 31 - i);
    }

  unsigned int interval = (double) result / Mm * 10;
  pr_distribution2[interval % 10]++;

  bool ending[7];
  for (int i = 0; i < 7; i++)
    ending[i] = 0;

  for (int i = 0; i < 7; i++)
    {
      ending[i] = numberToReturn[31 - 7 + i];
    }

  random2 (ending, --counter);
}


int main ()
{


  int first = random1 (15, 1, 69069, 2147483648, 100000);

  for (int i = 0; i < 10; i++)
    {
      cout << i << " - " << pr_distribution1[i] << endl;
    }

  cout << endl << endl;
  int second = random2 (beginning, 10000);

  for (int i = 0; i < 10; i++)
    {
      cout << i << " - " << pr_distribution2[i] << endl;
    }
    
  return 0;
}
