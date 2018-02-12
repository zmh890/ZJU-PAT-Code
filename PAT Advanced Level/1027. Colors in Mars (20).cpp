/*
People in Mars represent the colors in their computers in a similar way as the Earth people. That is, a color is represented by a 6-digit number, where the first 2 digits are for Red, the middle 2 digits for Green, and the last 2 digits for Blue. The only difference is that they use radix 13 (0-9 and A-C) instead of 16. Now given a color in three decimal numbers (each between 0 and 168), you are supposed to output their Mars RGB values.

Input

Each input file contains one test case which occupies a line containing the three decimal color values.

Output

For each test case you should output the Mars RGB value in the following format: first output "#", then followed by a 6-digit number where all the English characters must be upper-cased. If a single color is only 1-digit long, you must print a "0" to the left.

Sample Input
15 43 71
Sample Output
#123456
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
int R,G,B;
char change(int m)
{
	if(m >= 0 && m <= 9)
		return ('0'+m);
	else if(m == 10)
		return 'A';
	else if(m == 11)
		return 'B';
	else 
		return 'C';
}
string trans(int n)
{
	int dec = n/13;
	int sig = n%13;
	string tmp;
	tmp.push_back(change(dec));
	tmp.push_back(change(sig));
	return tmp;
}
int main()
{
	//fstream cin("F://tennis.txt");
	cin >> R >> G >> B;
	string ans = trans(R) + trans(G) + trans(B);
	cout << '#' << ans;
	system("pause");
	return 0;
}