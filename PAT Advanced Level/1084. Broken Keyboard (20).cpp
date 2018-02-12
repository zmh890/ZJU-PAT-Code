/*
On a broken keyboard, some of the keys are worn out. So when you type some sentences, the characters corresponding to those keys will not appear on screen.

Now given a string that you are supposed to type, and the string that you actually type out, please list those keys which are for sure worn out.

Input Specification:

Each input file contains one test case. For each case, the 1st line contains the original string, and the 2nd line contains the typed-out string. Each string contains no more than 80 characters which are either English letters [A-Z] (case insensitive), digital numbers [0-9], or "_" (representing the space). It is guaranteed that both strings are non-empty.

Output Specification:

For each test case, print in one line the keys that are worn out, in the order of being detected. The English letters must be capitalized. Each worn out key must be printed once only. It is guaranteed that there is at least one worn out key.

Sample Input:
7_This_is_a_test
_hs_s_a_es
Sample Output:
7TI
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
	string origin,match;
	cin >> origin >> match;
	string res;
	int i = 0,j = 0;
	while(i < origin.size() || j < match.size())//测试点4 match已经比较结束 但是origin还没有结束 origin最后的几个字符没有匹配
	{
		//cout << i << " " << j << endl;
		if(j == match.size())
		{
			while(i < origin.size())
				res += toupper(origin[i]),++i;
			break;
		}
		else
			if(origin[i] != match[j])
				res += toupper(origin[i]),i++;
			else
				++i,++j;
	}
	//cout << "res::" << res << endl;
	cout << res[0];
	for(i = 1;i < res.size();i++)
	{
		for(j = 0;j < i;j++)
			if(res[j] == res[i])
				break;
		if(j == i)
			cout << res[i];
	}
	system("pause");
	return 0;
}