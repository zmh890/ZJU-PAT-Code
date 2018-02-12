/*
Given a list of N student records with name, ID and grade. You are supposed to sort the records with respect to the grade in non-increasing order, and output those student records of which the grades are in a given interval.

Input Specification:

Each input file contains one test case. Each case is given in the following format:

N
name[1] ID[1] grade[1]
name[2] ID[2] grade[2]
... ...
name[N] ID[N] grade[N]
grade1 grade2
where name[i] and ID[i] are strings of no more than 10 characters with no space, grade[i] is an integer in [0, 100], grade1 and grade2 are the boundaries of the grade's interval. It is guaranteed that all the grades are distinct.

Output Specification:

For each test case you should output the student records of which the grades are in the given interval [grade1, grade2] and are in non-increasing order. Each student record occupies a line with the student's name and ID, separated by one space. If there is no student's grade in that interval, output "NONE" instead.

Sample Input 1:
4
Tom CS000001 59
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
60 100
Sample Output 1:
Mike CS991301
Mary EE990830
Joe Math990112
Sample Input 2:
2
Jean AA980920 60
Ann CS01 80
90 95
Sample Output 2:
NONE
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
#include <sstream>
using namespace std;
typedef struct Stu//只是个结构体排序 呃 简单的有点吓人
{
	char name[12];
	char id[12];
	int grade;
	bool operator < (const struct Stu& s) const
	{
		return s.grade < grade;
	}
	void print()
	{
		printf("%s %s\n",name,id);
	}
}stu;
int main()
{
	//fstream cin("F://test.txt");
	//freopen("F://test.txt","r",stdin);
	int N;
	scanf("%d",&N);
	vector<stu> v(N+1),res;
	for(int i = 0;i < N;i++)
	{
		scanf("%s %s %d",v[i].name,v[i].id,&v[i].grade);
	}
	int low,high;
	scanf("%d %d",&low,&high);
	sort(v.begin(),v.end());
	for(int i = 0;i < v.size();i++)
		if(v[i].grade >= low && v[i].grade <= high)
			res.push_back(v[i]);
	if(res.empty()) cout << "NONE";
	else
		for(int j = 0;j < res.size();j++)
			res[j].print();
	;
	return 0;
}