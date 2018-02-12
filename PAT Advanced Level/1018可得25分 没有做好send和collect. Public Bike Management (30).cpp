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
	/*for(int i = 0;i <= N;i++)
	{
		cout << needs[i] << " ";
	}
	cout << endl;*/
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
				needs[j] = needs[u] + Maxc/2 - bikenum[j];
				//cout << j << "---==" << needs[j] << endl;
				if(!isin[j]){isin[j] = 1;q.push(j);}
			}
			else if(dist[j] == dist[u] + edges[u][j] && edges[u][j] != INF && j != u)
			{
				//path[j].push_back(u);
				if(abs(needs[j]) > abs(needs[u] + Maxc/2 - bikenum[j]))
				{
					needs[j] = needs[u] + Maxc/2 - bikenum[j];
					path[j][0] = u;
				}
				//cout << j << "=====" << needs[j] << endl;
			}
		}
		//cout <<u <<">>>>>"<< "asdf\n";
	}
}
int main()
{
	fstream cin("F://asd.txt");
	cin >> Maxc >> N >> Sp >> M;
	bikenum[0] = 30000;
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
	stack<int> s;
	int sp = Sp;
	while(sp != 0)
	{
		s.push(sp);
		sp = path[sp][0];
	}
	if(needs[Sp] >= 0)
	{
		cout << needs[Sp] << " " << 0;
		while(!s.empty())
		{
			int tmp = s.top();s.pop();
			cout << "->" << tmp;
		}
		cout << " " << 0;
	}
	else
	{
		cout << 0 << " " << 0;
		while(!s.empty())
		{
			int tmp = s.top();s.pop();
			cout << "->" << tmp;
		}
		cout << " " << -needs[Sp];
	}
	system("pause");
	return 0;
}