/*
A long-distance telephone company charges its customers by the following rules:

Making a long-distance call costs a certain amount per minute, depending on the time of day when the call is made. When a customer starts connecting a long-distance call, the time will be recorded, and so will be the time when the customer hangs up the phone. Every calendar month, a bill is sent to the customer for each minute called (at a rate determined by the time of day). Your job is to prepare the bills for each month, given a set of phone call records.

Input Specification:

Each input file contains one test case. Each case has two parts: the rate structure, and the phone call records.

The rate structure consists of a line with 24 non-negative integers denoting the toll (cents/minute) from 00:00 - 01:00, the toll from 01:00 - 02:00, and so on for each hour in the day.

The next line contains a positive number N (<= 1000), followed by N lines of records. Each phone call record consists of the name of the customer (string of up to 20 characters without space), the time and date (mm:dd:hh:mm), and the word "on-line" or "off-line".

For each test case, all dates will be within a single month. Each "on-line" record is paired with the chronologically next record for the same customer provided it is an "off-line" record. Any "on-line" records that are not paired with an "off-line" record are ignored, as are "off-line" records not paired with an "on-line" record. It is guaranteed that at least one call is well paired in the input. You may assume that no two records for the same customer have the same time. Times are recorded using a 24-hour clock.

Output Specification:

For each test case, you must print a phone bill for each customer.

Bills must be printed in alphabetical order of customers' names. For each customer, first print in a line the name of the customer and the month of the bill in the format shown by the sample. Then for each time period of a call, print in one line the beginning and ending time and date (dd:hh:mm), the lasting time (in minute) and the charge of the call. The calls must be listed in chronological order. Finally, print the total charge for the month in the format shown by the sample.

Sample Input:
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line
Sample Output:
CYJJ 01
01:05:59 01:07:00 61 $12.10
Total amount: $12.10
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
aaa 01
02:00:01 04:23:59 4318 $638.80
Total amount: $638.80
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <cctype>
#include <queue>
#include <fstream>
#include <deque>
#include <list>
#include <set>
#include <iomanip>
using namespace std;
typedef struct Record
{
	string name;
	string time;
	string state;
	Record(string n,string t,string s):name(n),time(t),state(s){}
	void print()
	{
		cout << name << " " << time << " " << state << endl;	}
}record;

vector<int> costunit;
vector<record> records;
int times;
bool cmp(const record& r1,const record& r2)
{
	if(r1.name != r2.name)
		return r1.name < r2.name;
	else
		return r1.time < r2.time;
}
double calcost(string s1,string s2)
{
	if(s1 > s2)
		return 0.0;
	double cost = 0.0;
	int day1 = (s1[0] - '0')*10 + (s1[1] - '0');
	int hour1= (s1[3] - '0')*10 + (s1[4] - '0');
	int min1 = (s1[6] - '0')*10 + (s1[7] - '0');

	int day2 = (s2[0] - '0')*10 + (s2[1] - '0');
	int hour2= (s2[3] - '0')*10 + (s2[4] - '0');
	int min2 = (s2[6] - '0')*10 + (s2[7] - '0');
	times = (day2 - day1)*1440 + (hour2 - hour1)*60 + (min2 - min1);
	if(hour1 == hour2 && day1 == day2)
		return (min2 - min1)*costunit[hour1]/100.0 + 1e-9;
	else
	{
		cost += (60 - min1)*costunit[hour1]/100.0;
		hour1++;			//注意 01：23：59-02：00：00
		if(hour1 == 24)		//要注意跨天的时间 day2>day1 && hour2<hour1
		{
			day1++;hour1 -= 24;
		}
		while(hour2 != hour1 || day1 != day2)
		{
			cost += 60*costunit[hour1]/100.0;
			hour1++;
			if(hour1 == 24)
			{
				day1++;hour1 -= 24;
			}
		}
		cost += min2*costunit[hour2]/100.0;
		return cost + 1e-9;
	}
}
int main()
{
	//fstream cin("F://pb.txt");
	int N;
	for(int i = 0;i < 24;i++)
	{
		int cost;
		cin >> cost;
		costunit.push_back(cost);
	}
	cin >> N;
	for(int j = 0;j < N;j++)
	{
		string name,time,state;
		cin >> name >> time >> state;
		records.push_back(record(name,time,state));
	}
	sort(records.begin(),records.end(),cmp);

	/*for(int j = 0;j < N;j++)
	{
		records[j].print();
	}
	cout << "\n\n";*/

	for(int i = 0;i < N;)
	{
		int flag = 0;
		int cnt;
		double total = 0.0;
		string nowname = records[i].name;
		string nowmonth = records[i].time.substr(0,2);
		for(cnt = i;cnt < N;cnt++)
		{
			if(records[cnt].name != nowname || cnt >= N-1)
				break;
			if(records[cnt].state == "on-line" && records[cnt+1].state == "off-line" && records[cnt].name == records[cnt+1].name && records[cnt].name == nowname)
			{
				if(!flag)
				{
					cout << nowname << " " << nowmonth << endl;
					flag = 1;
				}
				cout << records[cnt].time.substr(3) << " " << records[cnt+1].time.substr(3) << " ";
				double cost = calcost(records[cnt].time.substr(3),records[cnt+1].time.substr(3));
				cout << times << " $";
					
				cout << setiosflags(ios::fixed) << setprecision(2) << cost << endl;
				total += cost;
			}
			if(records[cnt].name != nowname || cnt >= N-1)
				break;
		}
		i = cnt;
		if(flag)
			cout << "Total amount: $" << total << endl;
		if(i == N-1)
			break;
	}

	system("pause");
	return 0;
}