/*
Given any permutation of the numbers {0, 1, 2,..., N-1}, it is easy to sort them in increasing order. But what if Swap(0, *) is the ONLY operation that is allowed to use? For example, to sort {4, 0, 2, 1, 3} we may apply the swap operations in the following way:

Swap(0, 1) => {4, 1, 2, 0, 3}
Swap(0, 3) => {4, 1, 2, 3, 0}
Swap(0, 4) => {0, 1, 2, 3, 4}

Now you are asked to find the minimum number of swaps need to sort the given permutation of the first N nonnegative integers.

Input Specification:

Each input file contains one test case, which gives a positive N (<=105) followed by a permutation sequence of {0, 1, ..., N-1}. All the numbers in a line are separated by a space.

Output Specification:

For each case, simply print in a line the minimum number of swaps need to sort the given permutation.

Sample Input:
10 3 5 7 2 6 4 9 0 8 1
Sample Output:
9
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <cstring>
#include <cctype>
#include <list>
#include <map>
#include <set>
#include <fstream>
#include <iomanip>
using namespace std;
vector<int> parent(100005,-1);
int Find(int x)
{
	int p;
	for(p = x;parent[p] >= 0;p = parent[p]);
	while(x != p)
	{
		int tmp = x;
		parent[x] = p;
		x = parent[tmp];
	}
	return p;
}
void Union(int x,int y)
{
	int px = Find(x);
	int py = Find(y);
	if(px == py)
		return;
	if(parent[px] > parent[py])
	{
		parent[py] += parent[px];
		parent[px] = py;
	}
	else
	{
		parent[px] += parent[py];
		parent[py] = px;
	}
}
//并查集处理 以例子为例 原理在于:可以按照当前数字和位置分成两组数 0->7->2->3   5->1->9->6->4
//第一组排序完成需要三次，此时0归位 再排序第二组时 需要将0与5交换 并且第二组要多交换一次 
//总次数为 3+1+5
//采用并查集分组后 计算共有多少组 已经在自己位置上的不算 但是0除外 注意：如果开始时0在0号位置 组数要加1 
//总次数为：所有组的元素个数之和-组数+(组数-1)*2
//该方法较为复杂 但是时间复杂度低 
int main()
{
	//fstream cin("F://test.txt");
	int N;
	cin >> N;
	for(int i = 0;i < N;i++)
	{
		int tmp;cin >> tmp;
		if(tmp != i)
			Union(tmp,i);
	}
	int steps = 0,clusters = 0;
	int zerocluster = Find(0);
	for(int i = 0;i < N;i++)
	{
		//cout << parent[i] << " ";
		if(parent[i] < -1)
			steps += (-parent[i])-1,clusters++;
	}
	//cout << endl;
	if(parent[0] == -1) clusters++;
	cout << steps + (clusters - 1)*2;
	system("pause");
	return 0;
}