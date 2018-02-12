/*
Zhejiang University has 40000 students and provides 2500 courses. Now given the student name lists of all the courses, you are supposed to output the registered course list for each student who comes for a query.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers: N (<=40000), the number of students who look for their course lists, and K (<=2500), the total number of courses. Then the student name lists are given for the courses (numbered from 1 to K) in the following format: for each course i, first the course index i and the number of registered students Ni (<= 200) are given in a line. Then in the next line, Ni student names are given. A student name consists of 3 capital English letters plus a one-digit number. Finally the last line contains the N names of students who come for a query. All the names and numbers in a line are separated by a space.

Output Specification:

For each test case, print your results in N lines. Each line corresponds to one student, in the following format: first print the student's name, then the total number of registered courses of that student, and finally the indices of the courses in increasing order. The query results must be printed in the same order as input. All the data in a line must be separated by a space, with no extra space at the end of the line.

Sample Input:
11 5
4 7
BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
1 4
ANN0 BOB5 JAY9 LOR6
2 7
ANN0 BOB5 FRA8 JAY9 JOE4 KAT3 LOR6
3 1
BOB5
5 9
AMY7 ANN0 BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
ZOE1 ANN0 BOB5 JOE4 JAY9 FRA8 DON2 AMY7 KAT3 LOR6 NON9
Sample Output:
ZOE1 2 4 5
ANN0 3 1 2 5
BOB5 5 1 2 3 4 5
JOE4 1 2
JAY9 4 1 2 4 5
FRA8 3 2 4 5
DON2 2 4 5
AMY7 1 5
KAT3 3 2 4 5
LOR6 4 1 2 4 5
NON9 0
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

vector<set<int>> mp(26*26*26*10);//对于PAT中有明显时间限制的题目 就要考虑用空间换时间 查找时间不要O(logn) 直接O(1)
//map用红黑树实现 在严格时间限制上不能满足要求 这时候 直接分配一个大的vector或者数组 做一个hash表更快一些

int main()
{
	//fstream cin("F://test.txt");
	//fread(stdin,"F://test.txt");
	int N,K;
	scanf("%d%d",&N,&K);
	while(K--)
	{
		int index,Ni;
		scanf("%d%d",&index,&Ni);
		while(Ni--)
		{
			char *tmp = new char[4];scanf("%s",tmp);
			int itmp = (tmp[0]-'A')*26*26*10 + (tmp[1]-'A')*26*10 + (tmp[2]-'A')*10 + tmp[3]-'0';
			mp[itmp].insert(index);
		}
	}
	while(N--)
	{
		char *name = new char[4];scanf("%s",name);
		printf("%s",name);
		int iname = (name[0]-'A')*26*26*10 + (name[1]-'A')*26*10 + (name[2]-'A')*10 + name[3]-'0';
		if(mp.at(iname).empty())
			printf(" 0\n");
		else
		{
			printf(" %d",mp[iname].size());
			for(set<int>::iterator it = mp[iname].begin();it != mp[iname].end();it++)
				printf(" %d",(*it));
			printf("\n");
		}
	}
	system("pause");
	return 0;
}