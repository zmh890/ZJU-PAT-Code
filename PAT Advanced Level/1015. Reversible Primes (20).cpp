/*
A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.

Now given any two positive integers N (< 105) and D (1 < D <= 10), you are supposed to tell if N is a reversible prime with radix D.

Input Specification:

The input file consists of several test cases. Each case occupies a line which contains two integers N and D. The input is finished by a negative N.

Output Specification:

For each test case, print in one line "Yes" if N is a reversible prime with radix D, or "No" if not.

Sample Input:
73 10
23 2
23 10
-2
Sample Output:
Yes
Yes
No
*/
#include <iostream>
#include <string>
using namespace std;

int isprime(long m)
{
  if(m <= 1) return 0;
  else if(m == 2) return 1;
  else
  {
    for(int i = 2;i*i <= m;i++)
      if(m%i == 0)
        return 0;
  }
  return 1;
}
int main()
{
  long prime,radix;
  while(1)
  {
    cin >> prime;
    if(prime > 0)
    {
      cin >> radix;
      if(!isprime(prime))
        cout << "No" << endl;
      else
      {
        long reverseprime = 0;
        string tmp;
        while(prime > 0)
        {
          tmp += prime % radix + '0';
          prime /= radix;
        }
        for(int i = 0;i < tmp.size();i++)
          reverseprime = reverseprime*radix + (tmp[i] - '0');
        if(isprime(reverseprime))
          cout << "Yes" << endl;
        else
          cout << "No" << endl;
      }
    }
    else 
      break;
  }

  system("pause");
  return 0;
}