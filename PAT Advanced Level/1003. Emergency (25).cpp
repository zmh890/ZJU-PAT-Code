/*
As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

Input

Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (<= 500) - the number of cities (and the cities are numbered from 0 to N-1), M - the number of roads, C1 and C2 - the cities that you are currently in and that you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C1 to C2.

Output

For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2, and the maximum amount of rescue teams you can possibly gather.
All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.

Sample Input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output
2 4
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
using namespace std;
#define MAXN 500
#define INF 32700
int n,m;
int Edge[MAXN][MAXN];
int depart,desti;
int teams[MAXN];
int least = 0;

int countleast[MAXN];
int countcall[MAXN];
int S[MAXN],path[MAXN];
int dist[MAXN];
void Dijkstra(int v0)
{
	for(int i = 0;i < n;i++)
	{
		dist[i] = INF;S[i] = 0;
		countleast[i] = 0;
		countcall[i] = 0;
	}
	dist[v0] = 0;countleast[v0] = 1;
	countcall[v0] = teams[v0];
	while(1)
	{
		int min = INF,u = -1;
		for(int j = 0;j < n;j++)
		{
			if(!S[j] && dist[j] < min)
			{
				min = dist[j];u = j;
			}
		}
		if(u == -1 || u == desti)
			return;
		else
		{
			S[u] = 1;
			for(int j = 0;j < n;j++)
			{
				if(!S[j] && Edge[u][j] < INF && dist[u] + Edge[u][j] < dist[j])
				{
					dist[j] = dist[u] + Edge[u][j];
					countleast[j] = countleast[u];
					countcall[j] = countcall[u] + teams[j];
				}
				else if(!S[j] && Edge[u][j] < INF && dist[u] + Edge[u][j] == dist[j])
				{
					countleast[j] += countleast[u];
					if(countcall[j] < countcall[u] + teams[j])
						countcall[j] = countcall[u] + teams[j];
				}

			}
		}
	}
}
int main()
{
	cin >> n >> m >> depart >> desti;
	for(int i = 0;i < n;i++)
		cin >> teams[i];
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
		{
			if(i == j) Edge[i][j] = 0;
			else Edge[i][j] = INF;
		}
	for(int i = 0;i < m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		Edge[u][v] = w;
		Edge[v][u] = w;
	}
	Dijkstra(depart);

	
	cout << countleast[desti] << " " << countcall[desti];
	system("pause");
	return 0;
}