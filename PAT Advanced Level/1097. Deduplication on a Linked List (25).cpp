/*
Given a singly linked list L with integer keys, you are supposed to remove the nodes with duplicated absolute values of the keys. That is, for each value K, only the first node of which the value or absolute value of its key equals K will be kept. At the mean time, all the removed nodes must be kept in a separate list. For example, given L being 21→-15→-15→-7→15, you must output 21→-15→-7, and the removed list -15→15.

Input Specification:

Each input file contains one test case. For each case, the first line contains the address of the first node, and a positive N (<= 105) which is the total number of nodes. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Key Next

where Address is the position of the node, Key is an integer of which absolute value is no more than 104, and Next is the position of the next node.

Output Specification:

For each case, output the resulting linked list first, then the removed list. Each node occupies a line, and is printed in the same format as in the input.

Sample Input:
00100 5
99999 -7 87654
23854 -15 00000
87654 15 -1
00000 -15 99999
00100 21 23854
Sample Output:
00100 21 23854
23854 -15 99999
99999 -7 -1
00000 -15 87654
87654 15 -1
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <algorithm>
#include <fstream>
using namespace std;
typedef struct Node 
{
	int addr,K,next;
	Node(int a,int k,int n):addr(a),K(k),next(n){}
	Node(){}
}node;
node all[100000];
int main()
{
	//fstream cin("F://test.txt");
	//freopen("F://test.txt","r",stdin);
	int start,N;
	scanf("%d %d",&start,&N);
	for(int i = 0;i < N;i++)
	{
		int addr,K,next;
		scanf("%d %d %d",&addr,&K,&next);
		all[addr].addr = addr;
		all[addr].K = K;
		all[addr].next = next;
	}
	vector<node> nodup;
	vector<node> dup;
	set<int> s;
	nodup.reserve(100000);dup.reserve(100000);
	nodup.push_back(all[start]);
	s.insert(all[start].K);
	start = all[start].next;
	while(start != -1)
	{
		int dupflag = 0;
		if(s.find(all[start].K) != s.end() || s.find(-all[start].K) != s.end())
			dup.push_back(all[start]);
		else
			nodup.push_back(all[start]),s.insert(all[start].K);
		start = all[start].next;
	}
	//cout << nodup.size() << endl << dup.size() << endl;
	
	if(!nodup.empty())
	{
		printf("%05d %d ",nodup[0].addr,nodup[0].K);
		for(int i = 1;i < nodup.size();i++)
			printf("%05d\n%05d %d ",nodup[i].addr,nodup[i].addr,nodup[i].K);
		printf("-1\n");
	}
	if(!dup.empty())
	{
		printf("%05d %d ",dup[0].addr,dup[0].K);
		for(int i = 1;i < dup.size();i++)
			printf("%05d\n%05d %d ",dup[i].addr,dup[i].addr,dup[i].K);
		printf("-1");
	}
	;
	return 0;
}