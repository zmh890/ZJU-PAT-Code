/*
Given two strings S1 and S2, S = S1 - S2 is defined to be the remaining string after taking all the characters in S2 from S1. Your task is simply to calculate S1 - S2 for any given strings. However, it might not be that simple to do it fast.

Input Specification:

Each input file contains one test case. Each case consists of two lines which gives S1 and S2, respectively. The string lengths of both strings are no more than 104. It is guaranteed that all the characters are visible ASCII codes and white space, and a new line character signals the end of a string.

Output Specification:

For each test case, print S1 - S2 in one line.

Sample Input:
They are students.
aeiou
Sample Output:
Thy r stdnts.
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
int counts[500];//就是要用空间换时间 大面积设置数组 直接查找
int main()
{
	//fstream cin("F://test.txt");
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	for(int i = 0;i < s2.size();i++)
		counts[(int)s2[i]]++;
	for(int i = 0;i < s1.size();i++)
		if(!counts[(int)s1[i]]) printf("%c",s1[i]);
	system("pause");
	return 0;
}