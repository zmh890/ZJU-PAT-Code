/*
The task is really simple: given N exits on a highway which forms a simple cycle, you are supposed to tell the shortest distance between any pair of exits.

Input Specification:

Each input file contains one test case. For each case, the first line contains an integer N (in [3, 105]), followed by N integer distances D1 D2 ... DN, where Di is the distance between the i-th and the (i+1)-st exits, and DN is between the N-th and the 1st exits. All the numbers in a line are separated by a space. The second line gives a positive integer M (<=104), with M lines follow, each contains a pair of exit numbers, provided that the exits are numbered from 1 to N. It is guaranteed that the total round trip distance is no more than 107.

Output Specification:

For each test case, print your results in M lines, each contains the shortest distance between the corresponding given pair of exits.

Sample Input:
5 1 2 4 14 9
3
1 3
2 5
4 1
Sample Output:
3
10
7
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
	int N;int alldis = 0;
	scanf("%d",&N);
	vector<int> v(N+1);v[0] = 0;//vector直接存放1-2,1-2-3,1-2-3-4,...的和 可以直接通过一次减法实现 shit 真是太笨了
	for(int i = 1;i <= N;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		alldis += tmp;v[i] = v[i-1] + tmp;
	}
	int M;
	scanf("%d",&M);
	while(M--)
	{
		int p,q;
		scanf("%d %d",&p,&q);
		int dis1 = abs(v[p-1] - v[q-1]);
		if(dis1 > alldis/2) dis1 = alldis-dis1;
		printf("%d\n",dis1);
	}

	system("pause");
	return 0;
}