/*
Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University. Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test. Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive number N (<=100), the number of test locations. Then N ranklists follow, each starts with a line containing a positive integer K (<=300), the number of testees, and then K lines containing the registration number (a 13-digit number) and the total score of each testee. All the numbers in a line are separated by a space.

Output Specification:

For each test case, first print in one line the total number of testees. Then print the final ranklist in the following format:

registration_number final_rank location_number local_rank

The locations are numbered from 1 to N. The output must be sorted in nondecreasing order of the final ranks. The testees with the same score must have the same rank, and the output must be sorted in nondecreasing order of their registration numbers.

Sample Input:
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
Sample Output:
9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4
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
	string reg;
	int score;
	int localnum;
	int finalrank;
	int localrank;
	Stu(string r,int s,int lnum):reg(r),score(s),localnum(lnum){finalrank = 1;localrank = 1;}
	void print()	
	{
		cout << reg << " " << finalrank << " " << localnum << " " << localrank << endl;
	}
}stu;
int N,K;
vector<stu> vall,vlocal;
bool cmp(const stu& t1,const stu& t2)
{
	if(t1.score > t2.score)	return true;
	else if(t1.score == t2.score && t1.reg < t2.reg)
		return true;
	else return false;
}
int main()
{
	//fstream cin("F://rank.txt");
	cin >> N;
	for(int i = 1;i <= N;i++)
	{
		cin >> K;vlocal.clear();
		string r;int s;
		for(int j = 1;j <= K;j++)
		{
			cin >> r >> s;vlocal.push_back(stu(r,s,i));//先压入本地list的vector
		}
		sort(vlocal.begin(),vlocal.end(),cmp);
		vlocal[0].localrank = 1;
		for(int k = 1;k < vlocal.size();k++)
			if(vlocal[k].score == vlocal[k-1].score)		vlocal[k].localrank = vlocal[k-1].localrank;
			else vlocal[k].localrank = k+1;
		vall.insert(vall.end(),vlocal.begin(),vlocal.end());
	}
	sort(vall.begin(),vall.end(),cmp);
	cout << vall.size() << endl;
	vall[0].finalrank = 1;vall[0].print();
	for(int k = 1;k < vall.size();k++)
	{
		if(vall[k].score == vall[k-1].score)		vall[k].finalrank = vall[k-1].finalrank;
		else vall[k].finalrank = k+1;
		vall[k].print();
	}
	system("pause");
	return 0;
}