/*
Given two sets of integers, the similarity of the sets is defined to be Nc/Nt*100%, where Nc is the number of distinct common numbers shared by the two sets, and Nt is the total number of distinct numbers in the two sets. Your job is to calculate the similarity of any given pair of sets.

Input Specification:

Each input file contains one test case. Each case first gives a positive integer N (<=50) which is the total number of sets. Then N lines follow, each gives a set with a positive M (<=104) and followed by M integers in the range [0, 109]. After the input of sets, a positive integer K (<=2000) is given, followed by K lines of queries. Each query gives a pair of set numbers (the sets are numbered from 1 to N). All the numbers in a line are separated by a space.

Output Specification:

For each query, print in one line the similarity of the sets, in the percentage form accurate up to 1 decimal place.

Sample Input:
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3
Sample Output:
50.0%
33.3%
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
	int N;
	cin >> N;
	vector<set<int>> v(N+1);//直接用set就可以过滤掉输入时的重复元素
	for(int i = 1;i <= N;i++)
	{
		int M;cin >> M;
		while(M--)
		{
			int tmp;cin >> tmp;
			v[i].insert(tmp);
		}
	}
	int K;cin >> K;
	while(K--)
	{
		int n,m;cin >> n >> m;
		int cntdup = 0;
		for(set<int>:: iterator it = v[n].begin();it != v[n].end();it++) //遍历一个集合中的元素 看看在另一个集合中有没有
			if(v[m].find(*it) != v[m].end())
				++cntdup;
		printf("%.1f%%\n",cntdup*1.0/(v[n].size() + v[m].size() - cntdup)*100);
	}
	system("pause");
	return 0;
}