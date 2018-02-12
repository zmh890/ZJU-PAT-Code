/*
Given an increasing sequence S of N integers, the median is the number at the middle position. For example, the median of S1={11, 12, 13, 14} is 12, and the median of S2={9, 10, 15, 16, 17} is 15. The median of two sequences is defined to be the median of the nondecreasing sequence which contains all the elements of both sequences. For example, the median of S1 and S2 is 13.

Given two increasing sequences of integers, you are asked to find their median.

Input

Each input file contains one test case. Each case occupies 2 lines, each gives the information of a sequence. For each sequence, the first positive integer N (<=1000000) is the size of that sequence. Then N integers follow, separated by a space. It is guaranteed that all the integers are in the range of long int.

Output

For each test case you should output the median of the two given sequences in a line.

Sample Input
4 11 12 13 14
5 9 10 15 16 17
Sample Output
13
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

int main()
{
	//fstream cin("F://median.txt");
	long int N1,N2;
	//！！！！！！注意 cin和scanf不能混用 会段错误的
	scanf("%ld",&N1);
	vector<long> v1(N1);
	for(long i = 0;i < N1;i++)
		{long tmp;scanf("%ld",&tmp);v1[i] = tmp;}//scanf比cin要快 所以遇到大数据输入输出的时候 用scanf和printf取代cin和cout
	scanf("%ld",&N2);
	vector<long> v2(N2);
	for(long i = 0;i < N2;i++)
		{long tmp;scanf("%ld",&tmp);v2[i] = tmp;}
	long median = ((long long)N1 + (long long)N2 - 1)/2;
	//cout << v1.size() << " " << v2.size() << " " << median << endl;
	long count = 0;long midnum = v1[0] < v2[0]?v1[0]:v2[0];
	vector<long>::iterator it1 = v1.begin(),it2 = v2.begin();
	while(count <= median)
	{
		if(it1 != v1.end() && it2 != v2.end())
		{
			if(*it1 > *it2)	midnum = *it2++;
			else midnum = *it1++;
		}
		else if(it1 == v1.end())
		{
			midnum = *it2++;
		}
		else if(it2 == v2.end())
		{
			midnum = *it1++;
		}
		count ++;
	}
	printf("%ld",midnum);
	system("pause");
	return 0;
}