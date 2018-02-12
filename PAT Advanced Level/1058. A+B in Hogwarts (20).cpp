/*
If you are a fan of Harry Potter, you would know the world of magic has its own currency system -- as Hagrid explained it to Harry, "Seventeen silver Sickles to a Galleon and twenty-nine Knuts to a Sickle, it's easy enough." Your job is to write a program to compute A+B where A and B are given in the standard form of "Galleon.Sickle.Knut" (Galleon is an integer in [0, 107], Sickle is an integer in [0, 17), and Knut is an integer in [0, 29)).

Input Specification:

Each input file contains one test case which occupies a line with A and B in the standard form, separated by one space.

Output Specification:

For each test case you should output the sum of A and B in one line, with the same format as the input.

Sample Input:
3.2.1 10.16.27
Sample Output:
14.1.28
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <cstring>
#include <list>
#include <map>
#include <set>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	//fstream cin("F://test.txt");	
	int g,s,k;int gg,ss,kk;
	scanf("%d.%d.%d %d.%d.%d",&g,&s,&k,&gg,&ss,&kk);
	int carry = 0;
	k += kk;carry = k/29;k = k%29;
	s += ss + carry;carry = s/17;s = s%17;
	g += gg + carry;
	printf("%d.%d.%d",g,s,k);
	system("pause");
	return 0;
}