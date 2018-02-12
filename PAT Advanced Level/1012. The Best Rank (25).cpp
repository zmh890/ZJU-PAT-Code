/*
To evaluate the performance of our first year CS majored students, we consider their grades of three courses only: C - C Programming Language, M - Mathematics (Calculus or Linear Algebra), and E - English. At the mean time, we encourage students by emphasizing on their best ranks -- that is, among the four ranks with respect to the three courses and the average grade, we print the best rank for each student.

For example, The grades of C, M, E and A - Average of 4 students are given as the following:

StudentID  C  M  E  A
310101     98 85 88 90
310102     70 95 88 84
310103     82 87 94 88
310104     91 91 91 91
Then the best ranks for all the students are No.1 since the 1st one has done the best in C Programming Language, while the 2nd one in Mathematics, the 3rd one in English, and the last one in average.

Input

Each input file contains one test case. Each case starts with a line containing 2 numbers N and M (<=2000), which are the total number of students, and the number of students who would check their ranks, respectively. Then N lines follow, each contains a student ID which is a string of 6 digits, followed by the three integer grades (in the range of [0, 100]) of that student in the order of C, M and E. Then there are M lines, each containing a student ID.

Output

For each of the M students, print in one line the best rank for him/her, and the symbol of the corresponding rank, separated by a space.

The priorities of the ranking methods are ordered as A > C > M > E. Hence if there are two or more ways for a student to obtain the same best rank, output the one with the highest priority.

If a student is not on the grading list, simply output "N/A".

Sample Input
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999
Sample Output
1 C
1 M
1 E
1 A
3 A
N/A
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
#include <set>
#include <algorithm>
#include <functional>
#include <fstream>
using namespace std;

int N,M;
int nrank[4000][4];
vector< pair<string,int> > v[4];
set<string> s;
char project[4] = {'A','C','M','E'};
bool cmp(pair<string,int> p1,pair<string,int> p2)
{
	return p1.second > p2.second;
}
int main()
{
	//fstream cin("F://ss.txt");
	cin >> N >> M;
	for(int i = 0;i < N;i++)
		nrank[i][0] = nrank[i][1] = nrank[i][2] = nrank[i][3] = i;
	for(int i = 0;i < N;i++)
	{
		string tmps;
		int c,m,e;
		cin >> tmps >> c >> m >> e;
		int a = (c + m + e);
		s.insert(tmps);
		pair<string,int> p;
		p.first = tmps;
		p.second = a;v[0].push_back(p);
		p.second = c;v[1].push_back(p);
		p.second = m;v[2].push_back(p);
		p.second = e;v[3].push_back(p);
	}
	for(int i = 0;i < 4;i++)
	{
		sort(v[i].begin(),v[i].end(),cmp);
		for(int ii = 1;ii < v[i].size();ii++)//并列排名的处理 如排名 1 1 3 4的情况 并不能用 1 1 2 3来排名 
		{
			if(v[i][ii].second == v[i][ii - 1].second)
				nrank[ii][i] = nrank[ii - 1][i];//
		}
	}
	for(int j = 0;j < M;j++)
	{
		string tmp;
		cin >> tmp;
		if(s.find(tmp) == s.end())
			cout << "N/A" << endl;
		else 
		{
			int bestrank = N;
			int ranknum = 0;
			for(int i = 0;i < 4;i++)
			{
				vector< pair<string,int> >::iterator it;
				for(it = v[i].begin();it != v[i].end();it++)
					if(it->first == tmp && nrank[it - v[i].begin()][i] < bestrank)
					{
						bestrank = nrank[it - v[i].begin()][i];
						ranknum = i;
					}
			}
			cout << bestrank + 1 << " " << project[ranknum] << endl;
		}
	}
	system("pause");
	return 0;
}
