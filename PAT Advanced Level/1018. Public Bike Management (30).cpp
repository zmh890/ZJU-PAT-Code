/*
There is a public bike service in Hangzhou City which provides great convenience to the tourists from all over the world. One may rent a bike at any station and return it to any other stations in the city.

The Public Bike Management Center (PBMC) keeps monitoring the real-time capacity of all the stations. A station is said to be in perfect condition if it is exactly half-full. If a station is full or empty, PBMC will collect or send bikes to adjust the condition of that station to perfect. And more, all the stations on the way will be adjusted as well.

When a problem station is reported, PBMC will always choose the shortest path to reach that station. If there are more than one shortest path, the one that requires the least number of bikes sent from PBMC will be chosen.


Figure 1



Figure 1 illustrates an example. The stations are represented by vertices and the roads correspond to the edges. The number on an edge is the time taken to reach one end station from another. The number written inside a vertex S is the current number of bikes stored at S. Given that the maximum capacity of each station is 10. To solve the problem at S3, we have 2 different shortest paths:

1. PBMC -> S1 -> S3. In this case, 4 bikes must be sent from PBMC, because we can collect 1 bike from S1 and then take 5 bikes to S3, so that both stations will be in perfect conditions.

2. PBMC -> S2 -> S3. This path requires the same time as path 1, but only 3 bikes sent from PBMC and hence is the one that will be chosen.

Input Specification:

Each input file contains one test case. For each case, the first line contains 4 numbers: Cmax (<= 100), always an even number, is the maximum capacity of each station; N (<= 500), the total number of stations; Sp, the index of the problem station (the stations are numbered from 1 to N, and PBMC is represented by the vertex 0); and M, the number of roads. The second line contains N non-negative numbers Ci (i=1,...N) where each Ci is the current number of bikes at Si respectively. Then M lines follow, each contains 3 numbers: Si, Sj, and Tij which describe the time Tij taken to move betwen stations Si and Sj. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print your results in one line. First output the number of bikes that PBMC must send. Then after one space, output the path in the format: 0->S1->...->Sp. Finally after another space, output the number of bikes that we must take back to PBMC after the condition of Sp is adjusted to perfect.

Note that if such a path is not unique, output the one that requires minimum number of bikes that we must take back to PBMC. The judge's data guarantee that such a path is unique.

Sample Input:
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1
Sample Output:
3 0->2->3 0
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <queue>
#include <stack>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;
#define MAXN 510
#define INF 30000
int Maxc,N,Sp,M;
int edges[MAXN][MAXN];
int bikenum[MAXN];

vector<vector<int>> path(MAXN);
int dist[MAXN];
int needs[MAXN];
void SPFA(int v0)
{
	queue<int> q;
	int isin[MAXN];
	for(int i = 0;i <= N;i++)
	{
		dist[i] = INF;path[i].push_back(v0);isin[i] = 0;
		needs[i] = INF;
	}
	needs[0] = 0;needs[Sp] = Maxc/2 - bikenum[Sp];
	q.push(v0);isin[v0] = 1;dist[v0] = 0;
	while(!q.empty())
	{
		int u = q.front();q.pop();isin[u] = 0;
		for(int j = 0;j <= N;j++)
		{
			if(dist[j] > dist[u] + edges[u][j] && j != u)
			{
				dist[j] = dist[u] + edges[u][j];
				path[j][0] = u;
				if(!isin[j]){isin[j] = 1;q.push(j);}
			}
			else if(dist[j] == dist[u] + edges[u][j] && edges[u][j] != INF && j != u)
			{
				path[j].push_back(u);
			}
		}
	}
}
vector<vector<int>> bestpaths;
vector<int> possiblePath;
vector<int> bestonepath;
int minSend = INF;
int minCollect = INF;
void FindBest(int u)//秘诀就在此处 要找到合乎要求的最短的路径
{
	possiblePath.push_back(u);  
    if(u == 0)  
    {//find the end  
        int send = 0;  
        int collect = 0;  
        for(int i = possiblePath.size()-1; i >= 0; --i)  //send和collect可以同时不为零  比如说 最短路径上的车数为7 1 8 
        {												//此时 collect应为3 send应为2 即要调来2辆 返回去3辆 我只想说 真是shit啊
            int t = possiblePath[i];  
			if(bikenum[t] > Maxc/2)  
                collect += bikenum[t] - Maxc/2;  
            else if(bikenum[t] < Maxc/2)  
            {  
                collect -= (Maxc/2-bikenum[t]);  
                if(collect < 0) send -=collect, collect=0;  
            }  
        }  
		//比较大小的时候，先比较send 较小的佳 如果相等 就比较collect 较小的佳 简直就是shit！！！ 题意完全不明确！！
        if(send < minSend) minSend=send, minCollect=collect, bestonepath=possiblePath;  
        else if(send == minSend && collect < minCollect) minCollect=collect, bestonepath=possiblePath;  
        return;  
    }  
    for(int i = 0; i < path[u].size(); ++i)  
    {  
        FindBest(path[u][i]);  
        possiblePath.pop_back();  
    }  
}
int main()
{
	//fstream cin("F://asd.txt");
	cin >> Maxc >> N >> Sp >> M;
	bikenum[0] = Maxc/2;
	memset(edges,INF,sizeof(edges));
	for(int i = 1;i <= N;i++)
	{
		int tmp;
		cin >> tmp;
		bikenum[i] = tmp;
		edges[i][i] = 0;
	}
	for(int i = 1;i <= M;i++)
	{
		int s,e,w;
		cin >> s >> e >> w;
		edges[s][e] = w;
		edges[e][s] = w;
	}
	SPFA(0);
	FindBest(Sp);
	/*for(int j = 0;j < bestonepath.size();j++)
	{
		cout << bestonepath[j] << " ";
	}
	cout << endl;*/
	/*for(int j = 0;j < bestpaths.size();j++)
	{
		for(int i = 0;i < bestpaths[j].size();i++)
			cout << bestpaths[j][i] << " ";
		cout << endl;
	}*/
	cout << minSend << " " << 0;
	for(int i = bestonepath.size()-2;i >= 0;i--)
		cout << "->" << bestonepath[i];
	cout << " " << minCollect;

	system("pause");
	return 0;
}