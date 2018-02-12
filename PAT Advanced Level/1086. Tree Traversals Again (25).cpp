/*
An inorder binary tree traversal can be implemented in a non-recursive way with a stack. For example, suppose that when a 6-node binary tree (with the keys numbered from 1 to 6) is traversed, the stack operations are: push(1); push(2); push(3); pop(); pop(); push(4); pop(); pop(); push(5); push(6); pop(); pop(). Then a unique binary tree (shown in Figure 1) can be generated from this sequence of operations. Your task is to give the postorder traversal sequence of this tree.
            1
          2     5
        3   4  6
Figure 1
Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=30) which is the total number of nodes in a tree (and hence the nodes are numbered from 1 to N). Then 2N lines follow, each describes a stack operation in the format: "Push X" where X is the index of the node being pushed onto the stack; or "Pop" meaning to pop one node from the stack.

Output Specification:

For each test case, print the postorder traversal sequence of the corresponding tree in one line. A solution is guaranteed to exist. All the numbers must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop
Sample Output:
3 4 2 6 5 1
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
#include <sstream>
using namespace std;
vector<int> fororder;
vector<int> inorder;
stack<int> postorder;
void genpost(int inleft,int inright,int fleft)
{
	if(inleft > inright) return;
	//if(inleft == inright) {postorder.push(fororder[fleft]);return;}
	int len = inright - inleft + 1;
	postorder.push(fororder[fleft]);
	int i;
	for(i = inleft;i <= inright;i++)
		if(inorder[i] == fororder[fleft])
			break;
	genpost(i+1,inright,fleft+i-inleft+1);
	genpost(inleft,i-1,fleft+1);
}
int main()
{
	//fstream cin("F://test.txt");
	int N;
	cin >> N;
	stack<int> s;
	for(int i = 0;i < N*2;i++)
	{
		string order;int n;
		cin >> order;
		if(order == "Push")
		{
			cin >> n;fororder.push_back(n);
			s.push(n);
		}
		else if(order == "Pop")
		{
			inorder.push_back(s.top());s.pop();
		}
	}
	genpost(0,N-1,0);
	cout << postorder.top();postorder.pop();
	while(!postorder.empty())
	{
		cout << " " << postorder.top();
		postorder.pop();
	}
	system("pause");
	return 0;
}