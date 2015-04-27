#include<bits/stdc++.h>

#define M_LIM       100000
#define M_MOD_A     1000000007
#define M_MOD_B     1000000009

using namespace std;

typedef long long   ll;
typedef long double ld;

void calc_pref(const string &s, int *p)
{
	p[0] = 0;
	p[1] = 0;

	for (int i = 2; i <= s.length(); i++)
	{
		p[i] = p[i - 1];

		while (p[i] && s[p[i]] != s[i - 1])
			p[i] = p[p[i]];

		if (s[p[i]] == s[i - 1])
			p[i]++;
	}
}

int is_cycle(const string &s)
{
	bool flag;
	for (int i = 1; i <= sqrt(double(s.length())); i++)
	{
		if (s.length() % i == 0)
		{
			flag = true;
			for (int j = i; flag && j < s.length(); j++)
				if (s[j - i] != s[j])
					flag = false;

			if (flag)
				return i;
		}
	}
	return s.length();
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int p[M_LIM], l, cl;
	int has[3] = { 0 }, let_count = 0;
	string s;

	cin >> l;
	cin >> s;

	for (int i = 0; i < s.length(); i++)
		has[s[i] - 'a'] = 1;
	let_count = has[0] + has[1] + has[2];

	calc_pref(s, p);
	cl = is_cycle(s);

	if (s.length() <= l)
	{
		cout << 1 << endl;
		cout << s;
		return 0;
	}

	if (cl <= l)
	{
		cout << 1 << endl;
		for (int i = 0; i < cl; i++)
			cout << s[i];
		return 0;
	}

	if (s.length() <= 2 * l)
	{
		cout << 2 << endl;
		for (int i = 0; i < l; i++)
			cout << s[i];
		cout << endl;
		for (int i = l; i < s.length(); i++)
			cout << s[i];
		return 0;
	}

	if (let_count == 2)
	{
		cout << 2 << endl;
		for (int i = 0; i < 3; i++)
			if (has[i])
				cout << char('a' + i) << endl;
		return 0;
	}

	bool flag;
	int dc_l, dc_l1, dc_l2;
	string r, t, q;
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = i + 2; j < s.length(); j++)
		{
			r = ""; t = ""; q = "";
			for (int k = 0; k <= i; k++)
				r += s[k];
			for (int k = j; k < s.length(); k++)
				q += s[k];
			for (int k = i + 1; k < j; k++)
				t += s[k];
			dc_l = is_cycle(r);
			dc_l1 = is_cycle(t);
			dc_l2 = is_cycle(q);

			flag = dc_l == dc_l2;
			for (int k = 0; flag && k < dc_l; k++)
				if (r[k] != q[k])
					flag = false;

			if (!flag)
				continue;

			if (dc_l <= l && dc_l1 <= l)
			{
				cout << 2 << endl;
				for (int k = 0; k < dc_l; k++)
					cout << r[k];
				cout << endl;
				for (int k = 0; k < dc_l1; k++)
					cout << t[k];

				return 0;
			}
		}
	}

	cout << "3\na\nb\nc";

	return 0;
}



