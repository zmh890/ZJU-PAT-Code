/*
If a machine can save only 3 significant digits, the float numbers 12300 and 12358.9 are considered equal since they are both saved as 0.123*105 with simple chopping. Now given the number of significant digits on a machine and two float numbers, you are supposed to tell if they are treated equal in that machine.

Input Specification:

Each input file contains one test case which gives three numbers N, A and B, where N (<100) is the number of significant digits, and A and B are the two float numbers to be compared. Each float number is non-negative, no greater than 10100, and that its total digit number is less than 100.

Output Specification:

For each test case, print in a line "YES" if the two numbers are treated equal, and then the number in the standard form "0.d1...dN*10^k" (d1>0 unless the number is 0); or "NO" if they are not treated equal, and then the two numbers in their standard form. All the terms must be separated by a space, with no extra space at the end of a line.

Note: Simple chopping is assumed without rounding.

Sample Input 1:
3 12300 12358.9
Sample Output 1:
YES 0.123*10^5
Sample Input 2:
3 120 128
Sample Output 2:
NO 0.120*10^3 0.128*10^3
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <cstring>
#include <list>
#include <map>
#include <set>
#include <fstream>
#include <iomanip>
using namespace std;
typedef struct NUM
{
	string n;
	int k;
	void print() {cout << "0." << n << "*10^" << k;}
	bool operator == (const struct NUM& nn) const
	{
		return (n == nn.n) && (k == nn.k);
	}
}number;
number trans(string s,int n)
{
	number ans;
	if(s == "0") ans.n = "0",ans.k = 0;
	else
	{
		int signcount = 0;int k;string num;
		int pointpos = s.find('.');
		int it = 0,itstart;
		while((s[it] == '0' || s[it] == '.') && it < s.size()) ++it;//it指向第一个有效数字
		itstart = it;
		
		if(pointpos == string::npos) k = s.size();//指向小数点的位置 判断进位
		else 
		{
			k = pointpos - itstart;
			if(k < 0) ++k;
		}
		//cout << "find::it:::" << itstart << " " << it << endl;
		if(itstart >= s.size()) num = "0",k = 0;
		else
		{
			while(signcount < n && itstart < s.size())
			{
				if(s[itstart] != '.') 
					num += s[itstart],++signcount;
				itstart++;
			}
			//while(itstart < it && itstart < s.size())
			//	if(s[itstart] != '.') num += s[itstart],++itstart;

		}
		ans.n = num;ans.k = k;
	}
	if(ans.n == "0")//注意：0的问题 如果有效数字为3 要写成0.000*10^0
		for(int i = 1;i < n;i++)
			ans.n += "0";
	return ans;
}
int main()
{
	//fstream cin("F://test.txt");
	int N;
	string A,B;
	cin >> N >> A >> B;
	number ansA = trans(A,N);
	number ansB = trans(B,N);
	if(ansA == ansB) cout << "YES ",ansA.print();
	else cout << "NO ",ansA.print(),cout << " ",ansB.print();
	system("pause");
	return 0;
}