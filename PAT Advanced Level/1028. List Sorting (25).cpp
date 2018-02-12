/*
Excel can sort records according to any column. Now you are supposed to imitate this function.

Input

Each input file contains one test case. For each case, the first line contains two integers N (<=100000) and C, where N is the number of records and C is the column that you are supposed to sort the records with. Then N lines follow, each contains a record of a student. A student's record consists of his or her distinct ID (a 6-digit number), name (a string with no more than 8 characters without space), and grade (an integer between 0 and 100, inclusive).

Output

For each test case, output the sorting result in N lines. That is, if C = 1 then the records must be sorted in increasing order according to ID's; if C = 2 then the records must be sorted in non-decreasing order according to names; and if C = 3 then the records must be sorted in non-decreasing order according to grades. If there are several students who have the same name or grade, they must be sorted according to their ID's in increasing order.

Sample Input 1
3 1
000007 James 85
000010 Amy 90
000001 Zoe 60
Sample Output 1
000001 Zoe 60
000007 James 85
000010 Amy 90
Sample Input 2
4 2
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 98
Sample Output 2
000010 Amy 90
000002 James 98
000007 James 85
000001 Zoe 60
Sample Input 3
4 3
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 90
Sample Output 3
000001 Zoe 60
000007 James 85
000002 James 90
000010 Amy 90
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
#include <set>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;
typedef struct Stu
{
	int id;
	string name;
	int grade;
	Stu(){}
}stu;
int N;int C;
bool cmp (const stu& s1,const stu& s2)
{
	if(C == 1)
		return s1.id < s2.id;
	else if(C == 2)
	{
		if(s1.name == s2.name)
			return s1.id < s2.id;
		else
			return s1.name < s2.name;
	}
	else if(C == 3)
	{
		if(s1.grade == s2.grade)
			return s1.id < s2.id;
		else return s1.grade < s2.grade;
	}
}

int main()
{
	//fstream cin("F://lists.txt");
	cin >> N >> C;
	vector<stu> v(N);
	for(int i = 0;i < N;i++)
	{
		cin >> v[i].id >> v[i].name >> v[i].grade;
	}
	sort(v.begin(),v.end(),cmp);
	for(int i = 0;i < N;i++)
		printf("%06d %s %d\n",v[i].id,v[i].name.c_str(),v[i].grade);//printf 要比cout的效率高 同理 scanf与cin 
	//int的处理速度也比string要快 Oh shit！！ 卡着200ms的线啊
	system("pause");
	return 0;
}