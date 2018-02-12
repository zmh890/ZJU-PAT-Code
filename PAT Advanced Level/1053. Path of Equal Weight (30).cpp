/*
Given a non-empty tree with root R, and with weight Wi assigned to each tree node Ti. The weight of a path from R to L is defined to be the sum of the weights of all the nodes along the path from R to any leaf node L.

Now given any weighted tree, you are supposed to find all the paths with their weights equal to a given number. For example, let's consider the tree showed in Figure 1: for each node, the upper number is the node ID which is a two-digit number, and the lower number is the weight of that node. Suppose that the given number is 24, then there exists 4 different paths which have the same given weight: {10 5 2 7}, {10 4 10}, {10 3 3 6 2} and {10 3 3 6 2}, which correspond to the red edges in Figure 1.


Figure 1
Input Specification:

Each input file contains one test case. Each case starts with a line containing 0 < N <= 100, the number of nodes in a tree, M (< N), the number of non-leaf nodes, and 0 < S < 230, the given weight number. The next line contains N positive numbers where Wi (<1000) corresponds to the tree node Ti. Then M lines follow, each in the format:

ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 00.

Output Specification:

For each test case, print all the paths with weight S in non-increasing order. Each path occupies a line with printed weights from the root to the leaf in order. All the numbers must be separated by a space with no extra space at the end of the line.

Note: sequence {A1, A2, ..., An} is said to be greater than sequence {B1, B2, ..., Bm} if there exists 1 <= k < min{n, m} such that Ai = Bi for i=1, ... k, and Ak+1 > Bk+1.

Sample Input:
20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 02 03 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19
Sample Output:
10 5 2 7
10 4 10
10 3 3 6 2
10 3 3 6 2
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
int N,M,S;
int weight[200];
int calweight[200];
vector<vector<int>> res;
vector<vector<int>> relations;
set<int> nonleaf;
bool cmp(const vector<int>& v1,const vector<int> v2)
{
	int i = v1.size()-1,j = v2.size()-1;
	while(i >= 0 && j >= 0)
	{
		if(v1[i] != v2[j]) return v1[i] > v2[j];
		else 
			{--i;--j;}
	}
	return v1.size() > v2.size();//这个地方 大于小于对评判结果貌似无影响
}
void BFS()
{
	queue<int> q;
	q.push(0);
	while(!q.empty())
	{
		int size = q.size();
		while(size--)
		{
			int u = q.front();q.pop();
			for(int i = 0;i < relations[u].size();i++)
				q.push(relations[u][i]),calweight[relations[u][i]] += calweight[u]; 
		}
	}
}
int main()
{
	//fstream cin("F://test.txt");
	//freopen("F://test.txt","r",stdin);
	memset(weight,0,sizeof(weight));
	scanf("%d %d %d",&N,&M,&S);
	for(int i = 0;i < N;i++)
	{
		int tmp;scanf("%d",&tmp);
		weight[i] = calweight[i] = tmp;
	}
	relations.resize(N+1);
	vector<int> v(N,0);//元素内容是当前位置的父节点
	for(int j = 0;j < M;j++)
	{
		int K;int father;
		scanf("%d %d",&father,&K);
		nonleaf.insert(father);
		while(K--)
		{
			int son;
			scanf("%d",&son);
			v[son] = father;
			//calweight[son] += calweight[father];
			relations[father].push_back(son);
		}
	}
	BFS();//注意 输入的结点关系可能是无序的 测试点2 所以 必须要用一个BFS计算叠加的weight
	for(int k = 0;k < N;k++)
		if(nonleaf.find(k) == nonleaf.end() && calweight[k] == S)
		{
			vector<int> tmp;
			for(int t = k;t != 0;t = v[t])
				tmp.push_back(weight[t]);
			tmp.push_back(weight[0]);
			res.push_back(tmp);
		}
	sort(res.begin(),res.end(),cmp);
	for(int i = 0;i < res.size();i++)
	{
		int flag = 1;
		for(int j = res[i].size()-1;j >= 0;j--)
			if(flag) printf("%d",res[i][j]),flag = 0;
			else printf(" %d",res[i][j]);
		printf("\n");
	}
	;
	system("pause");
	return 0;
}