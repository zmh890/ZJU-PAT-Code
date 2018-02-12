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
int Mid;
stack<int> s;
void adjust()
{
	if(lessmid.size() > greatmid.size() + 1)
	{
		auto tmp = lessmid.begin();
		greatmid.insert(*tmp);lessmid.erase(tmp);
	}
	else if(greatmid.size() > lessmid.size())
	{
		auto tmp = greatmid.begin();
		lessmid.insert(*tmp);greatmid.erase(tmp);
	}
	if(!s.empty())
		Mid = *lessmid.begin();
}
int main()
{
	//fstream cin("F://test.txt");
	//freopen("F://test.txt","r",stdin);
	int N;
	scanf("%d",&N);
	while(N--)
	{
		char command[20];
		scanf("%s",command);
		if(strcmp(command,"Push") == 0)
		{
			int e;scanf("%d",&e);
			s.push(e);
			if(s.empty())
				lessmid.insert(e),Mid = e;
			else if(Mid >= e)
				lessmid.insert(e);
			else 
				greatmid.insert(e);
			adjust();
		}
		else if(strcmp(command,"Pop") == 0)
		{
			if(s.empty())
				printf("Invalid\n");
			else
			{
				int m = s.top();
				printf("%d\n",s.top());s.pop();
				if(Mid >= m)
					lessmid.erase(lessmid.find(m));
				else greatmid.erase(greatmid.find(m));
				adjust();
			}
		}
		else if(strcmp(command,"PeekMedian") == 0)
		{
			if(s.empty())
				printf("Invalid\n");
			else
				printf("%d\n",Mid);
		}
		else
			printf("Invalid\n");
	}
	//fclose(stdin);
	;
	return 0;
}