/*
Being unique is so important to people on Mars that even their lottery is designed in a unique way. The rule of winning is simple: one bets on a number chosen from [1, 104]. The first one who bets on a unique number wins. For example, if there are 7 people betting on 5 31 5 88 67 88 17, then the second one who bets on 31 wins.

Input Specification:

Each input file contains one test case. Each case contains a line which begins with a positive integer N (<=105) and then followed by N bets. The numbers are separated by a space.

Output Specification:

For each test case, print the winning number in a line. If there is no winner, print "None" instead.

Sample Input 1:
7 5 31 5 88 67 88 17
Sample Output 1:
31
Sample Input 2:
5 888 666 666 888 888
Sample Output 2:
None
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

vector<int> cnts(10005,0);//大面积定义数组 以空间换时间
vector<int> uniq;
int main()
{
	//fstream cin("F://test.txt");
	int N;
	cin >> N;
	for(int i = 0;i < N;i++)
	{
		int tmp;
		cin >> tmp;
		cnts[tmp]++;
		if(cnts[tmp] > 1)
		{
			for(vector<int>::iterator it = uniq.begin();it != uniq.end();it++)
				if(*it == tmp) {uniq.erase(it);break;}
		}
		else
			uniq.push_back(tmp);
	}
	if(uniq.empty())	cout << "None";
	else cout << uniq[0];
	system("pause");
	return 0;
}