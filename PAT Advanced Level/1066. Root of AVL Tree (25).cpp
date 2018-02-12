/*
An AVL tree is a self-balancing binary search tree. In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property. Figures 1-4 illustrate the rotation rules.

    
    
Now given a sequence of insertions, you are supposed to tell the root of the resulting AVL tree.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=20) which is the total number of keys to be inserted. Then N distinct integer keys are given in the next line. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print ythe root of the resulting AVL tree in one line.

Sample Input 1:
5
88 70 61 96 120
Sample Output 1:
70
Sample Input 2:
7
88 70 61 96 120 90 65
Sample Output 2:
88

*/
#include <iostream>
#include <vector>
#include <string>
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
	int height;
	Node(int n):ele(n){left = NULL;right = NULL;height = 0;}
}node;
int getheight(node* a)
{
	if(a == NULL)
		return 0;
	return max(getheight(a->left),getheight(a->right)) + 1;
}
//直接用AVL平衡方法 左单旋 右单旋 左右双旋 右左双旋
node* SingleLeftRotation(node* a)
{
	node* b = a->left;
	a->left = b->right;
	b->right = a;
	a->height = getheight(a);
	b->height = getheight(b);
	return b;
}
node* SingleRightRotation(node* a)
{
	node* b = a->right;
	a->right = b->left;
	b->left = a;
	a->height = getheight(a);
	b->height = getheight(b);
	return b;
}
node* DoubleLeftRightRotation(node* a)
{
	a->left = SingleRightRotation(a->left);
	return SingleLeftRotation(a);
}
node* DoubleRightLeftRotation(node* a)
{
	a->right = SingleLeftRotation(a->right);
	return SingleRightRotation(a);
}
node* AVL_Insert(node* home,int e)//平衡二叉树插入节点的方法
{
	if(!home)
		return new node(e);
	if(e < home->ele)
	{
		home->left = AVL_Insert(home->left,e);
		if(getheight(home->left)-getheight(home->right) == 2)
			if(e < home->left->ele)
				home = SingleLeftRotation(home);
			else
				home = DoubleLeftRightRotation(home);
	}
	else
	{
		home->right = AVL_Insert(home->right,e);
		if(getheight(home->right)-getheight(home->left) == 2)
			if(e >= home->right->ele)
				home = SingleRightRotation(home);
			else
				home = DoubleRightLeftRotation(home);
	}
	return home;
}
int main()
{
	//fstream cin("F://test.txt");
	int N;
	cin >> N;
	node* root = NULL;
	for(int i = 0;i < N;i++)
	{
		int tmp;cin >> tmp;
		root = AVL_Insert(root,tmp);
	}
	cout << root->ele;
	system("pause");
	return 0;
}