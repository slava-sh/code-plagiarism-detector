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
	int lst = 0;
	int len1 = 1;
	int cur_len1 = 0;
	int cnt1 = 0;
	int cur1 = 0;
	while(true)
	{
		while(len <= 150)
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
		len = 1;
		cur_len = 0;
		cnt = 0;
		cur = 0;
		for(int i = 1; i <= 150; i++)
		{
			cout << "U" << endl;
			cout.flush();
			char c;
			cin >> c;
			if(c == 'Y' || c == 'E')
			{
				return 0;
			}
			cout.flush();
		}
		for(int i = 1; i <= 150; i++)
		{
			cout << "R" << endl;
			cout.flush();
			char c;
			cin >> c;
			if(c == 'Y' || c == 'E')
			{
				return 0;
			}
			cout.flush();
		}
	}
	return 0;
}