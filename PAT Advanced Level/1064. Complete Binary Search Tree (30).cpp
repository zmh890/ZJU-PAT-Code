/*
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
A Complete Binary Tree (CBT) is a tree that is completely filled, with the possible exception of the bottom level, which is filled from left to right.

Now given a sequence of distinct non-negative integer keys, a unique BST can be constructed if it is required that the tree must also be a CBT. You are supposed to output the level order traversal sequence of this BST.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=1000). Then N distinct non-negative integer keys are given in the next line. All the numbers in a line are separated by a space and are no greater than 2000.

Output Specification:

For each test case, print in one line the level order traversal sequence of the corresponding complete binary search tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

Sample Input:
10
1 2 3 4 5 6 7 8 9 0
Sample Output:
6 3 8 1 5 7 9 0 2 4
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
typedef struct Node
{
	int ele;
	struct Node* left;
	struct Node* right;
}node;
vector<int> v;
node* createtree(int l,int r)
{
	if(l > r) return NULL;
	if(l == r)
	{
		node* root = new node;
		root->ele = v[l];root->left = NULL;root->right = NULL;
		return root;
	}
	int num = r - l + 1;
	int level = 1;
	int completenum = 1;
	while(1)//本题的关键就在于根据完全二叉树的特点 求得当前二叉树(子树)的左子树的节点数 做到这点就可以完成递归了
	{//这个循环是为了求出当前完全二叉树中的完美二叉树结点个数
		if(num >= completenum && num < completenum*2+1)
			break;
		else
			level++,completenum = completenum*2+1;
	}
	int remain = num - completenum;
	int leftnum,rightnum;
	if(remain > (completenum+1)/2)
		leftnum = (completenum - 1)/2 + (completenum+1)/2;
	else
		leftnum = (completenum - 1)/2 + remain;
	rightnum = num - 1 - leftnum;
	node* root = new node;
	root->ele = v[l+leftnum];
	root->left = createtree(l,l+leftnum-1);
	root->right= createtree(l+leftnum+1,r);
	return root;
}
int main()
{
	//fstream cin("F://test.txt");
	int N;
	cin >> N;
	for(int i = 0;i < N;i++)
	{
		int tmp;cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(),v.end());
	node* root = createtree(0,N-1);
	queue<node*> q;
	q.push(root);
	int flag = 1;
	while(!q.empty())
	{
		node* u = q.front();q.pop();
		if(flag) cout << u->ele,flag = 0;
		else cout << " " << u->ele;
		if(u->left) q.push(u->left);
		if(u->right) q.push(u->right);
	}
	system("pause");
	return 0;
}