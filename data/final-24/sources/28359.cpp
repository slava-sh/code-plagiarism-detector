#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;

const int MAX = 2 * 1e4 + 111;

int l;

string s;

int z[MAX];

void zf(string s)
{
	int size = s.size();
	z[0] = size;
	int l = 0, r = 0;
	for(int i = 1; i < size; i++)
	{
		if(i < r)
			z[i] = min(z[i - l], r - i + 1);
		while(i + z[i] < size && s[z[i]] == s[i + z[i]])
			z[i]++;
		if(i + z[i] > r)
		{
			l = i;
			r = i + z[i] - 1;
		}
	}
}

void check()
{
	int size = s.size();
	for(int i = 1; i <= l; i++)
	{
		if(size % i != 0)
			continue;
		bool f = true;
		for(int j = 0; j < size; j += i)
		{
			if(z[j] < i)
			{
				f = false;
				break;
			}
		}
		if(f)
		{
			cout << 1 << "\n";
			for(int j = 0; j < i; j++)
				cout << s[j];
			exit(0);
		}
	}
}

void solve()
{
	int size = s.size();
	for(int i = 1; i <= l; i++)
	{
		if(size % i != 0)
			continue;
		bool f = true;
		for(int i = 0; i < size; i += l)
		{
			if(z[i] < l)
			{
				f = false;
				break;
			}
			else
			{
				//[i + z[i]; i + l)
			}
		}
		if(f)
		{
			cout << 1 << "\n";
			for(int j = 0; j < i; j++)
				cout << s[j];
			exit(0);
		}
	}
}

int main()
{
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> l >> s;
	zf(s);
	check();
	cout << 2 << "\n";
	cout << "a\nb";
	//solve();
	return 0;
}
