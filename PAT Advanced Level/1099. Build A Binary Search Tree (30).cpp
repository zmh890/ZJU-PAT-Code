/*
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
Given the structure of a binary tree and a sequence of distinct integer keys, there is only one way to fill these keys into the tree so that the resulting tree satisfies the definition of a BST. You are supposed to output the level order traversal sequence of that tree. The sample is illustrated by Figure 1 and 2.


Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=100) which is the total number of nodes in the tree. The next N lines each contains the left and the right children of a node in the format "left_index right_index", provided that the nodes are numbered from 0 to N-1, and 0 is always the root. If one child is missing, then -1 will represent the NULL child pointer. Finally N distinct integer keys are given in the last line.

Output Specification:

For each test case, print in one line the level order traversal sequence of that tree. All the numbers must be separated by a space, with no extra space at the end of the line.

Sample Input:
9
1 6
2 3
-1 -1
-1 4
5 -1
-1 -1
7 -1
-1 8
-1 -1
73 45 11 58 82 25 67 38 42
Sample Output:
58 25 82 11 38 67 45 73 42
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
	int ele;
	struct Node* left;
	struct Node* right;
	Node(int n):ele(n){left = NULL;right = NULL;}
	Node() {left = NULL;right = NULL;}
}node;
vector<pair<int,int>> v;
vector<int> vele;
node* createtree(int n)
{
	if(n == -1) return NULL;
	node* root = new node;
	root->left = createtree(v[n].first);
	root->right= createtree(v[n].second);
	return root;
}
int velecnt = 0;
void inorder(node* now)
{
	if(!now)
		return;
	inorder(now->left);
	now->ele = vele[velecnt++];
	inorder(now->right);
}
int main()
{
	//fstream cin("F://test.txt");
	//freopen("F://test.txt","r",stdin);
	int N; 
	cin >> N;
	v.resize(N);
	vele.resize(N);
	for(int i = 0;i < N;i++)
		cin >> v[i].first >> v[i].second;
	for(int j = 0;j < N;j++)
		cin >> vele[j];
	sort(vele.begin(),vele.end());//输入的乱序ele 排序
	node* root = createtree(0);
	inorder(root);//中序遍历填充值
	queue<node*> q;
	q.push(root);
	int firstflag = 1;
	while(!q.empty())//层序遍历输出
	{
		node* tmp = q.front();q.pop();
		if(firstflag)
			cout << tmp->ele,firstflag = 0;
		else 
			cout << " " << tmp->ele;
		if(tmp->left) q.push(tmp->left);
		if(tmp->right) q.push(tmp->right);
	}
	;
	return 0;
}