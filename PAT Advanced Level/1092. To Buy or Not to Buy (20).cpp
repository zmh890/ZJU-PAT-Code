/*
Eva would like to make a string of beads with her favorite colors so she went to a small shop to buy some beads. There were many colorful strings of beads. However the owner of the shop would only sell the strings in whole pieces. Hence Eva must check whether a string in the shop contains all the beads she needs. She now comes to you for help: if the answer is "Yes", please tell her the number of extra beads she has to buy; or if the answer is "No", please tell her the number of beads missing from the string.

For the sake of simplicity, let's use the characters in the ranges [0-9], [a-z], and [A-Z] to represent the colors. For example, the 3rd string in Figure 1 is the one that Eva would like to make. Then the 1st string is okay since it contains all the necessary beads with 8 extra ones; yet the 2nd one is not since there is no black bead and one less red bead.

                                    ppRYYGrrYBR2258
                                    ppRYYGrrYB225
                                    YrR8RrY
                                    Figure 1
Input Specification:

Each input file contains one test case. Each case gives in two lines the strings of no more than 1000 beads which belong to the shop owner and Eva, respectively.

Output Specification:

For each test case, print your answer in one line. If the answer is "Yes", then also output the number of extra beads Eva has to buy; or if the answer is "No", then also output the number of beads missing from the string. There must be exactly 1 space between the answer and the number.

Sample Input 1:
ppRYYGrrYBR2258
YrR8RrY
Sample Output 1:
Yes 8
Sample Input 2:
ppRYYGrrYB225
YrR8RrY
Sample Output 1:
No 2
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

int main()
{
	//fstream cin("F://test.txt");
	int sum[2][200];
	memset(sum,0,sizeof(sum));
	string origin,match;
	cin >> origin >> match;
	for(int i = 0;i < origin.size();i++)
		sum[0][origin[i]]++;
	for(int j = 0;j < match.size();j++)
		sum[1][match[j]]++;
	/*for(int j = 0;j < 100;j++)
	{
		for(int i = 0;i < 2;i++)
		
			cout << sum[i][j] << " ";
		cout << endl;
	}*/
	int extra = 0,missing = 0;
	for(int k = 0;k < 200;k++)
	{
		if(sum[0][k] > sum[1][k])
			extra += sum[0][k] - sum[1][k];
		else if(sum[0][k] < sum[1][k])
			missing += sum[1][k] - sum[0][k];
	}
	if(missing) cout << "No " << missing;
	else cout << "Yes " << extra;
	system("pause");
	return 0;
}