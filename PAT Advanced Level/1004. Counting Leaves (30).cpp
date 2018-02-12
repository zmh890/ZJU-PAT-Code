/*
A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.
Input

Each input file contains one test case. Each case starts with a line containing 0 < N < 100, the number of nodes in a tree, and M (< N), the number of non-leaf nodes. Then M lines follow, each in the format:

ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 01.
Output

For each test case, you are supposed to count those family members who have no child for every seniority level starting from the root. The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.

The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child. Hence on the root 01 level, there is 0 leaf node; and on the next level, there is 1 leaf node. Then we should output "0 1" in a line.

Sample Input
2 1
01 1 02
Sample Output
0 1
*/
//用时：：1H5M
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>
#include <vector>
#include <hash_map>
#include <fstream>
using namespace std;
#define MAXN 100

vector<int> tree[MAXN];
queue<int> result;

void BFS()
{
	queue<int> q;
	int visited[MAXN];
	memset(visited,0,sizeof(visited));
	q.push(1);
	visited[1] = 1;
	while(!q.empty())
	{
		int count = q.size();
		int no_sons = 0;
		for(int i = 1;i <= count;i++)
		{
			int u = q.front();q.pop();
			if(tree[u].empty())
			{
				visited[u] = 1;
				no_sons ++;
			}
			else
			{
				visited[u] = 1;
				for(int t = 0;t < tree[u].size();t++)
				{
					if(!visited[tree[u][t]])
						q.push(tree[u][t]);
				}
			}
		}
		result.push(no_sons);
		
	}
}
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i = 0;i < m;i++)
	{
		int id,k;
		cin >> id >> k;
		for(int j = 0;j < k;j++)
		{
			int idk;
			cin >> idk;
			tree[id].push_back(idk);
		}
	}
	/*for(int i = 1;i <= m;i++)
	{
		cout << "tree" << i << "::";
		for(int j = 0;j < tree[i].size();j++)
			cout << tree[i][j] << " ";
		cout << endl;
	}*/
	BFS();
	cout << result.front();result.pop();
	while(!result.empty())
	{
		cout << " " << result.front();
		result.pop();
	}

	system("pause");
	return 0;
}

