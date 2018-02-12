/*
At the beginning of every day, the first person who signs in the computer room will unlock the door, and the last one who signs out will lock the door. Given the records of signing in's and out's, you are supposed to find the ones who have unlocked and locked the door on that day.

Input Specification:

Each input file contains one test case. Each case contains the records for one day. The case starts with a positive integer M, which is the total number of records, followed by M lines, each in the format:

ID_number Sign_in_time Sign_out_time
where times are given in the format HH:MM:SS, and ID number is a string with no more than 15 characters.

Output Specification:

For each test case, output in one line the ID numbers of the persons who have unlocked and locked the door on that day. The two ID numbers must be separated by one space.

Note: It is guaranteed that the records are consistent. That is, the sign in time must be earlier than the sign out time for each person, and there are no two persons sign in or out at the same moment.

Sample Input:
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40
Sample Output:
SC3021234 CS301133
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
#include <algorithm>
#include <functional>
#include <fstream>
using namespace std;
typedef struct Person
{
	string ID;
	string signin;
	string signout;
	Person(string s1,string s2,string s3):ID(s1),signin(s2),signout(s3){};
}person;
struct cmp1
{
	bool operator() (person &s1,person &s2)
	{
		return s1.signin > s2.signin;
	}
};
struct cmp2
{
	bool operator() (person &s1,person &s2)
	{
		return s1.signout < s2.signout;
	}
};
int M;
priority_queue<person,vector<person>,cmp1> p1;
priority_queue<person,vector<person>,cmp2> p2;

int main()
{
	//fstream cin("F://ss.txt");
	cin >> M;
	for(int i = 0;i < M;i ++)
	{
		string t1,t2,t3;
		cin >> t1 >> t2 >> t3;
		person p(t1,t2,t3);
		p1.push(p);
		p2.push(p);
	}
	cout << p1.top().ID << " " << p2.top().ID;
	
	system("pause");
	return 0;
}

