/*
Given a sequence of positive integers and another positive integer p. The sequence is said to be a "perfect sequence" if M <= m * p where M and m are the maximum and minimum numbers in the sequence, respectively.

Now given a sequence and a parameter p, you are supposed to find from the sequence as many numbers as possible to form a perfect subsequence.

Input Specification:

Each input file contains one test case. For each case, the first line contains two positive integers N and p, where N (<= 105) is the number of integers in the sequence, and p (<= 109) is the parameter. In the second line there are N positive integers, each is no greater than 109.

Output Specification:

For each test case, print in one line the maximum number of integers that can be chosen to form a perfect subsequence.

Sample Input:
10 8
2 3 20 4 5 1 6 7 8 9
Sample Output:
8
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
#include <map>
#include <set>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
	//fstream cin("F://test.txt");
	int N,p;
	cin >> N >> p;
	vector<int> v(N);
	for(int i = 0;i < N;i++)
		cin >> v[i];
	sort(v.begin(),v.end());
	int ans = 0;
	for(int i = 0;i < v.size();i++)
	{
		long long mp = (long long)v[i]*(long long)p;
		int pos = upper_bound(v.begin(),v.end(),mp) - v.begin();//upper_bound果然是神器也 二分查找搞定的哦
		//在容器上使用算法先想想STL中的算法
        //之前的想法是错误的 并不能用从容器两头齐头并进查找的方法 有bug
		while(pos >= v.size() || v[pos] > mp) pos--;
		int len = pos - i + 1;
		if(len > ans) ans = len;
	}
	cout << ans;
	system("pause");
	return 0;
}