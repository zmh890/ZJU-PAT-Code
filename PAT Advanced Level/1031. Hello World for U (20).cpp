/*
Given any string of N (>=5) characters, you are asked to form the characters into the shape of U. For example, "helloworld" can be printed as:

h  d
e  l
l  r
lowo
That is, the characters must be printed in the original order, starting top-down from the left vertical line with n1 characters, then left to right along the bottom line with n2 characters, and finally bottom-up along the vertical line with n3 characters. And more, we would like U to be as squared as possible -- that is, it must be satisfied that n1 = n3 = max { k| k <= n2 for all 3 <= n2 <= N } with n1 + n2 + n3 - 2 = N.
Input Specification:

Each input file contains one test case. Each case contains one string with no less than 5 and no more than 80 characters in a line. The string contains no white space.

Output Specification:

For each test case, print the input string in the shape of U as specified in the description.

Sample Input:
helloworld!
Sample Output:
h   !
e   d
l   l
lowor
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
void print(const char& c1,const char& c2,int spaces)
{
	cout << c1;
	while(spaces > 0) cout << " ",spaces--;
	cout << c2 << endl;
}
int main()
{
	//fstream cin("F://median.txt");
	string s;
	cin >> s;
	int N = s.size();
	int n13 = 1,n2 = N+2-2*n13;
	while(n13 <= n2)
	{
		n13++;n2 = N+2-2*n13;
	}
	--n13;n2 = N+2-2*n13;
	//cout << n13 << " " << n2 << endl;
	string::iterator it1 = s.begin(),it2 = s.end()-1;
	for(int i = 1;i < n13;i++)
		print(*it1++,*it2--,n2-2);
	while(it1 <= it2)
		cout << *it1++;
	system("pause");
	return 0;
}