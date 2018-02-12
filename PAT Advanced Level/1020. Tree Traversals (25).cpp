/*
Suppose that all the keys in a binary tree are distinct positive integers. Given the postorder and inorder traversal sequences, you are supposed to output the level order traversal sequence of the corresponding binary tree.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=30), the total number of nodes in the binary tree. The second line gives the postorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the level order traversal sequence of the corresponding binary tree. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
Sample Output:
4 1 6 3 5 7 2
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <queue>
#include <stack>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;
typedef struct Node
{
	int ele;
	struct Node* left;
	struct Node* right;
	Node(int e){ele = e;left = NULL;right = NULL;}
}node;
int post[33],in[33];
node* createtree(int postR,int inL,int inR)//递归建立一棵树
{
	if(inL > inR)	return NULL;//此处要格外注意
	if(postR < 0)	return NULL;
	int pos;
	node* home = new node(post[postR]);
	for(pos = inL;pos <= inR;pos++)
		if(in[pos] == post[postR])
			break;
	home->left = createtree(postR-1-(inR-pos),inL,pos-1);
	home->right= createtree(postR-1,pos+1,inR);
	return home;
}
int main()
{
	//fstream cin("F://TTT.txt");
	int num,tmp;
	cin >> num;
	for(int i = 0;i < num;i++)
	{
		cin >> tmp;post[i] = tmp;
	}
	for(int j = 0;j < num;j++)
	{
		cin >> tmp;in[j] = tmp;
	}
	node* home = createtree(num-1,0,num-1);
	queue<node*> q;
	q.push(home);
	while(!q.empty())
	{
		if(q.front() != NULL)
		{
			if(q.front() == home)	cout << q.front()->ele;
			else cout << " " << q.front()->ele;
			q.push(q.front()->left);q.push(q.front()->right);
		}
		q.pop();
	}
	system("pause");
	return 0;
}