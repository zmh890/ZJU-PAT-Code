/*
Eva is trying to make her own color stripe out of a given one. She would like to keep only her favorite colors in her favorite order by cutting off those unwanted pieces and sewing the remaining parts together to form her favorite color stripe.

It is said that a normal human eye can distinguish about less than 200 different colors, so Eva's favorite colors are limited. However the original stripe could be very long, and Eva would like to have the remaining favorite stripe with the maximum length. So she needs your help to find her the best result.

Note that the solution might not be unique, but you only have to tell her the maximum length. For example, given a stripe of colors {2 2 4 1 5 5 6 3 1 1 5 6}. If Eva's favorite colors are given in her favorite order as {2 3 1 5 6}, then she has 4 possible best solutions {2 2 1 1 1 5 6}, {2 2 1 5 5 5 6}, {2 2 1 5 5 6 6}, and {2 2 3 1 1 5 6}.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=200) which is the total number of colors involved (and hence the colors are numbered from 1 to N). Then the next line starts with a positive integer M (<=200) followed by M Eva's favorite color numbers given in her favorite order. Finally the third line starts with a positive integer L (<=10000) which is the length of the given stripe, followed by L colors on the stripe. All the numbers in a line are separated by a space.

Output Specification:

For each test case, simply print in a line the maximum length of Eva's favorite stripe.

Sample Input:
6
5 2 3 1 5 6
12 2 2 4 1 5 5 6 3 1 1 5 6
Sample Output:
7
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
int fcolors[202];
int origin[10005];
int dp[202][10005];
int LCS(int row,int col)//动态规划 最长子序列问题(LCS)的变化问题
{
	memset(dp,0,sizeof(dp));
	for(int i = 1;i <= row;i++)
		for(int j = 1;j <= col;j++)
		{
			int maxone = max(max(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
			//总是找当前位置的上 左 左上三个位置的最大值 然后根据fcolors和origin数字是否匹配判断是否加1
			if(fcolors[i] == origin[j])
				dp[i][j] = maxone + 1;
			else dp[i][j] = maxone;
		}
	return dp[row][col];
}
int main()
{
	//fstream cin("F://test.txt");
	int N;cin >> N;
	int M;cin >> M;
	for(int i = 0;i < M;i++)
		cin >> fcolors[i+1];
	int L;cin >> L;
	for(int j = 0;j < L;j++)
		cin >> origin[j+1];
	cout << LCS(M,L);
	system("pause");
	return 0;
}