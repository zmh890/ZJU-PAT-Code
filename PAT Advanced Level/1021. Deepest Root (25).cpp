/*
A graph which is connected and acyclic can be considered a tree. The height of the tree depends on the selected root. Now you are supposed to find the root that results in a highest tree. Such a root is called the deepest root.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=10000) which is the number of nodes, and hence the nodes are numbered from 1 to N. Then N-1 lines follow, each describes an edge by given the two adjacent nodes' numbers.

Output Specification:

For each test case, print each of the deepest roots in a line. If such a root is not unique, print them in increasing order of their numbers. In case that the given graph is not a tree, print "Error: K components" where K is the number of connected components in the graph.

Sample Input 1:
5
1 2
1 3
1 4
2 5
Sample Output 1:
3
4
5
Sample Input 2:
5
1 3
1 4
2 5
3 4
Sample Output 2:
Error: 2 components
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
#include <fstream>
#include <iomanip>
using namespace std;
#define MAXN 10005
vector<vector<int> > Edges;
int visited[MAXN];
int N;
int calgraphs()
{
	memset(visited,0,sizeof(visited));
	int count = 0;
	int graphs = 0;
	queue<int> q;
	while(count < N)
	{
		for(int i = 1;i <= N;i++)
			if(!visited[i])
			{
				q.push(i);visited[i] = 1;
				while(!q.empty())
				{
					int u = q.front();q.pop();count++;
					for(int j = 0;j < Edges[u].size();j++)
						if(!visited[Edges[u][j]])
							q.push(Edges[u][j]),visited[Edges[u][j]] = 1;
					//cout << "LLLLLLLLLL" << endl;
				}
				graphs++;
			}
			//cout << "fffffff" << endl;
	}
	return graphs;
}
int BFS(int v0)
{
	memset(visited,0,sizeof(visited));
	queue<int> q;
	q.push(v0);visited[v0] = 1;
	int floors = 1;
	while(!q.empty())
	{
		int elecount = q.size();
		while(elecount--)
		{
			int u = q.front();q.pop();
			for(int j = 0;j < Edges[u].size();j++)
				if(!visited[ Edges[u][j] ])
					q.push(Edges[u][j]),visited[Edges[u][j]] = 1;
		}
		floors++;
	}
	return floors;
}
struct cmp
{
	bool operator()(const pair<int,int>& p1,const pair<int,int>& p2)
	{
		if(p1.second < p2.second)	return true;
		else if(p1.second == p2.second)
		{
			return p1.first > p2.first;
		}
		else  return false;
	}
};
priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> v;

int main()
{
	//fstream cin("F://root.txt");
	cin >> N;
	if(N == 1)//测试点1 测试1个点和2个点的情况 边界测试 这是PAT要注意的地方
	{cout << 1 << endl;return 0;}
	if(N == 2)
	{cout << 1 << endl;cout << 2 << endl;return 0;}
	for(int i = 0;i <= N;i++)
		{vector<int> t;Edges.push_back(t);}
	for(int i = 0;i < N-1;i++)
	{
		int u,v;
		cin >> u >> v;
		Edges[u].push_back(v);Edges[v].push_back(u);
	}
	int graphs = calgraphs();//cout << graphs << endl;
	if(graphs > 1)
	{
		cout << "Error: " << graphs << " components",system("pause");
		return 0;
	}
	for(int j = 1;j <= N;j++)
		v.push(make_pair(j,BFS(j)));
	int max = v.top().second;
	while(max == v.top().second)
		cout << v.top().first << endl,v.pop();
	system("pause");
	return 0;
}