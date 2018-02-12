/*
To store English words, one method is to use linked lists and store a word letter by letter. To save some space, we may let the words share the same sublist if they share the same suffix. For example, "loading" and "being" are stored as showed in Figure 1.


Figure 1
You are supposed to find the starting position of the common suffix (e.g. the position of "i" in Figure 1).

Input Specification:

Each input file contains one test case. For each case, the first line contains two addresses of nodes and a positive N (<= 105), where the two addresses are the addresses of the first nodes of the two words, and N is the total number of nodes. The address of a node is a 5-digit positive integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Data Next

where Address is the position of the node, Data is the letter contained by this node which is an English letter chosen from {a-z, A-Z}, and Next is the position of the next node.

Output Specification:

For each case, simply output the 5-digit starting position of the common suffix. If the two words have no common suffix, output "-1" instead.

Sample Input 1:
11111 22222 9
67890 i 00002
00010 a 12345
00003 g -1
12345 D 67890
00002 n 00003
22222 B 23456
11111 L 00001
23456 e 67890
00001 o 00010
Sample Output 1:
67890
Sample Input 2:
00001 00002 4
00001 a 10001
10001 s -1
00002 a 10002
10002 t -1
Sample Output 2:
-1
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cctype>
#include <queue>
#include <stack>
#include <cstring>
#include <list>
#include <map>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;
#define MAXN 100001
int nodes[MAXN];	//本题的数据结构应该采用插入和查找时间O(1)的 简单来说是数组，复杂点可以用哈希表，但是map在时间上不行
int counts[MAXN];
int main()
{
	//fstream cin("F://median.txt");
	int start1,start2,N;
	cin >> start1 >> start2 >> N;
	//特殊情况处理也很是问题 如 一个结点的时候 两个链表的起始结点相同，即从第一个结点就相同的情况
	if(start1 == -1 || start2 == -1)	 {printf("-1");return 0;}
	if(start1 == start2)	{printf("%05d",start1);return 0;}
	if(N <= 1) {printf("-1");return 0;}
	for(int i = 0;i < MAXN;i++)
		nodes[i] = -1,counts[i] = 0;
	while(N--)
	{
		int addr,next;char c;
		cin >> addr >> c >> next;
		nodes[addr] = next;
	}
	int t;
	for(int p = start1;nodes[p] != -1;p = nodes[p])
		counts[p] = 1;
	for(t = start2;t != -1 && !counts[t];t = nodes[t])
		counts[t] = 1;
	if(t != -1)
		printf("%05d",t);
	else
		printf("-1");
	system("pause");
	return 0;
}