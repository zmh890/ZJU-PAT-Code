/*
Sherlock Holmes received a note with some strange strings: "Let's date! 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm". It took him only a minute to figure out that those strange strings are actually referring to the coded time "Thursday 14:04" -- since the first common capital English letter (case sensitive) shared by the first two strings is the 4th capital letter 'D', representing the 4th day in a week; the second common character is the 5th capital letter 'E', representing the 14th hour (hence the hours from 0 to 23 in a day are represented by the numbers from 0 to 9 and the capital letters from A to N, respectively); and the English letter shared by the last two strings is 's' at the 4th position, representing the 4th minute. Now given two pairs of strings, you are supposed to help Sherlock decode the dating time.

Input Specification:

Each input file contains one test case. Each case gives 4 non-empty strings of no more than 60 characters without white space in 4 lines.

Output Specification:

For each test case, print the decoded time in one line, in the format "DAY HH:MM", where "DAY" is a 3-character abbreviation for the days in a week -- that is, "MON" for Monday, "TUE" for Tuesday, "WED" for Wednesday, "THU" for Thursday, "FRI" for Friday, "SAT" for Saturday, and "SUN" for Sunday. It is guaranteed that the result is unique for each case.

Sample Input:
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm
Sample Output:
THU 14:04
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

int main()
{
	//fstream cin("F://test.txt");
	char week[7][4] = 
	{
		"MON","TUE","WED","THU","FRI","SAT","SUN"
	};
	string s1,s2;
	string str1,str2;
	getline(cin,s1);getline(cin,s2);
	getline(cin,str1);getline(cin,str2);
	int i;
	//做题要根据题意 严格限定边界 不能越界 也不能留边界空间
	for(i = 0;i < s1.size() && i < s2.size();i++)
		if(s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G')//测试点4 表示日期的大写字符要在A-G之间
			break;
	cout << week[(s1[i] - 'A')%7] << " ";
	for(i = i + 1;i < s1.size() && i < s2.size();i++)
		if(s1[i] == s2[i] && (isdigit(s1[i]) || s1[i] >= 'A' && s1[i] <= 'N'))//测试点2 时的大写字符要在A-N之间
			break;
	if(isdigit(s1[i]))
		cout << "0" << s1[i] << ":";
	else if(isupper(s1[i]))
		cout << (s1[i] - 'A' + 10) << ":";
	for(i = 0;i < str1.size() && i < str2.size();i++)
		if(str1[i] == str2[i] && isalpha(str1[i]))
				break;
	if(i < 10) cout << "0" << i;
	else cout << i;
	system("pause");
	return 0;
}