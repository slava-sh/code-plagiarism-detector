#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define LL long long

map <string, int> was[101], id;
string code[101], s;
int n, m, k;

LL get(string s)
{
	LL x = 0;
	for (int i = 0; i < (int)s.length(); ++i)
		x = x * 10 + s[i] - 48;

	return x;
}

int len(LL x)
{
	int res = 0;

	while (x > 0)
	{
		++res;
		x /= 10;
	}

	return res;
}

string fg(int k, string &s, int last)
{
	if (k == 3)
		return s.substr(last, 3);
	if (k == 4)
		return s.substr(last, 2) + "-" + s.substr(last + 2, 2);
	if (k == 5)
		return s.substr(last, 3) + "-" + s.substr(last + 3, 2);
	if (k == 6)	
		return s.substr(last, 2) + "-" + s.substr(last + 2, 2) + "-" + s.substr(last + 4, 2);
	if (k == 7)
		return s.substr(last, 3) + "-" + s.substr(last + 3, 2) + "-" + s.substr(last + 5, 2);			
	return "";
}

string rec(int reg, string &s, int last)
{
	for (int i = 3; i <= 5; ++i)
	{
		string sub = s.substr(last, i);
		if (sub[0] != '0' && was[reg][sub])
		{
			if (s[last + i] != '0')
				return "+" + code[reg] + "(" + sub + ")" + fg(s.length() - i - last, s, last + i) + "\n";
		}
	}	

	return "";
}

int main()
{
	freopen("numbers.in", "r", stdin);
	freopen("numbers.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> code[i] >> k;

		id[code[i]] = i;

		for (int j = 1; j <= k; ++j)
		{
			cin >> s;
			was[i][s] = 1;
		}
	}

	cin >> m;

	for (int i = 1; i <= m; ++i)
	{
		cin >> s;

		if (s[0] == '0')
		{
			cout << "Incorrect\n";
			continue;
		}

		string reg = "";
		bool ok = 0;
		for (int j = 1; j <= 3; ++j)
		{
			string sub = s.substr(0, j);
			if (sub[0] != '0' && id[sub] > 0)
			{
				string res = rec(id[sub], s, j);
				if (res != "")
				{
					cout << res;
					ok = 1;
					break;
				}
			}
		}

		if (!ok)
			cout << "Incorrect\n";
	}
}