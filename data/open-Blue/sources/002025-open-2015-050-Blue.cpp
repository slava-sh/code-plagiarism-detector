//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <math.h>
#include <string>

using namespace std;

long long mod = 1e9 + 7;
const int maxN = 2e5;
long long p = 17;
long long H[maxN];
long long P[maxN];

long long Hash(int l, int r)
{
	if(l == 0)
	{
		return H[r];
	}
	else
	{
		return (H[r] - H[l - 1] * P[r - l + 1] + mod * mod) % mod;
	}
}



int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int l;
	cin >> l;
	string s;
	cin >> s;
	if((int)s.size() <= l)
	{
		cout << 1 << endl;
		cout << s << endl;
		return 0;
	}
	H[0] = s[0] - 'a';
	P[0] = 1;
	for(int i = 1; i <= (int)s.size(); i++)
	{
		P[i] = (P[i - 1] * p) % mod;
	}
	for(int i = 1; i <(int)s.size(); i++)
	{
		H[i] = (H[i - 1] * p + s[i] - 'a') % mod;
	}
	for(int i = 1; i <= l; i++)
	{
		int cur = 0;
		long long HH = Hash(0, i - 1);
		while(true)
		{
			if(cur + i <= (int)s.size() && Hash(cur, cur + i - 1) == HH)
			{
				cur += i;
			}
			else
			{
				break;
			}
		}
		if(cur == (int)s.size())
		{
			cout << 1 << endl;
			for(int j = 0; j < i; j++)
			{
				cout << s[j];
			}
			cout << endl;
			return 0;
		}
	}
	for(int i = 1; i <= l; i++)
	{
		int cur = 0;
		long long HH = Hash(0, i - 1);
		while(true)
		{
			if(cur + i <= (int)s.size() && Hash(cur, cur + i - 1) == HH)
			{
				cur += i;
			}
			else
			{
				break;
			}
		}
		for(int j = 1; j <= l && cur + j <= (int)s.size(); j++)
		{
			long long HH1 = Hash(cur, cur + j - 1);
			int curr = cur;
			while(true)
			{
				if(curr + i <= (int)s.size() && Hash(curr, curr + i - 1) == HH)
				{
					curr += i;
					continue;
				}
				if(curr + j <= (int)s.size() && Hash(curr, curr + j - 1) == HH1)
				{
					curr += j;
					continue;
				}
				break;
			}
			if(curr == (int)s.size())
			{
				cout << 2 << endl;
				for(int tt = 0; tt < i; tt++)
				{
					cout << s[tt];
				}
				cout << endl;
				for(int tt = 0; tt < j; tt++)
				{
					cout << s[cur + tt];
				}
				cout << endl;
				return 0;
			}
		}
	}
	cout<< 3 << endl;
	cout << "a" << endl;
	cout << "b" << endl;
	cout << "c" << endl;
	return 0;
}