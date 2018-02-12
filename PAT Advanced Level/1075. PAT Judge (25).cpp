/*
The ranklist of PAT is generated from the status list, which shows the scores of the submittions. This time you are supposed to generate the ranklist for PAT.

Input Specification:

Each input file contains one test case. For each case, the first line contains 3 positive integers, N (<=104), the total number of users, K (<=5), the total number of problems, and M (<=105), the total number of submittions. It is then assumed that the user id's are 5-digit numbers from 00001 to N, and the problem id's are from 1 to K. The next line contains K positive integers p[i] (i=1, ..., K), where p[i] corresponds to the full mark of the i-th problem. Then M lines follow, each gives the information of a submittion in the following format:

user_id problem_id partial_score_obtained

where partial_score_obtained is either -1 if the submittion cannot even pass the compiler, or is an integer in the range [0, p[problem_id]]. All the numbers in a line are separated by a space.

Output Specification:

For each test case, you are supposed to output the ranklist in the following format:

rank user_id total_score s[1] ... s[K]

where rank is calculated according to the total_score, and all the users with the same total_score obtain the same rank; and s[i] is the partial score obtained for the i-th problem. If a user has never submitted a solution for a problem, then "-" must be printed at the corresponding position. If a user has submitted several solutions to solve one problem, then the highest score will be counted.

The ranklist must be printed in non-decreasing order of the ranks. For those who have the same rank, users must be sorted in nonincreasing order according to the number of perfectly solved problems. And if there is still a tie, then they must be printed in increasing order of their id's. For those who has never submitted any solution that can pass the compiler, or has never submitted any solution, they must NOT be shown on the ranklist. It is guaranteed that at least one user can be shown on the ranklist.

Sample Input:
7 4 20
20 25 25 30
00002 2 12
00007 4 17
00005 1 19
00007 2 25
00005 1 20
00002 2 2
00005 1 15
00001 1 18
00004 3 25
00002 2 25
00005 3 22
00006 4 -1
00001 2 18
00002 1 20
00004 1 15
00002 4 18
00001 3 4
00001 4 2
00005 2 -1
00004 2 0
Sample Output:
1 00002 63 20 25 - 18
2 00005 42 20 0 22 -
2 00007 42 - 25 - 17
2 00001 42 18 18 4 2
5 00004 40 15 0 25 -
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
int fullscores[6];

int N,K,M;
typedef struct Student
{
	int id;
	int allscore;
	int perfects;
	int judged;
	int scores[6];
	Student()
	{
		id = 100000;
		judged = 0;
		for(int i = 0;i < 6;i++)
			scores[i] = -2;
		allscore = 0;perfects = 0;
	}
	void updatescore(int pid,int score)//-1指编译未通过 -2指未提交
	{
		if(score >= 0) judged = 1;
		if(score > scores[pid]) 
			//注意 要区分三类人：未提交 没有编译通过 编译通过但是得了0分 是不一样的
			//这三类人给的原始分数为 -2，-1，0 输出时转换一下即可 
			//标志位judged一定要有 用来判断这个人有没有有效提交过一道题目 即有没有提交过编译通过的代码
		{
			scores[pid] = score;
			if(score == fullscores[pid])
				perfects++;
			if(score > 0)
			{
				allscore = 0;
				for(int i = 1;i <= K;i++)
					if(scores[i] > 0)
						allscore += scores[i];
			}
		}
	}
	void print()
	{
		printf(" %05d %d",id,allscore);
		for(int i = 1;i <= K;i++)
			if(scores[i] == -2)
				printf(" -");
			else if(scores[i] == -1)
				printf(" 0");
			else printf(" %d",scores[i]);
		//printf(" %d ",perfects);
		printf("\n");
	}
}stu;
stu v[10005];
bool cmp(const stu& s1,const stu& s2)
{
	if(s1.allscore != s2.allscore)
		return s1.allscore > s2.allscore;
	else if(s1.perfects != s2.perfects)
		return s1.perfects > s2.perfects;
	else if(s1.judged != s2.judged)
		return s1.judged > s2.judged;
	else
		return s1.id < s2.id;
}
int main()
{
	//fstream cin("F://test.txt");
	cin >> N >> K >> M;//编号从1开始
	for(int i = 1;i <= N;i++)
		v[i].id = i;
	for(int i = 1;i <= K;i++)
		cin >> fullscores[i];
	while(M--)
	{
		int uid,pid,score;
		cin >> uid >> pid >> score;
		v[uid].updatescore(pid,score);
	}
	//for(int i = 1;i <= N;i++)
	//	v[i].print();
	sort(v+1,v+N+1,cmp);
	cout << 1;v[1].print();
	int nowrank = 1;
	for(int i = 2;i <= N;i++)
	{
		if(v[i].allscore >= 0 && v[i].judged)
		{
			if(v[i].allscore == v[i-1].allscore)
				cout << nowrank;
			else
				cout << i,nowrank = i;
			v[i].print();
		}
	}
	system("pause");
	return 0;
}