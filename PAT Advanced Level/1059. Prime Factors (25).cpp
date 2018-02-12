/*
Given any positive integer N, you are supposed to find all of its prime factors, and write them in the format N = p1^k1 * p2^k2 *…*pm^km.

Input Specification:

Each input file contains one test case which gives a positive integer N in the range of long int.

Output Specification:

Factor N in the format N = p1^k1 * p2^k2 *…*pm^km, where pi's are prime factors of N in increasing order, and the exponent ki is the number of pi -- hence when there is only one pi, ki is 1 and must NOT be printed out.

Sample Input:
97532468
Sample Output:
97532468=2^2*11*17*101*1291
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <cstring>
#include <list>
#include <map>
#include <set>
#include <fstream>
#include <iomanip>
using namespace std;
int main()
{
	//fstream cin("F://test.txt");	
	long n;
	cin >> n;
	cout << n << "=";
	if(n == 1) {cout << 1;return 0;}
	int start = 2;
	int flag = 1;
	while(n != 1 && n != 0)
	{
		int count = 0;int i = start;
		int now;
		for(;i <= n;i++)    //从小到大(从2开始)最先能整除n的除数必然是一个素数 
			if(n%i == 0) 
			{
				now = i;count++;n/= i;
				while(n != 1 && n != 0)
					if(n%i == 0) {n /= i;count++;}
					else break;
				if(count > 1 && flag) cout << now << "^" << count,flag = 0;
				else if(flag) cout << now,flag = 0;
				else if(count > 1)	cout << "*" << now << "^" << count;
				else cout << "*" << now;
					
				break;
			}
	}
	system("pause");
	return 0;
}