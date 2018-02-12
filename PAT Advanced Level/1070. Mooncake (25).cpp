/*
Mooncake is a Chinese bakery product traditionally eaten during the Mid-Autumn Festival. Many types of fillings and crusts can be found in traditional mooncakes according to the region's culture. Now given the inventory amounts and the prices of all kinds of the mooncakes, together with the maximum total demand of the market, you are supposed to tell the maximum profit that can be made.

Note: partial inventory storage can be taken. The sample shows the following situation: given three kinds of mooncakes with inventory amounts being 180, 150, and 100 thousand tons, and the prices being 7.5, 7.2, and 4.5 billion yuans. If the market demand can be at most 200 thousand tons, the best we can do is to sell 150 thousand tons of the second kind of mooncake, and 50 thousand tons of the third kind. Hence the total profit is 7.2 + 4.5/2 = 9.45 (billion yuans).

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers N (<=1000), the number of different kinds of mooncakes, and D (<=500 thousand tons), the maximum total demand of the market. Then the second line gives the positive inventory amounts (in thousand tons), and the third line gives the positive prices (in billion yuans) of N kinds of mooncakes. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print the maximum profit (in billion yuans) in one line, accurate up to 2 decimal places.

Sample Input:
3 200
180 150 100
7.5 7.2 4.5
Sample Output:
9.45
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
typedef struct Product
{
	double amount;
	double price;
	double single;
	
}product;
product v[1005];
bool cmp(const product& i,const product& j)
{
	return i.single > j.single;
}
int main()
{
	//fstream cin("F://test.txt");
	int N,D;
	cin >> N >> D;
	for(int i = 0;i < N;i++)
		cin >> v[i].amount;
	for(int i = 0;i < N;i++)
	{
		cin >> v[i].price;
		v[i].single = v[i].price/v[i].amount;
	}
	sort(v,v+N,cmp);
	/*for(int i = 0;i < id.size();i++)
		cout << id[i] << " ";
	cout << endl;*/
	double profit = 0.0;
	for(int cnt = 0;cnt < N;cnt++)
	{
		if(D <= 0) break;
		if(D > v[cnt].amount)//测试点2 浮点数比较大小的特性 注意 浮点数比较大小 不能有大于等于 等于 小于等于 这样会发生错误 要时刻注意
			profit += v[cnt].price,D -= v[cnt].amount;
		else
			profit += v[cnt].single*D,D = 0;
	}
	printf("%.2f",profit);
	system("pause");
	return 0;
}