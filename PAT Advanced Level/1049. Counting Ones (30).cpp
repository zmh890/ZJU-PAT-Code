/*
The task is simple: given any positive integer N, you are supposed to count the total number of 1's in the decimal form of the integers from 1 to N. For example, given N being 12, there are five 1's in 1, 10, 11, and 12.

Input Specification:

Each input file contains one test case which gives the positive N (<=230).

Output Specification:

For each test case, print the number of 1's in one line.

Sample Input:
12
Sample Output:
5
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

int main()
{
	//fstream cin("F://test.txt");
	int N;
	int icount = 0,ilowernum,ihighernum,icurnum;
	int ifactor = 1;
	cin >> N;//如果想在满足条件 就不能遍历 而是分析数字 
	while(N/ifactor != 0)//分析每一位上出现1的情况 与这一位的数字有关系 
	{
		ilowernum = N - N/ifactor*ifactor;
		ihighernum= N/ifactor/10;
		icurnum = (N/ifactor)%10;
		switch(icurnum)
		{
		case 0:		//如果当前位数字是0 只跟当前位的高位有关系
			icount += ihighernum*ifactor;break;
		case 1:		//如果是1 跟高位和低位都有关系
			icount += ihighernum*ifactor + ilowernum+1;break;
		default:	//其他情况 只跟高位有关 但是 要注意 比0多一种情况
			icount += (ihighernum+1)*ifactor;break;
		}
		ifactor *= 10;
	}
	cout << icount;
	system("pause");
	return 0;
}