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

	fori(i, n)
	{
		if (s[i] == 'c')
			assert(false);
	}

	thash dt;
	bool ok = false;
	for (int i = 1; i <= l; i++)
	{
		if (n % (i + 1) != 0)
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

	cout << "2" << endl << "a" << endl << "b";

//-----------------------------------------------------------
	return 0;
}