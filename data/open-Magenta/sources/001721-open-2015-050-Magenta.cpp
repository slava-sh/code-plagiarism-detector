//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <string>
#include <queue>


using namespace std;

char nxt[4] = {'U', 'R', 'D', 'L'};

int main()
{
	int len = 1;
	int cur_len = 0;
	int cnt = 0;
	int cur = 0;
	while(true)
	{
		if(len == cur_len)
		{
			if(cnt)
			{
				len++;
				cur_len = 0;
				cnt = 0;
			}
			else
			{
				cur_len = 0;
				cnt = 1;
			}
			cur = (cur + 1) % 4;
		}
		int pp = rand();
		if(pp % 10 <= 3)
		{
			cout << nxt[pp % 10] << endl;
			cout.flush();
			char c;
			cin >> c;
			if(c == 'Y' || c == 'E')
			{
				return 0;
			}
		}
		cout << nxt[cur] << endl;
		cout.flush();
		cur_len++;
		char c;
		cin >> c;
		if(c == 'Y' || c == 'E')
		{
			return 0;
		}
		cout.flush();
	}
	return 0;
}