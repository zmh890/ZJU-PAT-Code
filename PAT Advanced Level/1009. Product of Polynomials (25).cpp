/*
This time, you are supposed to find A*B where A and B are two polynomials.

Input Specification:

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10, 0 <= NK < ... < N2 < N1 <=1000.

Output Specification:

For each test case you should output the product of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.

Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 3 3.6 2 6.0 1 1.6
*/
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <fstream>
using namespace std;
typedef struct Node
{
	int exp;
	double coe;
	Node(int e,double c)
	{
		exp = e;
		coe = c;
	}
	void print()
	{
		printf(" %d %.1f",exp,coe);
	}
	void add(struct Node &t)
	{
		if(exp != t.exp)
			return;
		coe += t.coe;		
	}
}node;
node mult(node &n1,node &n2)
{
	return node(n1.exp + n2.exp,n1.coe * n2.coe);
}
struct cmp
{
	bool operator ()(node &n1,node &n2)
	{
		return n1.exp < n2.exp;
	}
};
vector<node> v1,v2,vsum;
priority_queue<node,vector<node>,cmp> p;
int main()
{
	//fstream cin("F://pp.txt");
	int K;
	int e;
	double c;
	cin >> K;
	for(int i = 0;i < K;i++)
	{
		cin >> e >> c;
		v1.push_back(node(e,c));
	}
	cin >> K;
	for(int i = 0;i < K;i++)
	{
		cin >> e >> c;
		v2.push_back(node(e,c));
	}
	for(int i = 0;i < v1.size();i ++)
		for(int j = 0;j < v2.size();j++)
		{
			node tmp = mult(v1[i],v2[j]);
			p.push(tmp);
		}
	while(!p.empty())
	{
		int e = p.top().exp;
		double c = p.top().coe;
		p.pop();
		while(!p.empty() && p.top().exp == e)
		{
			c += p.top().coe;
			p.pop();
		}
		if(fabs(c) > 1e-5)//coe约为零的不要
			vsum.push_back(node(e,c));
	}
	cout << vsum.size();
	for(int i = 0;i < vsum.size();i++)
		vsum[i].print();
	system("pause");
	return 0;
}
