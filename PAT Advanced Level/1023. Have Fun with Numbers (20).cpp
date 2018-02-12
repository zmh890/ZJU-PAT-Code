/*
Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, with no duplication. Double it we will obtain 246913578, which happens to be another 9-digit number consisting exactly the numbers from 1 to 9, only in a different permutation. Check to see the result if we double it again!

Now you are suppose to check if there are more numbers with this property. That is, double a given number with k digits, you are to tell if the resulting number consists of only a permutation of the digits in the original number.

Input Specification:

Each input file contains one test case. Each case contains one positive integer with no more than 20 digits.

Output Specification:

For each test case, first print in a line "Yes" if doubling the input number gives a number that consists of only a permutation of the digits in the original number, or "No" if not. Then in the next line, print the doubled number.

Sample Input:
1234567899
Sample Output:
Yes
2469135798
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

int main()
{
	//fstream cin("F://DL.txt");
	string origin,doubled;
	cin >> origin;
	int carry = 0,count = 0;
	for(int i = origin.size()-1;i >= 0;i--)
	{
		int tmp = (origin[i] - '0')*2 + carry;
		carry = tmp/10;
		tmp = tmp%10;
		doubled.push_back('0' + tmp);
	}
	if(carry != 0)	doubled.push_back('0' + carry);
	string sorts = doubled;
	sort(origin.begin(),origin.end());
	sort(sorts.begin(),sorts.end());
	if(origin == sorts)	cout << "Yes\n";
	else  cout << "No\n";
	reverse(doubled.begin(),doubled.end());
	cout << doubled;
	system("pause");
	return 0;
}