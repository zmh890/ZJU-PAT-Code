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
typedef struct Node
{
	int address;
	char c;
	int next;
	bool bfirst,bsecond;
	Node(){bfirst = false;bsecond = false;}
}node;

int main()
{
	//fstream cin("F://median.txt");
	int start1,start2,N;
	scanf("%d %d %d",&start1,&start2,&N);
	if(start1 == -1 || start2 == -1)	 {printf("-1");system("pause");return 0;}
	if(N <= 1)	{printf("-1");system("pause");return 0;}
	if(start1 == start2)
	{
        printf("%05d\n",start1);
		system("pause");
        return 0;
    }
	vector<node> v(N);
	for(int i = 0;i < N;i++)
	{
		int addr,ne;char cc;
		scanf("%d %c %d",&addr,&cc,&ne);
		v[i].address = addr;v[i].c = cc;v[i].next = ne;
	}
	vector<node>::iterator it1,it2,head1,head2,tmp;
	for(it1 = v.begin();it1 != v.end();it1++)
		if(it1->address == start1) break;
	for(it2 = v.begin();it2 != v.end();it2++)
		if(it2->address == start2) break;
	head1 = it1;head2 = it2;
	while(it1->next != -1)
	{
		it1->bfirst = true;
		for(tmp = v.begin();tmp != v.end();tmp++)
			if(tmp->address == it1->next)
				break;
		if(tmp->next == it1->address)
			break;
		else
			it1 = tmp;
	}
	it1->bfirst = true;
	while(it2->next != -1)
	{
		it2->bsecond = true;
		if(it2->bfirst)
		{
			printf("%05d",it2->address);system("pause");return 0;
		}
		for(tmp = v.begin();tmp != v.end();tmp++)
			if(tmp->address == it2->next)
				break;
		if(tmp->next == it2->address)
			break;
		else
			it2 = tmp;
	}
	it2->bsecond = true;
	printf("-1");
	system("pause");
	return 0;
}