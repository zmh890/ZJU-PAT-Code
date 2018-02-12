/*
Given three integers A, B and C in [-2^63, 2^63], you are supposed to tell whether A+B > C.

Input Specification:

The first line of the input gives the positive number of test cases, T (<=10). Then T test cases follow, each consists of a single line containing three integers A, B and C, separated by single spaces.

Output Specification:

For each test case, output in one line "Case #X: true" if A+B>C, or "Case #X: false" otherwise, where X is the case number (starting from 1).

Sample Input:
3
1 2 3
2 3 4
9223372036854775807 -9223372036854775808 0
Sample Output:
Case #1: false
Case #2: true
Case #3: false
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
	int T;
	cin >> T;
	long long a,b,c;
	bool flag,overflow = false;
	for(int i = 1;i <= T;i++)
	{
		cin >> a >> b >> c;
		long long sum = a + b;
		//本题的关键在于 只需要将两种溢出的情况考虑到（正+正 负+负）单独拿出来
		//其他的情况都可以正常判断 注意long long的范围 -2^63 -- 2^63-1
		if(a > 0 && b > 0 && sum <= 0)
			flag = true;
		else if(a < 0 && b < 0 && sum >= 0)
			flag = false;
		else
			flag = sum > c?true:false;
		cout << "Case #" << i << ": ";
		cout << (flag?"true":"false") << endl;
	}
	system("pause");
	return 0;
}