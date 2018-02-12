/*
Eva loves to collect coins from all over the universe, including some other planets like Mars. One day she visited a universal shopping mall which could accept all kinds of coins as payments. However, there was a special requirement of the payment: for each bill, she could only use exactly two coins to pay the exact amount. Since she has as many as 105 coins with her, she definitely needs your help. You are supposed to tell her, for any given amount of money, whether or not she can find two coins to pay for it.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive numbers: N (<=105, the total number of coins) and M(<=103, the amount of money Eva has to pay). The second line contains N face values of the coins, which are all positive numbers no more than 500. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the two face values V1 and V2 (separated by a space) such that V1 + V2 = M and V1 <= V2. If such a solution is not unique, output the one with the smallest V1. If there is no solution, output "No Solution" instead.

Sample Input 1:
8 15
1 2 8 7 2 4 11 15
Sample Output 1:
4 11
Sample Input 2:
7 14
1 8 7 2 4 11 15
Sample Output 2:
No Solution
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cctype>
#include <queue>
#include <stack>
#include <cstring>
#include <list>
#include <map>
#include <set>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

int main()
{
	//fstream cin("F://test.txt");
	int M,N;
	scanf("%d %d",&N,&M);
	vector<int> v(N+1);
	int tmp;
	for(int i = 0;i < N;i++)
	{
		scanf("%d",&tmp);
		if(tmp < M)	v[i] = tmp;
	}
	sort(v.begin(),v.end());//排序完成之后 直接从头尾开始向中间遍历 只需不到一遍即可找到所需的组合
	vector<int>::iterator it1 = v.begin(),it2 = v.end()-1;
	while(it1 < it2)
		if(*it1 + *it2 > M) --it2;
		else if(*it1 + *it2 < M) ++it1;
		else
		{
			printf("%d %d",*it1,*it2);
			system("pause");
			return 0;
		}
	printf("No Solution");
	system("pause");
	return 0;
}