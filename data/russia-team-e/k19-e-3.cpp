#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define LL long long

map <string, int> was, id;
string code, s;
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

int main()
{
	freopen("numbers.in", "r", stdin);
	freopen("numbers.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> code >> k;

		id[code] = i;

		for (int j = 1; j <= k; ++j)
		{
			cin >> s;
			was[s] = i;
		}
	}

	cin >> m;

	for (int i = 1; i <= m; ++i)
	{
		cin >> s;

		string reg = "";
		int last = 0;
		for (int j = 1; j <= 3; ++j)
		{
			string sub = s.substr(0, j);
			if (len(get(sub)) == j && id.count(sub) > 0)
			{
				reg = sub;
				last = j;
			}
		}

		if (reg == "")
		{
			cout << "Incorrect\n";
			continue;
		}	

		string b = "";
		for (int j = 3; j <= 5; ++j)
		{
			string sub = s.substr(last, j);

			if (len(get(sub)) == j && was[sub] == id[reg])
			{
				last += j;
				b = sub;
			}
		}

		if (b == "")
		{
			cout << "Incorrect\n";
			continue;
		}

		int k = 11 - last;
		if (s[last] == '0')
		{
			cout << "Incorrect\n";
			continue;
		}

		cout << "+" << reg << "(" << b << ")";

		if (k == 3)
			cout << s.substr(last, 3);
		if (k == 4)
			cout << s.substr(last, 2) << "-" << s.substr(last + 2, 2);
		if (k == 5)
			cout << s.substr(last, 3) << "-" << s.substr(last + 3, 2);
		if (k == 6)
			cout << s.substr(last, 2) << "-" << s.substr(last + 2, 2) << "-" << s.substr(last + 4, 2);
		if (k == 7)
			cout << s.substr(last, 3) << "-" << s.substr(last + 3, 2) << "-" << s.substr(last + 5, 2);
		cout << '\n';
	}
}