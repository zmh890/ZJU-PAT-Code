/*
Eva loves to collect coins from all over the universe, including some other planets like Mars. One day she visited a universal shopping mall which could accept all kinds of coins as payments. However, there was a special requirement of the payment: for each bill, she must pay the exact amount. Since she has as many as 104 coins with her, she definitely needs your help. You are supposed to tell her, for any given amount of money, whether or not she can find some coins to pay for it.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive numbers: N (<=104, the total number of coins) and M(<=102, the amount of money Eva has to pay). The second line contains N face values of the coins, which are all positive numbers. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the face values V1 <= V2 <= ... <= Vk such that V1 + V2 + ... + Vk = M. All the numbers must be separated by a space, and there must be no extra space at the end of the line. If such a solution is not unique, output the smallest sequence. If there is no solution, output "No Solution" instead.

Note: sequence {A[1], A[2], ...} is said to be "smaller" than sequence {B[1], B[2], ...} if there exists k >= 1 such that A[i]=B[i] for all i < k, and A[k] < B[k].

Sample Input 1:
8 9
5 9 8 7 2 3 4 1
Sample Output 1:
1 3 5
Sample Input 2:
4 8
7 2 4 3
Sample Output 2:
No Solution
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
vector<int> v;
int dp[10005][105];
int flag[10005][105];
int cal(int n,int m)//动态规划部分 看不懂 需要补充一下动态规划的知识
{
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			if(j < v[i] || dp[i-1][j-v[i]] + v[i] < dp[i-1][j])
				dp[i][j] = dp[i-1][j];
			else
			{
				dp[i][j] = dp[i-1][j-v[i]] + v[i];
				flag[i][j] = 1;
			}
	return dp[n][m];
}
int main()
{
	fstream cin("F://test.txt");
	int N,M;
	cin >> N >> M;
	v.reserve(N);
	v.push_back(100000);
	memset(dp,0,sizeof(dp));
	memset(flag,0,sizeof(flag));
	for(int i = 0;i < N;i++)
	{
		int tmp;cin >> tmp;v.push_back(tmp);
	}
	sort(v.begin(),v.end(),greater<int>());
	int t = cal(N,M);
	for(int i = 0;i <= N+1;i++)
	{
		for(int j = 0;j <= N+1;j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}
	cout << endl << endl;
	for(int i = 0;i <= N+1;i++)
	{
		for(int j = 0;j <= N+1;j++)
			cout << flag[i][j] << " ";
		cout << endl;
	}

	if(t != M)
		cout << "No Solution";
	else
	{
		bool fflag = 1;
		while(M)
		{
			while(!flag[N][M]) --N;
			if(fflag) cout << v[N],fflag = 0;
			else cout << " " << v[N];
			M = M - v[N];
			N--;
		}
	}
	system("pause");
	return 0;
}