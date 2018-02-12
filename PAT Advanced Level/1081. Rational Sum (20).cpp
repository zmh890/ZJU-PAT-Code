/*
Given N rational numbers in the form "numerator/denominator", you are supposed to calculate their sum.

Input Specification:

Each input file contains one test case. Each case starts with a positive integer N (<=100), followed in the next line N rational numbers "a1/b1 a2/b2 ..." where all the numerators and denominators are in the range of "long int". If there is a negative number, then the sign must appear in front of the numerator.

Output Specification:

For each test case, output the sum in the simplest form "integer numerator/denominator" where "integer" is the integer part of the sum, "numerator" < "denominator", and the numerator and the denominator have no common factor. You must output only the fractional part if the integer part is 0.

Sample Input 1:
5
2/5 4/15 1/30 -2/60 8/3
Sample Output 1:
3 1/3
Sample Input 2:
2
4/3 2/3
Sample Output 2:
2
Sample Input 3:
3
1/3 -1/6 1/8
Sample Output 3:
7/24
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
typedef long long ll;
int gcd(int m,int n)
{
	return (n == 0)?m:gcd(n,m%n);
}
typedef struct Ration
{
	ll integer;
	ll numer,denom;
	Ration(){integer = 0;numer = 0;denom = 1;}
	Ration(int n,int d):numer(n),denom(d){integer = 0;}
	
	void simplify()//重新考虑这一部分 考虑通用性
	{
		int minusflag = (numer < 0) ? 1:0;//最简化分数
		numer = abs(numer);
		int g = gcd(numer,denom);
		numer /= g;denom /= g;
		numer = minusflag?-numer:numer;
		//化为真分数
		integer += numer/denom;
		numer = abs(numer)%denom;
		numer = minusflag?-numer:numer;
	}
	struct Ration operator + (const struct Ration& r) const//突发奇想 全部用类函数实现 但是这样反而增加了代码量
	{                                                      //另外 完全可以到最后再化成带分数
		int g = gcd(denom,r.denom);
		int den = (denom/g)*r.denom;
		int num = den/denom*numer + den/r.denom*r.numer;
		struct Ration tmp(num,den);
		tmp.integer = integer + r.integer;
		tmp.simplify();
		return tmp;
	}
	void print()
	{
		simplify();
		//cout << "print:::::";
		if(numer == 0) cout << integer;
		else if(integer == 0) cout << numer << "/" << denom;
		else if(numer < 0)
			cout << integer << " " << -numer << "/" << denom;
		else
			cout << integer << " " << numer << "/" << denom;
	}
}ration;
int main()
{
	//fstream cin("F://test.txt");
	//freopen("F://test.txt","r",stdin);
	int N;
	scanf("%d",&N);
	ration res;
	while(N--)
	{
		int n,d;
		scanf("%d/%d",&n,&d);
		//cout <<"nd:::"<< n << " " << d << endl;
		ration tmp(n,d);
		res = res+tmp;
		//res.print();
		//cout << endl;
	}
	res.print();
	;
	return 0;
}