/*
Given a string, you are supposed to output the length of the longest symmetric sub-string. For example, given "Is PAT&TAP symmetric?", the longest symmetric sub-string is "s PAT&TAP s", hence you must output 11.

Input Specification:

Each input file contains one test case which gives a non-empty string of length no more than 1000.

Output Specification:

For each test case, simply print the maximum length in a line.

Sample Input:
Is PAT&TAP symmetric?
Sample Output:
11
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
#include <map>
#include <set>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

bool isymmme(string t)
{
	if(t.empty())	return false;
	if(t.size() == 1) return true;
	string::iterator it1 = t.begin();
	string::iterator it2 = t.end()-1;
	while(it1 < it2)
		if(*it1 == *it2) it1++,it2--;
		else {return false;}
	return true;
}
int main()
{
	//fstream cin("F://test.txt");
	string s;
	getline(cin,s);
	int longest = s.size();
	while(longest)
	{
		for(int i = 0;i + longest <= s.size();i++)
			if(isymmme(s.substr(i,longest)))
				{cout << longest;system("pause");return 0;}
		longest--;
	}
	
	system("pause");
	return 0;
}