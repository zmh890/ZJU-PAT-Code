/*
The K-P factorization of a positive integer N is to write N as the sum of the P-th power of K positive integers. You are supposed to write a program to find the K-P factorization of N for any positive integers N, K and P.

Input Specification:

Each input file contains one test case which gives in a line the three positive integers N (<=400), K (<=N) and P (1<P<=7). The numbers in a line are separated by a space.

Output Specification:

For each case, if the solution exists, output in the format:

N = n1^P + ... nK^P

where ni (i=1, ... K) is the i-th factor. All the factors must be printed in non-increasing order.

Note: the solution may not be unique. For example, the 5-2 factorization of 169 has 9 solutions, such as 122 + 42 + 22 + 22 + 12, or 112 + 62 + 22 + 22 + 22, or more. You must output the one with the maximum sum of the factors. If there is a tie, the largest factor sequence must be chosen -- sequence { a1, a2, ... aK } is said to be larger than { b1, b2, ... bK } if there exists 1<=L<=K such that ai=bi for i<L and aL>bL

If there is no solution, simple output "Impossible".

Sample Input 1:
169 5 2
Sample Output 1:
169 = 6^2 + 6^2 + 6^2 + 6^2 + 5^2
Sample Input 2:
169 167 3
Sample Output 2:
Impossible
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
#include <functional>
#include <fstream>
using namespace std;
int N,K,P;
vector<vector<int>> res;
vector<int> one;
bool cmp(const vector<int>& v1,const vector<int> v2)
{
	int sum1 = 0,sum2 = 0;
	for(int i = 0;i < v1.size();i++)
		sum1 += v1[i],sum2 += v2[i];
	if(sum1 != sum2) return sum1 > sum2;
	for(int i = 0;i < v1.size();i++)
		if(v1[i] != v2[i]) return v1[i] > v2[i];
	return false;
}
int intpow(int p,int n)//手写p^n函数
{
	int tmp = p;
	if(n <= 0) return 1;
	for(int i = 1;i < n;i++)
		p *= tmp;
	return p;
}
int nsqrt(int p,int n)//开方函数 p的n次开方
{
	if(p <= 1 || n == 1) return p;
	for(int i = 2;i <= p;i++)
		if(intpow(i,n) > p)
			return i > 1?i-1:1;
	return p;
}
void calremain(int remain)
{
	if(one.size() > K || remain < 0) return;
	if(one.size() == K && remain == 0) res.push_back(one);
	else
	{
		int now;
		if(one.empty())
			now = nsqrt(remain,P)+1;
		else
			now = one[one.size()-1];
		for(int i = now;i > 0;i--)
		{
			int ele = intpow(i,P);
			if(!one.empty() && i > one[one.size()-1] || one.size() == K)
				continue;
			one.push_back(i);

			/*for(int i = 0;i < one.size();i++)
				cout << one[i] << " ";
			cout << endl;*/
			
			calremain(remain-ele);
			one.pop_back();
		}
	}

}
int main()
{
	cin >> N >> K >> P;
	calremain(N);
	sort(res.begin(),res.end(),cmp);
	if(res.empty()) cout << "Impossible";
	else
	{
		cout << N << " = ";
		for(int i = 0;i < res[0].size();i++)
			if(!i) cout << res[0][i] << "^" << P;
			else cout << " + " << res[0][i] << "^" << P;
	}
	;
	return 0;
}