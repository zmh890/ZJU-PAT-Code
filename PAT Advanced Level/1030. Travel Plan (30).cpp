/*
A traveler's map gives the distances between cities along the highways, together with the cost of each highway. Now you are supposed to write a program to help a traveler to decide the shortest path between his/her starting city and the destination. If such a shortest path is not unique, you are supposed to output the one with the minimum cost, which is guaranteed to be unique.

Input Specification:

Each input file contains one test case. Each case starts with a line containing 4 positive integers N, M, S, and D, where N (<=500) is the number of cities (and hence the cities are numbered from 0 to N-1); M is the number of highways; S and D are the starting and the destination cities, respectively. Then M lines follow, each provides the information of a highway, in the format:

City1 City2 Distance Cost

where the numbers are all integers no more than 500, and are separated by a space.

Output Specification:

For each test case, print in one line the cities along the shortest path from the starting point to the destination, followed by the total distance and the total cost of the path. The numbers must be separated by a space and there must be no extra space at the end of output.

Sample Input
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
Sample Output
0 2 3 3 40

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
#define MAXN (int)(505)
const int INF = 10000;
int Edges[MAXN][MAXN];
int Costs[MAXN][MAXN];
int N,M,S,D;

int path[MAXN];
int dist[MAXN];int inq[MAXN];
int costall[MAXN];
void SPFA(int v0)
{
	queue<int> q;
	for(int i = 0;i < N;i++)
	{
		dist[i] = INF;path[i] = v0;inq[i] = 0;
		Edges[i][i] = 0;
		costall[i] = INF;
	}
	dist[v0] = 0;costall[v0] = 0;
	q.push(v0);inq[v0]++;
	while(!q.empty())
	{
		int u = q.front();q.pop();inq[u]--;
		for(int j = 0;j < N;j++)
			if(dist[j] > dist[u] + Edges[u][j] && Edges[u][j] < INF)
			{
				dist[j] = dist[u] + Edges[u][j];
				path[j] = u;
				costall[j] = costall[u] + Costs[u][j];//costall的处理是重点
				if(!inq[j]) {q.push(j);inq[j]++;}
			}
			else if(u != j && dist[j] == dist[u] + Edges[u][j] && Edges[u][j] < INF)
				//还是要进一步理解多条最短路径下的选择条件的处理 此题与1003类似 可放在一起理解
			{
				if(costall[u] + Costs[u][j] < costall[j])
					costall[j] = costall[u] + Costs[u][j],path[j] = u;
			}
	}
}

int main()
{
	//fstream cin("F://median.txt");
	cin >> N >> M >> S >> D;
	for(int i = 0;i < N;i++)
		for(int j = 0;j < N;j++)
			Edges[i][j] = Costs[i][j] = INF;//memset INF的时候会出问题 如果memset的不是0 就一个一个填充
	for(int i = 0;i < M;i++)
	{
		int u,v,w,cost;
		cin >> u >> v >> w >> cost;
		Edges[u][v] = Edges[v][u] = w;
		Costs[u][v] = Costs[v][u] = cost;
	}
	SPFA(S);
	/*for(int i = 0;i < N;i++)
		cout << path[i] << " ";
	cout << endl;*/
	stack<int> sta;
	int d = D;
	while(path[d] != S)	sta.push(d),d = path[d];
	sta.push(d);

	cout << S;
	while(!sta.empty())
		{cout << " " << sta.top();sta.pop();}
	cout << " " << dist[D] << " " << costall[D];
	system("pause");
	return 0;
}