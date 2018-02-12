/*
About 900 years ago, a Chinese philosopher Sima Guang wrote a history book in which he talked about people's talent and virtue. According to his theory, a man being outstanding in both talent and virtue must be a "sage（圣人）"; being less excellent but with one's virtue outweighs talent can be called a "nobleman（君子）"; being good in neither is a "fool man（愚人）"; yet a fool man is better than a "small man（小人）" who prefers talent than virtue.

Now given the grades of talent and virtue of a group of people, you are supposed to rank them according to Sima Guang's theory.

Input Specification:

Each input file contains one test case. Each case first gives 3 positive integers in a line: N (<=105), the total number of people to be ranked; L (>=60), the lower bound of the qualified grades -- that is, only the ones whose grades of talent and virtue are both not below this line will be ranked; and H (<100), the higher line of qualification -- that is, those with both grades not below this line are considered as the "sages", and will be ranked in non-increasing order according to their total grades. Those with talent grades below H but virtue grades not are cosidered as the "noblemen", and are also ranked in non-increasing order according to their total grades, but they are listed after the "sages". Those with both grades below H, but with virtue not lower than talent are considered as the "fool men". They are ranked in the same way but after the "noblemen". The rest of people whose grades both pass the L line are ranked after the "fool men".

Then N lines follow, each gives the information of a person in the format:

ID_Number Virtue_Grade Talent_Grade
where ID_Number is an 8-digit number, and both grades are integers in [0, 100]. All the numbers are separated by a space.
Output Specification:

The first line of output must give M (<=N), the total number of people that are actually ranked. Then M lines follow, each gives the information of a person in the same format as the input, according to the ranking rules. If there is a tie of the total grade, they must be ranked with respect to their virtue grades in non-increasing order. If there is still a tie, then output in increasing order of their ID's.

Sample Input:
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
Sample Output:
12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct student
{
	string num;
	int moral;
	int talent;

	student(string n,int m,int t)
	{
		num = n;
		moral = m;
		talent = t;
	}
}stu;
bool compare(const stu& ta,const stu& tb)	//比较函数是本题的关键
{
	if(ta.moral + ta.talent > tb.moral + tb.talent)
		return true;
	else if(ta.moral + ta.talent == tb.moral + tb.talent)
		if(ta.moral > tb.moral)
			return true;
		else if(ta.moral == tb.moral)
			if(ta.num < tb.num)
				return true;
	return false;
}
int main()
{
	long int N;
	int L,H;
	vector<stu> vstu1,vstu2,vstu3,vstu4;
	string n;
	int m,t;
	cin >> N >> L >> H;
	if(N <= 0)
	{
		cout << "0" << endl;
		while(1);
	}
	for(long int i = 0;i < N;i++)
	{
		cin >> n >> m >> t;
		if(m >= L && t >= L)
		{
			stu st(n,m,t);
			if(m >= H && t >= H)
				vstu1.push_back(st);
			else if(m >= H && t < H)
				vstu2.push_back(st);
			else if(m >= t && m < H && t < H)
				vstu3.push_back(st);
			else
				vstu4.push_back(st);

		}
	}
	sort(vstu1.begin(),vstu1.end(),compare);
	sort(vstu2.begin(),vstu2.end(),compare);
	sort(vstu3.begin(),vstu3.end(),compare);
	sort(vstu4.begin(),vstu4.end(),compare);
	cout << vstu1.size() + vstu2.size() + vstu3.size() + vstu4.size() << "\n";//CAUTION!!!!! 将endl换成"\n" 程序才不会超时
	//printf("%ld\n",vstu1.size() + vstu2.size() + vstu3.size() + vstu4.size());
	vstu4.insert(vstu4.begin(),vstu3.begin(),vstu3.end());
	vstu4.insert(vstu4.begin(),vstu2.begin(),vstu2.end());
	vstu4.insert(vstu4.begin(),vstu1.begin(),vstu1.end());
	vector<stu>:: iterator it;
	for(it = vstu4.begin();it != vstu4.end();it++)
		cout << it->num << " " << it->moral << " " << it->talent << "\n";//CAUTION!!!!! 将endl换成"\n" 程序才不会超时
			//printf("%s %d %d\n",it->num.c_str(),it->moral,it->talent);
	system("pause");
	return 0;
}