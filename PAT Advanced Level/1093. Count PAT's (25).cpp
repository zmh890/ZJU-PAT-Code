/*
The string APPAPT contains two PAT's as substrings. The first one is formed by the 2nd, the 4th, and the 6th characters, and the second one is formed by the 3rd, the 4th, and the 6th characters.

Now given any string, you are supposed to tell the number of PAT's contained in the string.

Input Specification:

Each input file contains one test case. For each case, there is only one line giving a string of no more than 105 characters containing only P, A, or T.

Output Specification:

For each test case, print in one line the number of PAT's contained in the string. Since the result may be a huge number, you only have to output the result moded by 1000000007.

Sample Input:
APPAPT
Sample Output:
2
*/
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
	//fstream cin("F://test.txt");
	string s;
	long long sum = 0;
	cin >> s;
	long long cntP = 0,cntA = 0,cntT = 0;
	int i = 0;
	while(s[i] != 'P') i++;
	for(;i < s.size();i++)//遇到P直接+1 遇到A加上当前P的数量 遇到T加上当前A的数量
		if(s[i] == 'P') cntP++;
		else if(s[i] == 'A') cntA += cntP;
		else if(s[i] == 'T') cntT = (cntT + cntA)%1000000007;
	cout << cntT;
	system("pause");
	return 0;
}