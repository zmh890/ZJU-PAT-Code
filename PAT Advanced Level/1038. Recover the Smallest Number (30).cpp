/*
Given a collection of number segments, you are supposed to recover the smallest number from them. For example, given {32, 321, 3214, 0229, 87}, we can recover many numbers such like 32-321-3214-0229-87 or 0229-32-87-321-3214 with respect to different orders of combinations of these segments, and the smallest number is 0229-321-3214-32-87.

Input Specification:

Each input file contains one test case. Each case gives a positive integer N (<=10000) followed by N number segments. Each segment contains a non-negative integer of no more than 8 digits. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print the smallest number in one line. Do not output leading zeros.

Sample Input:
5 32 321 3214 0229 87
Sample Output:
22932132143287
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
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;
vector<string> v;
bool cmp(const string& s1,const string& s2)
	//oh shit 没想到解法竟然这么简答 还以为是拓扑排序 。。。分析问题的能力还是不够啊！！！！
{
	return s1+s2 < s2+s1;
}
int main()
{
	//fstream cin("F://test.txt");
	int N;
	cin >> N;
	v.reserve(N);
	for(int i = 0;i < N;i++)
	{
		string tmp;
		cin >> tmp;v.push_back(tmp);
	}
	sort(v.begin(),v.end(),cmp);
	string ans;
	for(int i = 0;i < v.size();i++)
		ans += v[i];
	int t = 0;
	while(ans[t] == '0')	t++;
	ans = ans.substr(t);
	if(ans.empty()) cout << "0";
	else cout << ans;
	system("pause");
	return 0;
}