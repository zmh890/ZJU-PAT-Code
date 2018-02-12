/*
This time you are asked to tell the difference between the lowest grade of all the male students and the highest grade of all the female students.

Input Specification:

Each input file contains one test case. Each case contains a positive integer N, followed by N lines of student information. Each line contains a student's name, gender, ID and grade, separated by a space, where name and ID are strings of no more than 10 characters with no space, gender is either F (female) or M (male), and grade is an integer between 0 and 100. It is guaranteed that all the grades are distinct.

Output Specification:

For each test case, output in 3 lines. The first line gives the name and ID of the female student with the highest grade, and the second line gives that of the male student with the lowest grade. The third line gives the difference gradeF-gradeM. If one such kind of student is missing, output "Absent" in the corresponding line, and output "NA" in the third line instead.

Sample Input 1:

3
Joe M Math990112 89
Mike M CS991301 100
Mary F EE990830 95
Sample Output 1:
Mary EE990830
Joe Math990112
6
Sample Input 2:
1
Jean M AA980920 60
Sample Output 2:
Absent
Jean AA980920
NA
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
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

typedef struct Stu
{
	string name;
	char gender;
	string id;
	int grade;
	Stu(string n,char g,string i,int gr):name(n),gender(g),id(i),grade(gr){}

}stu;
struct cmp1
{
	bool operator ()(const stu& s1,const stu& s2)
	{
		return s1.grade > s2.grade;
	}
};
struct cmp2
{
	bool operator ()(const stu& s1,const stu& s2)
	{
		return s1.grade < s2.grade;
	}
};
priority_queue<stu,vector<stu>,cmp1> males;
priority_queue<stu,vector<stu>,cmp2> females;

int main()
{
	//fstream cin("F://test.txt");
	int N;
	cin >> N;
	for(int i = 0;i < N;i++)
	{
		string name,id;char gender;int grade;
		cin >> name >> gender >> id >> grade;
		if(gender == 'M')	males.push(stu(name,gender,id,grade));
		else if(gender == 'F') females.push(stu(name,gender,id,grade));
	}
	int flag = 0;
	if(females.empty())	cout << "Absent\n",flag = 1;
	else cout << females.top().name << " " << females.top().id << endl;
	if(males.empty())	cout << "Absent\n",flag = 1;
	else cout << males.top().name << " " << males.top().id << endl;
	if(flag) cout << "NA\n";
	else cout << females.top().grade - males.top().grade << endl;
	system("pause");
	return 0;
}