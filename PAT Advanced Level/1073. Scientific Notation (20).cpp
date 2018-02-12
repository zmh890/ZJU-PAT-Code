/*
Scientific notation is the way that scientists easily handle very large numbers or very small numbers. The notation matches the regular expression [+-][1-9]"."[0-9]+E[+-][0-9]+ which means that the integer portion has exactly one digit, there is at least one digit in the fractional portion, and the number and its exponent's signs are always provided even when they are positive.

Now given a real number A in scientific notation, you are supposed to print A in the conventional notation while keeping all the significant figures.

Input Specification:

Each input file contains one test case. For each case, there is one line containing the real number A in scientific notation. The number is no more than 9999 bytes in length and the exponent's absolute value is no more than 9999.

Output Specification:

For each test case, print in one line the input number A in the conventional notation, with all the significant figures kept, including trailing zeros,

Sample Input 1:
+1.23400E-03
Sample Output 1:
0.00123400
Sample Input 2:
-1.2E+10
Sample Output 2:
-12000000000
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

int main()
{
	//fstream cin("F://test.txt");
	string input;
	string res;
	string figure;
	int exponent = 0;
	cin >> input;
	if(input[0] == '-')
		res += '-';
	size_t Epos = input.find('E');
	//计算指数绝对值
	//cout << "exp::" << input.substr(Epos+2,input.size()-Epos-2);
	stringstream ss(input.substr(Epos+2,input.size()-Epos-2));//用一个数字字符串初始化一个stringstream
	ss >> exponent; //stringstream转换成数字
	if(exponent == 0) {cout << res << input.substr(1,Epos-1);system("pause");return 0;}
	//计算figure
	figure += input[1];
	figure += input.substr(3,Epos-3);
	//cout << "exponent::" << exponent << endl;
	//cout << "figure::" << figure << endl;
	if(input[Epos+1] == '-')
	{
		res += "0.";
		for(int i = 0;i < exponent-1;i++)
			res += "0";
		res += figure;
	}
	if(input[Epos+1] == '+')
	{
		if(figure.size()-1 > exponent)
			figure.insert(exponent+1,".");//insert的插入的point的位置要搞清楚才行
		else
		{
			int limit = exponent-figure.size()+1;
			for(int i = 0;i < limit;i++)
				figure += "0";
		}
		res += figure;
	}
	cout << res;
	system("pause");
	return 0;
}