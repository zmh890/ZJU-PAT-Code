/*
Given a pair of positive integers, for example, 6 and 110, can this equation 6 = 110 be true? The answer is "yes", if 6 is a decimal number and 110 is a binary number.

Now for any pair of positive integers N1 and N2, your task is to find the radix of one number while that of the other is given.

Input Specification:

Each input file contains one test case. Each case occupies a line which contains 4 positive integers:
N1 N2 tag radix
Here N1 and N2 each has no more than 10 digits. A digit is less than its radix and is chosen from the set {0-9, a-z} where 0-9 represent the decimal numbers 0-9, and a-z represent the decimal numbers 10-35. The last number "radix" is the radix of N1 if "tag" is 1, or of N2 if "tag" is 2.

Output Specification:

For each test case, print in one line the radix of the other number so that the equation N1 = N2 is true. If the equation is impossible, print "Impossible". If the solution is not unique, output the smallest possible radix.

Sample Input 1:
6 110 1 10
Sample Output 1:
2
Sample Input 2:
1 ab 1 2
Sample Output 2:
Impossible
*/
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <fstream>
using namespace std;

long long changetodec(string s,long long r)
{
	long long sum = 0;
	long long radix = 1;
	int tmp;
	for(int i = s.size() - 1;i >= 0;i--)
	{
		if(s[i] <= '9' && s[i] >= '0')
			tmp = s[i] - '0';
		else 
			tmp = s[i] - 'a' + 10;
		sum += tmp*radix;
		radix *= r;
	}
	return sum;
}
long long bsearch(long long left,long long right,long long key,string unk)
{
	
	while(left <= right)
	{
		long long mid = (right + left)/2;
		long long lunk = changetodec(unk,mid);
		if(lunk == key)
			return mid;
		else if(lunk > key)
		{
			right = mid - 1;
		}
		else if(lunk < key)
			left = mid + 1;
	}
	return -1;
}
long long matching(string origin,long long int radix,string unknown)
{
	long long minradix = 0;
	long long result = -1;
	long long lori = 0,lunk = 0;
	for(int i = 0;i < unknown.size();i ++)
	{
		int tmp;
		if(unknown[i] <= '9' && unknown[i] >= '0')
			tmp = unknown[i] - '0';
		else 
			tmp = unknown[i] - 'a' + 10;
		if(tmp > minradix)
			minradix = tmp;
	}
	minradix++;
	if(minradix < 2) minradix = 2;
	lori = changetodec(origin,radix);

	long long left = minradix;
	long long right= 100000000000000;//shit 倒数第三个大进制检测 目测绝逼超过10亿 最少要百亿
	long long k;
	for(k = minradix;k <= 10000;k ++)
	{
		lunk = changetodec(unknown,k);
		if(lori == lunk)
		{
			result = k;
			break;
		}
		else if(lunk > lori)
			break;
	}
	if(result < 0)
		result = bsearch(10001,right,lori,unknown);	//以后写查找程序多用二分法
	return result;
}
int main()
{
	int t;
	long long radix;
	string N1,N2;
	cin >> N1 >> N2;
	cin >> t >> radix;
	long long flag;
	if(t == 1)
		flag = matching(N1,radix,N2);
	else
		flag = matching(N2,radix,N1);
	if(flag <= 1)
		cout << "Impossible";
	else
		cout << flag;
	system("pause");
	return 0;
}
