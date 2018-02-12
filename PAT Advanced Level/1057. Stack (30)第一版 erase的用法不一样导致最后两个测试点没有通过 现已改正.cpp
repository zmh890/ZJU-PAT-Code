/*
Stack is one of the most fundamental data structures, which is based on the principle of Last In First Out (LIFO). The basic operations include Push (inserting an element onto the top position) and Pop (deleting the top element). Now you are supposed to implement a stack with an extra operation: PeekMedian -- return the median value of all the elements in the stack. With N elements, the median value is defined to be the (N/2)-th smallest element if N is even, or ((N+1)/2)-th if N is odd.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<= 105). Then N lines follow, each contains a command in one of the following 3 formats:

Push key
Pop
PeekMedian
where key is a positive integer no more than 105.

Output Specification:

For each Push command, insert key into the stack and output nothing. For each Pop or PeekMedian command, print in a line the corresponding returned value. If the command is invalid, print "Invalid" instead.

Sample Input:
17
Pop
PeekMedian
Push 3
PeekMedian
Push 2
PeekMedian
Push 1
PeekMedian
Pop
Pop
Push 5
Push 4
PeekMedian
Pop
Pop
Pop
Pop
Sample Output:
Invalid
Invalid
3
2
2
1
2
4
4
5
3
Invalid
*/
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
#include <functional>
#include <fstream>
using namespace std;
multiset<int,greater<int>> lessmid;//要保证lessmid的元素与greatmid的元素个数相等或者多1
multiset<int> greatmid;
void adjust()
{
	while(lessmid.size() > greatmid.size() + 1)
	{
		auto tmp = lessmid.begin();
		greatmid.insert(*tmp);lessmid.erase(tmp);
	}
	while(greatmid.size() > lessmid.size())
	{
		auto tmp = greatmid.begin();
		lessmid.insert(*tmp);greatmid.erase(tmp);
	}
}
void insertmid(int m)
{
	if(lessmid.empty())
	{
		lessmid.insert(m);
		return;
	}
	if(*lessmid.begin() >= m)
		lessmid.insert(m);
	else 
		greatmid.insert(m);
	adjust();
}
void deletemid(int m)
{
    //set的erase函数 还是要给它iterator参数 用value_type类型的参数还是会有问题的！！！！！！！！！！！！！
    //因为这个问题 导致最后的两个测试点总是不通过 shit shit shit
    //原因找到 因为multiset中有重复元素 如果用value_type作为参数 会将所有所有所有与该int参数等价的元素删除！！！！
    //但是如果用iterator作为单个参数 则只会删除该iterator指向的一个一个一个元素！！！！！！！
    //要记住要记住要记住这个区别！！！
	if(lessmid.find(m) != lessmid.end()) 
		lessmid.erase(lessmid.find(m));
	else if(greatmid.find(m) != greatmid.end())
		greatmid.erase(greatmid.find(m));
	adjust();
}
int main()
{
	//fstream cin("F://test.txt");
	//freopen("F://test.txt","r",stdin);
	int N;
	scanf("%d",&N);
	stack<int> s;
	while(N--)
	{
		char command[20];
		scanf("%s",command);
		//printf("==================%s========\n",command);
		if(strcmp(command,"Push") == 0)
		{
			int e;scanf("%d",&e);
			s.push(e);insertmid(e);
		}
		else if(strcmp(command,"Pop") == 0)
		{
			if(s.empty())
				printf("Invalid\n");
			else
			{
				printf("%d\n",s.top());
				deletemid(s.top());s.pop();
			}
		}
		else if(strcmp(command,"PeekMedian") == 0)
		{
			if(s.empty())
				printf("Invalid\n");
			else
				printf("%d\n",*lessmid.begin());
		}
		else
			printf("Invalid\n");
	}
	//fclose(stdin);
	;//断点处
	return 0;
}