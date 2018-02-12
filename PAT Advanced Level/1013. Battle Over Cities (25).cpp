/*
It is vitally important to have all the cities connected by highways in a war. If a city is occupied by the enemy, all the highways from/toward that city are closed. We must know immediately if we need to repair any other highways to keep the rest of the cities connected. Given the map of cities which have all the remaining highways marked, you are supposed to tell the number of highways need to be repaired, quickly.

For example, if we have 3 cities and 2 highways connecting city1-city2 and city1-city3. Then if city1 is occupied by the enemy, we must have 1 highway repaired, that is the highway city2-city3.

Input

Each input file contains one test case. Each case starts with a line containing 3 numbers N (<1000), M and K, which are the total number of cities, the number of remaining highways, and the number of cities to be checked, respectively. Then M lines follow, each describes a highway by 2 integers, which are the numbers of the cities the highway connects. The cities are numbered from 1 to N. Finally there is a line containing K numbers, which represent the cities we concern.

Output

For each of the K cities, output in a line the number of highways need to be repaired if that city is lost.

Sample Input
3 2 3
1 2
1 3
1 2 3
Sample Output
1
0
0
*/
#include <iostream>
#include <vector>
using namespace std;
typedef struct line_tag
{
	int from;
	int to;
	line_tag(int f,int t)
	{
		from = f;
		to = t;
	}
	int isin(int is)
	{
		if(from == is || to == is)
			return 1;
		else
			return 0;
	}
}line;
int parent[1010] = {0};
void UFset()
{
	for(int i = 1;i < 1010;i++)
		parent[i] = -1;
}
int Find(int x)
{
	int s = x;
	for(;parent[s] >= 0;s = parent[s]);
	while(s != x)
	{
		int tmp = parent[x];
		parent[x] = s;
		x = tmp;
	}

	return s;
}
void Union(int R1,int R2)
{
	int r1 = Find(R1);
	int r2 = Find(R2);
	if(r1 == r2)//判定确实不属于一个集合 才可以Union
		return;
	int r = parent[r1] + parent[r2];
	if(parent[r1] > parent[r2])
	{
		parent[r1] = r2;
		parent[r2] = r;
	}
	else
	{
		parent[r2] = r1;
		parent[r1] = r;
	}
}
int main()
{
	vector<line> origin;
	int N,K;
	int M;
	cin >> N >> M >> K;
	for( int i = 0;i < M;i++)
	{
		int f,t;
		cin >> f >> t;
		line ltmp(f,t);
		origin.push_back(ltmp);
	}
	for(int t = 0;t < K;t++)
	{
		int key;
		cin >> key;
		UFset();
		for( int j = 0;j < origin.size();j ++)
		{
			if(!origin[j].isin(key))
			{
				//if(Find(origin[j].from) != Find(origin[j].to))//并查集操作 只有不属于一个集合的才可以Union
					Union(origin[j].from,origin[j].to);
			}
		}
		int count = 0;
		for(int m = 1;m <= N;m++)
		{
			if(parent[m] < 0 && m != key)
				count ++;
		}
		count --;
		cout << count << endl;
	}
	system("pause");
	return 0;
}

