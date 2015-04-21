#include <iostream>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <functional>
#include <queue>
#include <deque>
#include <bitset>

#define fori(i, n) for (int i = 0; i < (int)n; i++)

#define forit(i, v) for (auto i = (v).begin(); i != (v).end(); i++)

#define forab(i, a, b) for (int i = (int)a; i < (int)b; i++)

#define m_p(x, y) make_pair(x, y)
using namespace std;
struct file_opener
{
	FILE *in, *out;
	file_opener(string file_name)
	{
		in = freopen((file_name + ".in").c_str(), "r", stdin);
		out = freopen((file_name + ".out").c_str(), "w", stdout);
	}
	file_opener(string input_file, string output_file)
	{
		in = freopen((input_file + ".txt").c_str(), "r", stdin);
		out = freopen((output_file + ".txt").c_str(), "w", stdout);
	}
	~file_opener()
	{
		fclose(in);
		fclose(out);
	}
};

typedef long double ldb;
typedef long long llg;
typedef unsigned long long ullg;

llg p_base = 7, mod1 = 1e9 + 7, mod2 = 1e9 + 9;

struct thash
{
	llg a, b;
	thash()
	{
		a = b = 0;
	}
	thash(llg x)
	{
		a = x % mod1;
		b = x % mod2;
	}
	thash(llg _a, llg _b)
	{
		a = _a % mod1;
		b = _b % mod2;
	}
	thash operator + (thash ob)
	{
		return thash(a + ob.a, b + ob.b);
	}
	thash operator * (llg p)
	{
		return thash(a * p, b * p);
	}
	thash operator * (thash ob)
	{
		return thash(a * ob.a, b * ob.b);
	}
	thash operator - (thash ob)
	{
		return thash(a + 2 * mod1 - ob.a, b + 2 * mod2 - ob.b);
	}
};

bool operator == (thash ob1, thash ob2)
{
	return ob1.a == ob2.a && ob1.b == ob2.b;
}

bool operator != (thash ob1, thash ob2)
{
	return !(ob1 == ob2);
}

bool operator < (thash ob1, thash ob2)
{
	return ob1.a < ob2.a || (ob1.a == ob2.a && ob1.b < ob2.b);
}

const int maxn = 20500;
thash mn[maxn];

void init()
{
	mn[0] = thash(1);
	forab(i, 1, maxn)
		mn[i] = mn[i - 1] * p_base;
}

vector<thash> hashs;

void built(const string &s)
{
	hashs.push_back(s[0]);
	for (int i = 1; i < (int)s.length(); i++)
	{
		hashs.push_back(hashs.back() * p_base + s[i]);
	}
}

thash getHash(int l, int r)
{
	if (l == 0)
		return hashs[r];
	return hashs[r] - hashs[l - 1] * mn[r - l + 1];
}

set<thash> st;

bool check(thash sh1, thash sh2, int n, int l1, int l2)
{
	vector<int> pos;

	pos.push_back(0);

	for (int i = 0; i < (int)pos.size(); i++)
	{
		if (pos[i] + l1 - 1 < n && getHash(pos[i], pos[i] + l1 - 1) == sh1)
		{
			if (pos[i] + l1 == n)
				return true;

			pos.push_back(pos[i] + l1);
		}
		if (pos[i] + l2 - 1 < n && getHash(pos[i], pos[i] + l2 - 1) == sh2)
		{
			if (pos[i] + l2 == n)
				return true;

			pos.push_back(pos[i] + l2);
		}

	}

	return false;
}

pair<bool, string> solve(int l1, int l, thash sh, const string &s)
{
	int n = (int)s.length();

	thash n_hash;

	for (int i = l1; i < n; i++)
	{
		for (int j = 1; j < min(l, n - i); j++)
		{
			n_hash = getHash(i, i + j - 1);
			if (st.find(n_hash) != st.end())
				continue;

			if (check(sh, n_hash, n, l1, j))
			{
				return m_p(true, s.substr(i, j));
			}
			st.insert(n_hash);
		}
	}

	return m_p(false, "");
}

int main()
{
#ifdef LOCAL
	file_opener FileOpener("test");
#else
	file_opener FileOpener("input", "output");
#endif
	cout.setf(cout.fixed);
	cout.precision(10);
//-----------------------------------------------------------

	init();
	int n, l, k;

	string s;
	cin >> l >> s;

	built(s);

	n = s.length();
	if (n <= l)
	{
		cout << "1" << endl << s << endl;
		return 0;
	}
	
	thash dt;
	bool ok = false;
	for (int i = 1; i <= l; i++)
	{
		if (n % i != 0)
			continue;
		dt = getHash(0, i - 1);
		ok = true;
		for (int j = 1; ; j++)
		{
			if ((j + 1) * i - 1>= n)
				break;
			if (getHash(j * i, (j + 1) * i - 1) != dt)
			{
				ok = false;
				break;
			}
		}
		if (ok)
		{
			cout << 1 << endl << s.substr(0, i) << endl;
			return 0;
		}
	}

	bool contain_c = false;

	fori(i, n)
	{
		if (s[i] == 'c')
			contain_c = true;
	}

	if (contain_c)
	{
		for (int i = 1; i <= l; i++)
		{
			dt = getHash(0, i - 1);
			st.clear();
			pair<bool, string> ans = solve(i, l, dt, s);
			if (ans.first)
			{
				cout << 2 << endl << s.substr(0, i) << endl << ans.second << endl;  
				return 0;
			}
		}

		cout << "3" << endl << "a" << endl << "b" << endl << "c";
	}
	else
		cout << "2" << endl << "a" << endl << "b" << endl;


//-----------------------------------------------------------
	return 0;
}