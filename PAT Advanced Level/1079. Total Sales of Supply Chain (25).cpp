/*
A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）-- everyone involved in moving a product from supplier to customer.

Starting from one root supplier, everyone on the chain buys products from one's supplier in a price P and sell or distribute them in a price that is r% higher than P. Only the retailers will face the customers. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.

Now given a supply chain, you are supposed to tell the total sales from all the retailers.

Input Specification:

Each input file contains one test case. For each case, the first line contains three positive numbers: N (<=105), the total number of the members in the supply chain (and hence their ID's are numbered from 0 to N-1, and the root supplier's ID is 0); P, the unit price given by the root supplier; and r, the percentage rate of price increment for each distributor or retailer. Then N lines follow, each describes a distributor or retailer in the following format:

Ki ID[1] ID[2] ... ID[Ki]

where in the i-th line, Ki is the total number of distributors or retailers who receive products from supplier i, and is then followed by the ID's of these distributors or retailers. Kj being 0 means that the j-th member is a retailer, then instead the total amount of the product will be given after Kj. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the total sales we can expect from all the retailers, accurate up to 1 decimal place. It is guaranteed that the number will not exceed 1010.

Sample Input:
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0 7
2 6 1
1 8
0 9
0 4
0 3
Sample Output:
42.4
*/
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
	//fstream cin("F://test.txt");
	int N;double P,r;
	cin >> N;cin >> P >> r;
	r = r/100 + 1.0;
	vector<vector<int>> v(N);//建立邻接表
	set<int> retailers;//保存零售商的标号
	map<int,int> amounts;//根据零售商标号可查找其货物数量
	for(int i = 0;i < N;i++)
	{
		int K;cin >> K;
		if(K == 0)
		{
			int a;cin >> a;
			retailers.insert(i);
			amounts[i] = a;
		}
		else
			while(K--)
			{
				int t;cin >> t;
				v[i].push_back(t);
			}
	}
	queue<int> q;
	double ans = 0.0;
	q.push(0);
	while(!q.empty())//层序遍历
	{
		int num = q.size();
		while(num--)
		{
			int u = q.front();q.pop();
			if(retailers.find(u) != retailers.end())
				ans += P*amounts[u];
			else 
				for(int j = 0;j < v[u].size();j++)
					q.push(v[u][j]);
		}
		P *= r;
	}
	printf("%.1lf",ans);
	system("pause");
	return 0;
}