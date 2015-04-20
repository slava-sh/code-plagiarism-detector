#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:200000000")

#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cassert>

using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define sqr(x) ((x) * (x))
#define forn(i, n) for (int i = 0; i < n; i++)

struct gos
{
	int code;
	set<int> q;
};

bool correct(string& num)
{
	vector<int> pos;
	if (sz(num) < 3 || sz(num) > 7)
		return false;
	if (num[0] == '0')
		return false;
	/*if (sz(num) == 3)
	{
		pos.pb(0);
	}
	if (sz(num) == 4)
	{
		pos.pb(0);
		pos.pb(2);
	}
	if (sz(num) == 5)
	{
		pos.pb(0);
		pos.pb(3);
	}
	if (sz(num) == 6)
	{
		pos.pb(0);
		pos.pb(2);
		pos.pb(4);
	}
	if (sz(num) == 7)
	{
		pos.pb(0);
		pos.pb(3);
		pos.pb(5);
	}*/
	/*forn(i, sz(pos))
		if (num[pos[i]] == '0')
			return false;*/
	return true;
}

void format(string& num)
{
	vector<int> pos;
	if (sz(num) == 3)
	{
		pos.pb(0);
	}
	if (sz(num) == 4)
	{
		pos.pb(0);
		pos.pb(2);
	}
	if (sz(num) == 5)
	{
		pos.pb(0);
		pos.pb(3);
	}
	if (sz(num) == 6)
	{
		pos.pb(0);
		pos.pb(2);
		pos.pb(4);
	}
	if (sz(num) == 7)
	{
		pos.pb(0);
		pos.pb(3);
		pos.pb(5);
	}
	forn(i, sz(pos) - 1)
		cout << num.substr(pos[i], pos[i + 1] - pos[i]) << '-';
	cout << num.substr(pos[sz(pos) - 1], sz(num) - pos[sz(pos) - 1]);
	cout << endl;
}

int main()
{
	freopen("numbers.in", "rt", stdin);
	freopen("numbers.out", "wt", stdout);
	
	int n;
	cin >> n;
	vector<gos> a(n);
	forn(i, n)
	{
		int c, k;
		cin >> c >> k;
		a[i].code = c;
		forn(j, k)
		{
			int b;
			cin >> b;
			a[i].q.insert(b);
		}
	}
	int m;
	cin >> m;
	forn(i, m)
	{
		string num1;
		cin >> num1;
		if (sz(num1) != 11)
			goto dd;
		bool ok = false;
		forn(j, n)
		{
			string num = num1;
			int cur = 0;
			int tmp = 0;
			forn(z, min(sz(num), 3))
			{
				cur *= 10;
				cur += num[z] - '0';
				tmp++;
				if (cur == a[j].code)
					break;
			}
			if (cur != a[j].code)
				goto qq;
			num.erase(num.begin(), num.begin() + tmp);
			int cur1 = 0;
			forn(z, min(sz(num), 6))
			{
				cur1 *= 10;
				cur1 += (num[z] - '0');
				if (a[j].q.count(cur1))
				{
					if (correct(num.substr(z + 1, sz(num) - z - 1)))
					{
						cout << '+' << cur << '(' << cur1 << ')';
						format(num.substr(z + 1, sz(num) - z - 1));
						ok = true;
						goto dd;
					}
				}
			}
			qq:;
		}
		dd:;
		if (!ok)
			cout << "Incorrect\n";
	}
}