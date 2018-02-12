/*
People often have a preference among synonyms of the same word. For example, some may prefer "the police", while others may prefer "the cops". Analyzing such patterns can help to narrow down a speaker's identity, which is useful when validating, for example, whether it's still the same person behind an online avatar.

Now given a paragraph of text sampled from someone's speech, can you find the person's most commonly used word?

Input Specification:

Each input file contains one test case. For each case, there is one line of text no more than 1048576 characters in length, terminated by a carriage return '\n'. The input contains at least one alphanumerical character, i.e., one character from the set [0-9 A-Z a-z].

Output Specification:

For each test case, print in one line the most commonly occurring word in the input text, followed by a space and the number of times it has occurred in the input. If there are more than one such words, print the lexicographically smallest one. The word should be printed in all lower case. Here a "word" is defined as a continuous sequence of alphanumerical characters separated by non-alphanumerical characters or the line beginning/end.

Note that words are case insensitive.

Sample Input:
Can1: "Can a can can a can?  It can!"
Sample Output:
can 5
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
using namespace std;
bool isgood(char& c)
{
	if(isalpha(c))
	{
		c = tolower(c);return true;
	}
	if(isdigit(c))
		return true;
	return false;
}
int main()
{
	//fstream cin("F://test.txt");
	string s;
	getline(cin,s);
	map<string,int> m;
	int start = 0,rear = 0;
	//cout << s.size() << endl;
	while(1)
	{
		while(start < s.size() && !isgood(s[start])) ++start;//start是第一个合法字符的位置
		rear = start;
		//cout << start << " " << rear << endl;s
		if(start >= s.size()) break;
		while(rear < s.size() && isgood(s[rear])) ++rear;//rear是start后边第一个不合法字符的位置
		//cout << start << " " << rear << endl;
		string tmp = s.substr(start,rear - start);
		//cout << tmp << endl;
		if(m.find(tmp) != m.end()) m.find(tmp)->second++;
		else m[tmp] = 1;
		start = rear;
	}
	map<string,int>::iterator it = m.begin(),max = m.begin();
	for(;it != m.end();++it)
		if(it->second > max->second)
			max = it;
	cout << max->first << " " << max->second;
	system("pause");
	return 0;
}