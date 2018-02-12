/*
A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. For example, 1234321 is a palindromic number. All single digit numbers are palindromic numbers.

Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the non-palindromic number is reversed and the result is added to the original number. If the result is not a palindromic number, this is repeated until it gives a palindromic number. For example, if we start from 67, we can obtain a palindromic number in 2 steps: 67 + 76 = 143, and 143 + 341 = 484.

Given any positive integer N, you are supposed to find its paired palindromic number and the number of steps taken to find it.

Input Specification:

Each input file contains one test case. Each case consists of two positive numbers N and K, where N (<= 1010) is the initial numer and K (<= 100) is the maximum number of steps. The numbers are separated by a space.

Output Specification:

For each test case, output two numbers, one in each line. The first number is the paired palindromic number of N, and the second number is the number of steps taken to find the palindromic number. If the palindromic number is not found after K steps, just output the number obtained at the Kth step and K instead.

Sample Input 1:
67 3
Sample Output 1:
484
2
Sample Input 2:
69 3
Sample Output 2:
1353
3
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cctype>
#include <queue>
#include <stack>
#include <cstring>
#include <list>
#include <set>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

bool ispalin(string s)
{
	if(s.size() < 1) return false;
	if(s.size() == 1)return true;
	else
	{
		string::iterator it1 = s.begin(),it2 = s.end()-1;
		while(it1 < it2)
		{
			if(*it1 != *it2)
				return false;
			it1++;it2--;
		}
		return true;
	}
}
string sadd(string& s1,string& s2)
{
	string tmpadd;
	int carry = 0;
	for(int i = s1.size()-1;i >= 0;i--)
	{
		int tmp = (s1[i] - '0') + (s2[i] - '0') + carry;
		carry = tmp/10;
		tmp = tmp%10;
		tmpadd.push_back(tmp+'0');
	}
	if(carry) tmpadd.push_back(carry+'0');
	reverse(tmpadd.begin(),tmpadd.end());
	return tmpadd;
}
int main()
{
	//fstream cin("F://DL.txt");
	string origin,reorigin;
	int steps,nowstep = 0;
	cin >> origin >> steps;
	
	while(nowstep < steps)
	{
		if(ispalin(origin))
			{cout << origin << endl << nowstep;system("pause");return 0;}
		reorigin = origin;
		reverse(reorigin.begin(),reorigin.end());
		origin = sadd(origin,reorigin);
		nowstep++;
	}
	if(ispalin(origin))
		{cout << origin << endl << nowstep;system("pause");return 0;}
	cout << origin << endl << steps;
	system("pause");
	return 0;
}