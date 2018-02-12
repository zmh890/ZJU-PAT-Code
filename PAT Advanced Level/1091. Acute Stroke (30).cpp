/*
One important factor to identify acute stroke (急性脑卒中) is the volume of the stroke core. Given the results of image analysis in which the core regions are identified in each MRI slice, your job is to calculate the volume of the stroke core.

Input Specification:

Each input file contains one test case. For each case, the first line contains 4 positive integers: M, N, L and T, where M and N are the sizes of each slice (i.e. pixels of a slice are in an M by N matrix, and the maximum resolution is 1286 by 128); L (<=60) is the number of slices of a brain; and T is the integer threshold (i.e. if the volume of a connected core is less than T, then that core must not be counted).

Then L slices are given. Each slice is represented by an M by N matrix of 0's and 1's, where 1 represents a pixel of stroke, and 0 means normal. Since the thickness of a slice is a constant, we only have to count the number of 1's to obtain the volume. However, there might be several separated core regions in a brain, and only those with their volumes no less than T are counted. Two pixels are "connected" and hence belong to the same region if they share a common side, as shown by Figure 1 where all the 6 red pixels are connected to the blue one.


Figure 1
Output Specification:

For each case, output in a line the total volume of the stroke core.

Sample Input:
3 4 5 2
1 1 1 1
1 1 1 1
1 1 1 1
0 0 1 1
0 0 1 1
0 0 1 1
1 0 1 1
0 1 0 0
0 0 0 0
1 0 1 1
0 0 0 0
0 0 0 0
0 0 0 1
0 0 0 1
1 0 0 0
Sample Output:
26
*/
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <algorithm>
#include <fstream>
using namespace std;
int M,N,L,T;
int slices[1286][128][60];
int ans = 0;
typedef struct Region
{
	int x,y,z;
	Region(int x1,int y1,int z1):x(x1),y(y1),z(z1){}
}region;
//定义了六个移动方向 非常巧妙
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = { 0, 0, 1,-1, 0, 0};
int dz[6] = { 0, 0, 0, 0, 1,-1};
bool isinslice(region& r)
{
	if(r.x >= 0 && r.x < M && r.y >= 0 && r.y < N && r.z >= 0 && r.z < L)
		return true;
	return false;
}
void BFS(int x,int y,int z)//三维广度优先搜索 基本流程是不变的
{
	int nowcnt = 1;
	slices[x][y][z] = 0;
	queue<region> q;
	q.push(region(x,y,z));//当前坐标入队
	while(!q.empty())
	{
		region u = q.front();q.pop();
		for(int i = 0;i < 6;i++)//从当前坐标开始 对六个方向进行搜索 
		{
			int nx = u.x + dx[i];
			int ny = u.y + dy[i];
			int nz = u.z + dz[i];
			region tmp(nx,ny,nz);
			if(isinslice(tmp) && slices[nx][ny][nz])
				slices[nx][ny][nz] = 0,q.push(tmp),nowcnt++;
		}
	}
	//cout << "now::" << nowcnt << endl;
	if(nowcnt >= T)
		ans += nowcnt;
}
int main()
{
	//fstream cin("F://test.txt");
	cin >> M >> N >> L >> T;
	for(int k = 0;k < L;k++)
		for(int i = 0;i < M;i++)
			for(int j = 0;j < N;j++)
				cin >> slices[i][j][k];
	for(int k = 0;k < L;k++)
		for(int i = 0;i < M;i++)
			for(int j = 0;j < N;j++)
				if(slices[i][j][k])
					BFS(i,j,k);//三维的广度优先搜索 需要定义六个不同的搜索方向 
	cout << ans;
	system("pause");
	return 0;
}