/*
Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

Input Specification:

Each input file contains one test case. Each case occupies one line which contains an N (<= 10100).

Output Specification:

For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.

Sample Input:
12345
Sample Output:
one five

*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	string s;
	stack<string> ss;
	string number[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
	int num = 0;
	cin >> s;
	for(int i = 0;i < s.size();i++)
	{
		num += s[i] - '0';
	}
	if(num == 0)
		ss.push(number[0]);
	while(num != 0)
	{
		int single = num % 10;
		ss.push(number[single]);
		num /= 10;
	}
	string tmp = ss.top();
	cout << tmp;
	ss.pop();
	while(!ss.empty())
	{
		tmp = ss.top();
		cout << ' ' << tmp;
		ss.pop();
	}

	system("pause");
	return 0;
}