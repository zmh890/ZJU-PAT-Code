/*
A linked list consists of a series of structures, which are not necessarily adjacent in memory. We assume that each structure contains an integer key and a Next pointer to the next structure. Now given a linked list, you are supposed to sort the structures according to their key values in increasing order.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive N (< 105) and an address of the head node, where N is the total number of nodes in memory and the address of a node is a 5-digit positive integer. NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Key Next

where Address is the address of the node in memory, Key is an integer in [-105, 105], and Next is the address of the next node. It is guaranteed that all the keys are distinct and there is no cycle in the linked list starting from the head node.

Output Specification:

For each test case, the output format is the same as that of the input, where N is the total number of nodes in the list and all the nodes must be sorted order.

Sample Input:
5 00001
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345
Sample Output:
5 12345
12345 -1 00001
00001 0 11111
11111 100 22222
22222 1000 33333
33333 100000 -1
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
#include <map>
#include <set>
#include <fstream>
using namespace std;
typedef struct Node
{
	int addr;
	int ele;
	int next;
}node;
node allnode[100003];//准备一个充分大的数组 防止所有的结点
bool cmp(const node& n1,const node& n2)
{
	return n1.ele < n2.ele;
}
int main()
{
	//fstream cin("F://test.txt");
	int N,start;
	cin >> N >> start;
	for(int i = 0;i < N;i++)
	{
		int a;cin >> a;
		allnode[a].addr = a;
		cin >> allnode[a].ele;
		cin >> allnode[a].next;
	}
	vector<node> v;
	while(start != -1)//根据结点的头指针地址 找出所有的在这个链表上的结点
	{
		v.push_back(allnode[start]);
		start = allnode[start].next;
	}
	sort(v.begin(),v.end(),cmp);
	cout << v.size() << " ";
	for(int i = 0;i < v.size();i++)
		printf("%05d\n%05d %d ",v[i].addr,v[i].addr,v[i].ele);
	printf("-1");
	system("pause");
	return 0;
}