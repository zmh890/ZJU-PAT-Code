/*
Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. For example, given L being 1→2→3→4→5→6, if K = 3, then you must output 3→2→1→6→5→4; if K = 4, you must output 4→3→2→1→5→6.

Input Specification:

Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (<= 105) which is the total number of nodes, and a positive K (<=N) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Data Next

where Address is the position of the node, Data is an integer, and Next is the position of the next node.

Output Specification:

For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.

Sample Input:
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
Sample Output:
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1

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
node all[100000];//准备一个足够大的数组 方便存放原始数据 空间换时间
int main()
{
	//fstream cin("F://test.txt");
	vector<node> link;
	int start,N,K;
	cin >> start >> N >> K;
	link.reserve(N);
	while(N--)
	{
		int addr;cin >> addr;
		all[addr].addr = addr;
		cin >> all[addr].ele;
		cin >> all[addr].next;
	}
	while(start != -1)//根据首地址 找到这个链表中的所有结点 组成一个vector<node>
	{
		link.push_back(all[start]);
		start = all[start].next;
	}
	int nowpos = 0;
	int firstflag = 1;
	if(K < 1) K = 1;//注意K的大小会有影响的
	while(nowpos+K <= link.size())
	{
		for(int i = nowpos + K - 1;i >= nowpos;i--)
		{
			if(!firstflag)
				printf("%05d\n",link[i].addr);firstflag = 0;
			printf("%05d %d ",link[i].addr,link[i].ele);
		}
		nowpos += K;
	}
	for(int j = nowpos;j < link.size();j++)
	{
		printf("%05d\n",link[j].addr);
		printf("%05d %d ",link[j].addr,link[j].ele);
	}
	printf("-1");
	system("pause");
	return 0;
}