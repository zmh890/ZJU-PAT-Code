/*
Suppose a bank has K windows open for service. There is a yellow line in front of the windows which devides the waiting area into two parts. All the customers have to wait in line behind the yellow line, until it is his/her turn to be served and there is a window available. It is assumed that no window can be occupied by a single customer for more than 1 hour.

Now given the arriving time T and the processing time P of each customer, you are supposed to tell the average waiting time of all the customers.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 numbers: N (<=10000) - the total number of customers, and K (<=100) - the number of windows. Then N lines follow, each contains 2 times: HH:MM:SS - the arriving time, and P - the processing time in minutes of a customer. Here HH is in the range [00, 23], MM and SS are both in [00, 59]. It is assumed that no two customers arrives at the same time.

Notice that the bank opens from 08:00 to 17:00. Anyone arrives early will have to wait in line till 08:00, and anyone comes too late (at or after 17:00:01) will not be served nor counted into the average.

Output Specification:

For each test case, print in one line the average waiting time of all the customers, in minutes and accurate up to 1 decimal place.

Sample Input:
7 3
07:55:00 16
17:00:01 2
07:59:59 15
08:01:00 60
08:00:00 30
08:00:02 2
08:03:00 10
Sample Output:
8.2
*/
//1、设定时间偏移值 以08:00:00为基准 
//2、设定用户和窗口两个优先队列，用户按照到达时间排序，窗口按照当前窗口时间排序
//3、等待时间 = 用户开始服务时间 - 用户到达时间
//4、只要根据窗口时间和用户到达时间比较 若小于等于 开始服务时间=到达时间 否则 开始服务时间=窗口时间
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <queue>
#include <fstream>
#include <iomanip>
using namespace std;
typedef struct Customer
{
	int arrivetimebias;
	int startimebias;
	int processingtime;
	Customer(int arrive,int process):arrivetimebias(arrive),processingtime(process){startimebias = 0;}
	Customer(){}
	double caltimes();
	bool operator < (const struct Customer& c) const
	{
		return this->arrivetimebias > c.arrivetimebias;
	}
}cus;
typedef struct Window
{
	int nowtimebias;
	Window(){nowtimebias = 0;}
	bool operator < (const struct Window& w) const
	{
		return this->nowtimebias > w.nowtimebias;
	}
}win;
int N,K;
priority_queue<cus> customers;
priority_queue<win> windows;
int main()
{
	//fstream cin("F://aaa.txt");
	double total = 0.0;
	cin >> N >> K;
	for(int i = 0;i < N;i++)
	{
		int hour,min,sec;int time;
		char c;
		cin >> hour >> c >> min >> c >> sec >> time;
		int bias = (hour - 8)*3600 + min*60 + sec;
		if(bias >= 32401)
			continue;
		else
			customers.push(cus(bias,time*60));
	}
	int size = customers.size();
	while(K--)//创建初始化窗口 
	{
		win tmpwin;
		windows.push(tmpwin);
	}
	//cout << total << endl;
	//cout << ">>>" << windows.size() << endl;
	/*while(!windows.empty())
	{cout << "windows::" << windows.top().nowtimebias << endl;windows.pop();}
	system("pause");*/
	while(!customers.empty())
	{
		cus tmpcus = customers.top();customers.pop();
		win tmpwin = windows.top();windows.pop();
		if(tmpcus.arrivetimebias >= tmpwin.nowtimebias)
		{
			tmpcus.startimebias = tmpcus.arrivetimebias;
			tmpwin.nowtimebias = tmpcus.arrivetimebias + tmpcus.processingtime;
		}
		else
		{
			tmpcus.startimebias = tmpwin.nowtimebias;
			tmpwin.nowtimebias += tmpcus.processingtime;
			
		}
		total += tmpcus.startimebias - tmpcus.arrivetimebias;
		//cout << tmpcus.startimebias - tmpcus.arrivetimebias << endl;
		windows.push(tmpwin);
	}
	//cout << total << endl;
	cout << setiosflags(ios::fixed) << setprecision(1) << total/60/size << endl;
	system("pause");
	return 0;
}