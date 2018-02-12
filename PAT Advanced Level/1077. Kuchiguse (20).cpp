/*
The Japanese language is notorious for its sentence ending particles. Personal preference of such particles can be considered as a reflection of the speaker's personality. Such a preference is called "Kuchiguse" and is often exaggerated artistically in Anime and Manga. For example, the artificial sentence ending particle "nyan~" is often used as a stereotype for characters with a cat-like personality:

Itai nyan~ (It hurts, nyan~)
Ninjin wa iyada nyan~ (I hate carrots, nyan~)
Now given a few lines spoken by the same character, can you find her Kuchiguse?

Input Specification:

Each input file contains one test case. For each case, the first line is an integer N (2<=N<=100). Following are N file lines of 0~256 (inclusive) characters in length, each representing a character's spoken line. The spoken lines are case sensitive.

Output Specification:

For each test case, print in one line the kuchiguse of the character, i.e., the longest common suffix of all N lines. If there is no such suffix, write "nai".

Sample Input 1:
3
Itai nyan~
Ninjin wa iyadanyan~
uhhh nyan~
Sample Output 1:
nyan~
Sample Input 2:
3
Itai!
Ninjinnwaiyada T_T
T_T
Sample Output 2:
nai
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
int commonpos(const string& s1,const string& s2)
{
	int pos1 = s1.size()-1;int pos2 = s2.size()-1;
	int cnt = 0;
	while(pos1 >= 0 && pos2 >= 0)
		if(s1[pos1] == s2[pos2])
		{
			cnt++;pos1--;pos2--;
		}
		else break;
	return cnt;
}
int main()
{
	//fstream cin("F://test.txt");
	vector<string> v;
	int N;cin >> N;string tmp;getline(cin,tmp);//吸收N后边的回车
	while(N--)
	{
		string tmp;getline(cin,tmp);
		v.push_back(tmp);
		//cout << tmp << endl;
	}
	int commoncnt = v[0].size();
	for(int i = 1;i < v.size();i++)
	{
		int tmp = commonpos(v[i],v[i-1]);
		if(tmp < commoncnt)
			commoncnt = tmp;
	}
	if(commoncnt == 0)
		cout << "nai";
	else
		for(int j = v[0].size() - commoncnt;j < v[0].size();j++)
				cout << v[0][j];
	system("pause");
	return 0;
}