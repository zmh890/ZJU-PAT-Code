/*
Given an integer with no more than 9 digits, you are supposed to read it in the traditional Chinese way. Output "Fu" first if it is negative. For example, -123456789 is read as "Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu". Note: zero ("ling") must be handled correctly according to the Chinese tradition. For example, 100800 is "yi Shi Wan ling ba Bai".

Input Specification:

Each input file contains one test case, which gives an integer with no more than 9 digits.

Output Specification:

For each test case, print in a line the Chinese way of reading the number. The characters are separated by a space and there must be no extra space at the end of the line.

Sample Input 1:
-123456789
Sample Output 1:
Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu
Sample Input 2:
100800
Sample Output 2:
yi Shi Wan ling ba Bai
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
char number[11][9] = 
{
	"ling","yi","er","san","si","wu","liu","qi","ba","jiu"
};
char unit[7][9] = 
{
	"Shi","Bai","Qian","Wan","Yi"
};
vector<string> res;
void change(string &origin)
{
	if(origin == "0" || origin == "00")
	{
		res.push_back(number[0]);
		return;
	}
	int len = origin.size();
	for(int i = 0;i < origin.size();i++,len--)
	{
		
		if(origin[i] != '0')
		{
			res.push_back(number[origin[i]-'0']);
			switch(len)
			{
				case 9:res.push_back("Yi");break;
				case 8:
				case 4:res.push_back("Qian");break;
				case 7:
				case 3:res.push_back("Bai");break;
				case 6:
				case 2:res.push_back("Shi");break;
				case 5:res.push_back("Wan");break;
			}
		}
		else
		{
			if(len == 5)//此处if else较多 为了避免不必要的语法逻辑混乱 多用几个大括号是值得的
			{//最关键的还是万位的处理
				if(*res.rbegin() == "ling")
					*res.rbegin() = "Wan";
				else if(*res.rbegin() != "Yi")
					res.push_back("Wan");
			}
			else
			{
				if(*res.rbegin() != "ling")
					res.push_back("ling");
			}
		}
	}
}
int main()
{
	//fstream cin("F://test.txt");
	//freopen("F://test.txt","r",stdin);
	string digit;
	//while(1)
	//{
	//	digit.clear();res.clear();
	cin >> digit;
	if(digit[0] == '-') res.push_back("Fu"),digit.erase(0,1);
	//while(digit[0] == '0') digit.erase(0,1);
	change(digit);
	while(*res.rbegin() == number[0] && res.size() > 1) res.pop_back();
	for(int i = 0;i < res.size();i++)
		if(!i) cout << res[i];
		else cout << " " << res[i];
	cout << endl;
	//}	
	;
	return 0;
}