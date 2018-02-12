/*
For any 4-digit integer except the ones with all the digits being the same, if we sort the digits in non-increasing order first, and then in non-decreasing order, a new number can be obtained by taking the second number from the first one. Repeat in this manner we will soon end up at the number 6174 -- the "black hole" of 4-digit numbers. This number is named Kaprekar Constant.

For example, start from 6767, we'll get:

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
... ...

Given any 4-digit number, you are supposed to illustrate the way it gets into the black hole.

Input Specification:

Each input file contains one test case which gives a positive integer N in the range (0, 10000).

Output Specification:

If all the 4 digits of N are the same, print in one line the equation "N - N = 0000". Else print each step of calculation in a line until 6174 comes out as the difference. All the numbers must be printed as 4-digit numbers.

Sample Input 1:
6767
Sample Output 1:
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
Sample Input 2:
2222
Sample Output 2:
2222 - 2222 = 0000
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <cstring>
#include <cctype>
#include <list>
#include <map>
#include <set>
#include <fstream>
#include <iomanip>
using namespace std;
string strminus(string& big,string& small)
{
	if(big == small) return "0000";
	int res = 0,factor = 1000;
	string strres;
	for(int i = 0;i < 4;i++)
	{
		res += (big[i]-small[i])*factor;
		factor /= 10;
	}
	while(res)
	{
		strres = (char)('0'+res%10) + strres;
		res /= 10;
	}
	while(strres.size() < 4) strres = "0" + strres;
	return strres;
}
int main()
{
	//fstream cin("F://test.txt");
	string s;
	cin >> s;
	while(s.size() < 4) s = "0" + s;
	if(s == "6174")//测试点5 直接输入6174
	{
		cout << "7641 - 1467 = 6174";system("pause");return 0;
	}
	else if(s == "0000")
	{
		cout << "0000 - 0000 = 0000";system("pause");return 0;
	}
	while(s != "6174" && s != "0000")
	{
		string big = s,small = s;
		sort(big.begin(),big.end(),greater<char>());
		sort(small.begin(),small.end());
		s = strminus(big,small);
		cout << big << " - " << small << " = " << s << endl;
	}
	system("pause");
	return 0;
}