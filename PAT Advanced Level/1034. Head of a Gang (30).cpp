/*
One way that the police finds the head of a gang is to check people's phone calls. If there is a phone call between A and B, we say that A and B is related. The weight of a relation is defined to be the total time length of all the phone calls made between the two persons. A "Gang" is a cluster of more than 2 persons who are related to each other with total relation weight being greater than a given threshold K. In each gang, the one with maximum total weight is the head. Now given a list of phone calls, you are supposed to find the gangs and the heads.

Input Specification:

Each input file contains one test case. For each case, the first line contains two positive numbers N and K (both less than or equal to 1000), the number of phone calls and the weight threthold, respectively. Then N lines follow, each in the following format:

Name1 Name2 Time

where Name1 and Name2 are the names of people at the two ends of the call, and Time is the length of the call. A name is a string of three capital letters chosen from A-Z. A time length is a positive integer which is no more than 1000 minutes.

Output Specification:

For each test case, first print in a line the total number of gangs. Then for each gang, print in a line the name of the head and the total number of the members. It is guaranteed that the head is unique for each gang. The output must be sorted according to the alphabetical order of the names of the heads.

Sample Input 1:
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 1:
2
AAA 3
GGG 3
Sample Input 2:
8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 2:
0
*/
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <algorithm>
#include <fstream>
using namespace std;
#define MAXN 2010
map<string,int> name2id;
map<int,string> id2name;
map<string,int> res;
int Edges[MAXN][MAXN];
int times[MAXN];
int visited[MAXN];
int namecnt = 0;
int N,K;
void BFS()//通过设置visited数组的方式 可以查找这个图中有几个连通子图 并对每个连通子图做处理 想得太复杂了 
{
	memset(visited,0,sizeof(visited));
	for(int i = 0;i < namecnt;i++)
	{
		if(!visited[i])
		{
			set<int> gang;queue<int> q;
			q.push(i);gang.insert(i);
			visited[i] = 1;
			while(!q.empty())
			{
				int u = q.front();q.pop();
				for(int j = 0;j < namecnt;j++)
					if(!visited[j] && Edges[u][j])
						q.push(j),visited[j] = 1,gang.insert(j);
			}
			//计算这一组gang的互相通信时间
			int sumtime = 0;
			for(set<int>::iterator it = gang.begin();it != gang.end();it++)
				sumtime += times[*it];
			sumtime /= 2;
			//cout << "sumtime::" << sumtime << endl;
			if(gang.size() > 2 && sumtime > K)
			{
				int max = 0;int maxele;//找到头目
				for(set<int>::iterator it = gang.begin();it != gang.end();it++)
					if(times[*it] > max)
						max = times[*it],maxele = *it;
				res[id2name[maxele]] = gang.size();//注意是按照name的字母序排序 所以应该直接插入name
			}
			//cout << res.size() << endl;
		}
	}
}
int main()
{
	//fstream cin("F://test.txt");
	cin >> N >> K;
	memset(Edges,0,sizeof(Edges));
	while(N--)
	{
		string name1,name2;int time;
		cin >> name1 >> name2 >> time;
		//cout << name1.size() << " " << name2.size() << endl;
		int id1,id2;//将输入的字符串离散化成数字id
		if(name2id.find(name1) == name2id.end())
		{
			name2id[name1] = namecnt;id2name[namecnt] = name1;
			id1 = namecnt;
			namecnt++;
		}
		else
			id1 = name2id[name1];
		if(name2id.find(name2) == name2id.end())
		{
			name2id[name2] = namecnt;id2name[namecnt] = name2;
			id2 = namecnt;
			namecnt++;
		}
		else
			id2 = name2id[name2];
		times[id1] += time;times[id2] += time;
		Edges[id1][id2] = Edges[id2][id1] = 1;
	}
	BFS();
	cout << res.size() << endl;
	for(map<string,int>::iterator it = res.begin();it != res.end();it++)
		cout << it->first << " " << it->second << endl;
	system("pause");
	return 0;
}