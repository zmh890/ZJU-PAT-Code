/*
Given a sequence of K integers { N1, N2, ..., NK }. A continuous subsequence is defined to be { Ni, Ni+1, ..., Nj } where 1 <= i <= j <= K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

Input Specification:

Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (<= 10000). The second line contains K numbers, separated by a space.

Output Specification:

For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.

Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4
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

int K;
vector<int> v;
int main()
{
	//fstream cin("F://max.txt");
	int max = -1,spos = 0,epos = 0;
	int tmpmax = 0,tmpspos = 0,tmpepos = 0;
	cin >> K;
	for(int i = 0;i < K;i++)
	{
		int t;
		cin >> t;
		v.push_back(t);
		tmpmax += t;
		if(tmpmax < 0)
		{
			tmpmax = 0;
			tmpspos = i + 1;
			tmpepos = i + 1;
		}
		else 
		{
			tmpepos = i;
			if(tmpmax > max)
			{
				max = tmpmax;
				spos = tmpspos;
				epos = tmpepos;
			}
		}
	}
	if(K == 0)
		cout << "0 0 0";
	else
	{
		if(max < 0)
			cout << 0 << " " << v[0] << " " << v[v.size() - 1];
		else 
			cout << max << " " << v[spos] << " " << v[epos];
	}
	system("pause");
	return 0;
}
