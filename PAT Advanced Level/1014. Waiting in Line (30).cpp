/*
Suppose a bank has N windows open for service. There is a yellow line in front of the windows which devides the waiting area into two parts. The rules for the customers to wait in line are:

The space inside the yellow line in front of each window is enough to contain a line with M customers. Hence when all the N lines are full, all the customers after (and including) the (NM+1)st one will have to wait in a line behind the yellow line.
Each customer will choose the shortest line to wait in when crossing the yellow line. If there are two or more lines with the same length, the customer will always choose the window with the smallest number.
Customer[i] will take T[i] minutes to have his/her transaction processed.
The first N customers are assumed to be served at 8:00am.
Now given the processing time of each customer, you are supposed to tell the exact time at which a customer has his/her business done.

For example, suppose that a bank has 2 windows and each window may have 2 custmers waiting inside the yellow line. There are 5 customers waiting with transactions taking 1, 2, 6, 4 and 3 minutes, respectively. At 08:00 in the morning, customer1 is served at window1 while customer2 is served at window2. Customer3 will wait in front of window1 and customer4 will wait in front of window2. Customer5 will wait behind the yellow line.

At 08:01, customer1 is done and customer5 enters the line in front of window1 since that line seems shorter now. Customer2 will leave at 08:02, customer4 at 08:06, customer3 at 08:07, and finally customer5 at 08:10.

Input

Each input file contains one test case. Each case starts with a line containing 4 positive integers: N (<=20, number of windows), M (<=10, the maximum capacity of each line inside the yellow line), K (<=1000, number of customers), and Q (<=1000, number of customer queries).

The next line contains K positive integers, which are the processing time of the K customers.

The last line contains Q positive integers, which represent the customers who are asking about the time they can have their transactions done. The customers are numbered from 1 to K.

Output

For each of the Q customers, print in one line the time at which his/her transaction is finished, in the format HH:MM where HH is in [08, 17] and MM is in [00, 59]. Note that since the bank is closed everyday after 17:00, for those customers who cannot be served before 17:00, you must output "Sorry" instead.

Sample Input
2 2 7 5
1 2 6 4 3 534 2
3 4 5 6 7
Sample Output
08:07
08:06
08:10
17:00
Sorry
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
using namespace std;
vector<int> processtime;
deque<int> line[30];
queue<int> waiting;
vector<int> finishtime;
vector<int> processtimepro;
void transtime(int id,int time)
{
	if(time - processtimepro[id] >= 540)
	{
		cout << "Sorry\n";
		return;
	}
	int hour = time/60 + 8;
	int minute = time%60;
	if(hour < 10)
	{
		cout << "0";
		cout << (char)('0' + hour);
	}
	else
	{
		cout << (char)('0' + hour/10);
		cout << (char)('0' + hour%10);
	}
	cout << ":";
	if(minute < 10)
		cout << "0" << (char)('0' + minute);
	else
	{
		cout << (char)('0' + minute/10);
		cout << (char)('0' + minute%10);
	}
	cout << "\n";
}
int main()
{
	//fstream cin("F://waiting.txt");
	processtime.push_back(-1);
	processtimepro.push_back(-1);
	finishtime.push_back(-1);
	int N,M,K,Q;
	cin >> N >> M >> K >> Q;
	for(int i = 0;i < K;i++)
	{
		int time;
		cin >> time;
		processtime.push_back(time);
		processtimepro.push_back(time);
		finishtime.push_back(0);
	}
	int num = 1;
	for(int j = 0;j < M;j++)
		for(int i = 0;i < N;i++)
		{
			if(num <= K)
				line[i].push_back(num++);
			else
				break;
		}
	for(int i = num;i <= K;i++)
		waiting.push(i);

	int time = 0;
	int mintime = 10000;
	int zeroflag = 0;
	int minum = 0;
	while(time < 600 && !zeroflag)
	{
		mintime = 10000;
		minum = 0;
		zeroflag = 1;
		for(int i = 0;i < N;i++)
		{
			if(!line[i].empty() && processtime[line[i][0]] < mintime && processtime[line[i][0]] > 0)
			{
				zeroflag = 0;
				mintime = processtime[line[i][0]];
				minum = i;
			}
		}
		time += mintime;
		//cout << time << endl;
		for(int i = 0;i < N;i++)
		{
			if(!line[i].empty())
			{
				if(processtime[line[i][0]] >= 0)
					processtime[line[i][0]] -= mintime;
				if(processtime[line[i][0]] <= 0)
				{
					finishtime[line[i][0]] = time;
					line[i].pop_front();
					if(!waiting.empty())
					{
						int tmp = waiting.front();waiting.pop();
						line[i].push_back(tmp);
					}
				}
			}
		}
	}
	for(int k = 1;k <= Q;k++)
	{
		int query;
		cin >> query;

		if(finishtime[query] <= 0)
			finishtime[query] = 600;
		transtime(query,finishtime[query]);
	}

	system("pause");
	return 0;
}