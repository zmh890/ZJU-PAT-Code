/*
The highest building in our city has only one elevator. A request list is made up with N positive numbers. The numbers denote at which floors the elevator will stop, in specified order. It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. The elevator will stay for 5 seconds at each stop.

For a given request list, you are to compute the total time spent to fulfill the requests on the list. The elevator is on the 0th floor at the beginning and does not have to return to the ground floor when the requests are fulfilled.

Input Specification:

Each input file contains one test case. Each case contains a positive integer N, followed by N positive numbers. All the numbers in the input are less than 100.

Output Specification:

For each test case, print the total time on a single line.

Sample Input:
3 2 3 1
Sample Output:
41
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
#define UP (6)
#define DOWN (4)
#define STOP (5)

int N;
queue<int> q;
int main()
{
	int sumtime = 0;
	int nowfloor = 0;
	//fstream cin("F://max.txt");
	cin >> N;
	for(int i = 0;i < N;i++)
	{
		int t;
		cin >> t;
		q.push(t);
	}
	while(!q.empty())
	{
		int des = q.front();q.pop();
		if(des > nowfloor)	
		{
			sumtime += (des - nowfloor)*UP + STOP;
		}
		else if(des < nowfloor)
		{
			sumtime += (nowfloor - des)*DOWN + STOP;
		}
		else
		{
			sumtime += STOP;
		}
		nowfloor = des;
	}
	cout << sumtime;
	system("pause");
	return 0;
}
