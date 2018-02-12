/*
The task of this problem is simple: insert a sequence of distinct positive integers into a hash table, and output the positions of the input numbers. The hash function is defined to be "H(key) = key % TSize" where TSize is the maximum size of the hash table. Quadratic probing (with positive increments only) is used to solve the collisions.

Note that the table size is better to be prime. If the maximum size given by the user is not prime, you must re-define the table size to be the smallest prime number which is larger than the size given by the user.

Input Specification:

Each input file contains one test case. For each case, the first line contains two positive numbers: MSize (<=104) and N (<=MSize) which are the user-defined table size and the number of input numbers, respectively. Then N distinct positive integers are given in the next line. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print the corresponding positions (index starts from 0) of the input numbers in one line. All the numbers in a line are separated by a space, and there must be no extra space at the end of the line. In case it is impossible to insert the number, print "-" instead.

Sample Input:
4 4
10 6 4 15
Sample Output:
0 1 4 -
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
bool isprime(int n)
{
	if(n <= 1) return false;
	if(n == 2) return true;
	for(int i = 2;i*i <= n;i++)
		if(n%i == 0) return false;
	return true;
}
int main()
{
	//fstream cin("F://test.txt");
	int msize,N;
	cin >> msize >> N;
	while(!isprime(msize))
		msize++;
	vector<int> v(msize,-1);
	int flag = 1;
	while(N--)
	{
		int tmp;cin >> tmp;
		int pos = tmp%msize;
		int i;
		for(i = 0;i <= msize;i++)
			if(v[(pos + i*i)%msize] == -1)
			{
				pos = (pos + i*i)%msize;
				break;
			}
		if(i > msize)
			if(flag) cout << "-",flag = 0;
			else cout << " -";
		else
		{
			v[pos] = tmp;
			if(flag) cout << pos,flag = 0;
			else cout << " " << pos;
		}
	}
	system("pause");
	return 0;
}