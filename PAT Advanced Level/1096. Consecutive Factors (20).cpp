/*
Among all the factors of a positive integer N, there may exist several consecutive numbers. For example, 630 can be factored as 3*5*6*7, where 5, 6, and 7 are the three consecutive numbers. Now given any positive N, you are supposed to find the maximum number of consecutive factors, and list the smallest sequence of the consecutive factors.

Input Specification:

Each input file contains one test case, which gives the integer N (1<N<231).

Output Specification:

For each test case, print in the first line the maximum number of consecutive factors. Then in the second line, print the smallest sequence of the consecutive factors in the format "factor[1]*factor[2]*...*factor[k]", where the factors are listed in increasing order, and 1 is NOT included.

Sample Input:
630
Sample Output:
3
5*6*7
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

int main()
{
	//fstream cin("F://test.txt");
	//freopen("F://test.txt","r",stdin);
	int N;
	scanf("%d",&N);
	int sq = sqrt(N)+1;
	int maxcount = 0;
	int maxfirst = 2;
	for(int i = 2;i <= sq;i++)//想得太多了 不要想太多 如果确实没有好的办法 那就只能用笨办法并优化时间来做
	{
		int cnt = 0;
		int j = i;
		int tmp = N;
		while(tmp%j == 0)
			tmp /= j,cnt++,j++;
		if(cnt > maxcount)
			maxcount = cnt,maxfirst = i;			
	}
	if(maxcount == 0)
		cout << 1 << "\n" << N;
	else
	{
		cout << maxcount << "\n";
		cout << maxfirst;
		while(--maxcount)
			cout << "*" << ++maxfirst;
	}
	;
	return 0;
}