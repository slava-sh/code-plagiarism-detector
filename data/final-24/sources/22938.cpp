#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int MAXN = 100500;
string s;
int l;

bool check_first(int dx)
{
	for (int i = 0; i < (int)s.size() - dx; i++)
	{
		if (s[i] != s[i + dx])
			return false;
	}
	return true;
}

bool can_get(int ind, string &t)
{
	if (ind + t.size() > s.size())
		return false;
	for (int i = 0; i < t.size(); i++)
	{
		if (s[ind + i] != t[i])
			return false;
	}
	return true;
}

bool check_second(int len, string &sec)
{
	string fir = s.substr(0, len);
	int spos = 0;
	while (can_get(spos, fir))
		spos += fir.size();

	for (int i = 1; i <= l; i++)
	{
		int pos = spos;
		sec = s.substr(pos, i);
		while (pos != s.size())
		{
			bool flag = false;
			if (can_get(pos, fir))
			{
				pos += fir.size();
				flag = true;
			}
			if (can_get(pos, sec))
			{
				pos += sec.size();
				flag = true;
			}
			if (!flag)
				break;
		}
		if (pos == s.size())
			return true;
	}
	return false;
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	cin >> l;
	cin >> s;
	
	for (int i = 1; i <= l; i++)
	{
		if (check_first(i) && s.size() % i == 0)
		{
			cout << 1 << endl << s.substr(0, i);
			return 0;
		}
	}

	for (int i = 1; i <= l; i++)
	{
		string sec;
		if (check_second(i, sec))
		{
			cout << 2 << endl << s.substr(0, i) << endl << sec;
			return 0;
		}
	}

	printf("3\na\nb\nc");
	return 0;
}