/*
Weibo is known as the Chinese version of Twitter. One user on Weibo may have many followers, and may follow many other users as well. Hence a social network is formed with followers relations. When a user makes a post on Weibo, all his/her followers can view and forward his/her post, which can then be forwarded again by their followers. Now given a social network, you are supposed to calculate the maximum potential amount of forwards for any specific user, assuming that only L levels of indirect followers are counted.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers: N (<=1000), the number of users; and L (<=6), the number of levels of indirect followers that are counted. Hence it is assumed that all the users are numbered from 1 to N. Then N lines follow, each in the format:

M[i] user_list[i]

where M[i] (<=100) is the total number of people that user[i] follows; and user_list[i] is a list of the M[i] users that are followed by user[i]. It is guaranteed that no one can follow oneself. All the numbers are separated by a space.

Then finally a positive K is given, followed by K UserID's for query.

Output Specification:

For each UserID, you are supposed to print in one line the maximum potential amount of forwards this user can triger, assuming that everyone who can view the initial post will forward it once, and that only L levels of indirect followers are counted.

Sample Input:
7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6
Sample Output:
4
5
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
#define MAXN 1005
int Edges[MAXN][MAXN];
int visited[MAXN];
int N,L;
int calforwards(int v0)
{
	int rescnt = 0;
	memset(visited,0,sizeof(visited));
	queue<int> q;
	q.push(v0);visited[v0] = 1;
	for(int i = 0;i < L;i++)
	{
		int qnum = q.size();
		while(qnum--)
		{
			int u = q.front();q.pop();
			for(int j = 1;j <= N;j++)
				if(Edges[u][j] && !visited[j])
					rescnt++,q.push(j),visited[j] = 1;
		}
	}
	return rescnt;
}
int main()	//本题就是通过图的层序遍历 计算一定层数下不重复的节点数 
{
	//fstream cin("F://test.txt");
	cin >> N >> L;
	memset(Edges,0,sizeof(Edges));
	for(int i = 1;i <= N;i++)
	{
		int num;cin >> num;
		for(int j = 0;j < num;j++)
		{
			int follow;cin >> follow;
			Edges[follow][i] = 1;
		}
	}
	int K;cin >> K;
	while(K--)
	{
		int query;cin >> query;
		cout << calforwards(query) << "\n";
	}
	system("pause");
	return 0;
}