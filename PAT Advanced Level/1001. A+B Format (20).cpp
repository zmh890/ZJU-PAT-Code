/*
Calculate a + b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

Input

Each input file contains one test case. Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.

Output

For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input
-1000000 9
Sample Output
-999,991
*/
#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
	long int a,b;
	long int sum;
	int minusflag = 0;
	stack<char> s;
	cin >> a >> b;
	sum = a + b;
	if(sum < 0) 
	{
		minusflag = 1;
		sum = -sum;
	}
	int cnt = 0;
	if(sum == 0)	s.push('0');
	while(sum != 0)
	{
		s.push(sum % 10 + '0');
		cnt++;
		if(cnt == 3)
		{
			s.push(',');
			cnt = 0;
		}
		sum /= 10;
	}
	if(s.top() == ',') s.pop();
	if(minusflag == 1)	cout << '-';
	while(!s.empty())
	{
		char tmp = s.top();
		cout << tmp;
		s.pop();
	}
	system("pause");
	return 0;
}