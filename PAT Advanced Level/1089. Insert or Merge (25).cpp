/*
According to Wikipedia:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list. Each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.

Merge sort works as follows: Divide the unsorted list into N sublists, each containing 1 element (a list of 1 element is considered sorted). Then repeatedly merge two adjacent sublists to produce new sorted sublists until there is only 1 sublist remaining.

Now given the initial sequence of integers, together with a sequence which is a result of several iterations of some sorting method, can you tell which sorting method we are using?

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=100). Then in the next line, N integers are given as the initial sequence. The last line contains the partially sorted sequence of the N numbers. It is assumed that the target sequence is always ascending. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in the first line either "Insertion Sort" or "Merge Sort" to indicate the method used to obtain the partial result. Then run this method for one more iteration and output in the second line the resulting sequence. It is guaranteed that the answer is unique for each test case. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

Sample Input 1:
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
Sample Output 1:
Insertion Sort
1 2 3 5 7 8 9 4 6 0
Sample Input 2:
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
Sample Output 2:
Merge Sort
1 2 3 8 4 5 7 9 0 6

*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <algorithm>
#include <functional>
#include <fstream>
using namespace std;

void merge(vector<int>& a,int begin1,int end1,int begin2,int end2)
{
	int i = begin1;
	int j = begin2;
	int len = end2 - begin1 + 1;
	vector<int> newa(len);
	int t = 0;
	while(i <= end1 && j <= end2)
	{
		if(a[i] <= a[j])
			newa[t++] = a[i++];
		else
			newa[t++] = a[j++];
	}
	while(i <= end1)
		newa[t++] = a[i++];
	while(j <= end2)
		newa[t++] = a[j++];
	t = 0;
	int m = begin1;
	while(m <= end2)
		a[m++] = newa[t++];
}
void mergesort(vector<int>& a,int count)//每cnt个一组进行merge排序 注意最后的残缺组
{
	int len=a.size();  
    int i=0;  
    while(i<len){  //为什么用for不行？？？
        if(i+count-1<len){//两个子数组加起来有count个  
            merge(a,i,i+count/2-1,i+count/2,i+count-1);  
        }else{  
            if(i+count/2<len)//存在两个子数组，后一个残缺  
                merge(a,i,i+count/2-1,i+count/2,len-1);  
        }  
        i=i+count;  
    }  
}
void print(vector<int>& v)
{
	for(int i = 0;i < v.size();i++)
		if(!i) cout << v[i];
		else cout << " " << v[i];
	cout << endl;
}
int main()
{
	fstream cin("F://test.txt");
	//freopen("F://test.txt","r",stdin);
	int N;
	cin >> N;
	vector<int> tmp;
	vector<int> origin(N);
	vector<int> match(N);
	for(int i = 0;i < N;i++)
		cin >> origin[i];
	for(int j = 0;j < N;j++)
		cin >> match[j];
	tmp = origin;
	int len = 1;
	int outflag = 0;
	while(len < N)
	{
		len *= 2;
		mergesort(origin,len);
		//cout << len << "    nownoesdfadf\n";
		if(outflag)
		{
			print(origin);system("pause");
			return 0;
		}
		if(origin == match)
		{
			cout << "Merge Sort\n";
			outflag = 1;
		}
	}
	cout << "Insertion Sort\n";
	int i;
	for(i = 1;i < N;i++)
		if(match[i] < match[i-1])
			break;
	int ttt = match[i];
	for(;i > 0 && match[i-1] > ttt;i--)
		match[i] = match[i-1];
	match[i] = ttt;
	print(match);
	;
	return 0;
}