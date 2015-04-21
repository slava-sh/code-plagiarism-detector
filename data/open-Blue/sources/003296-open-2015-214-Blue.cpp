#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
const long long P = 5, Q = 1000000007;
long long hashit(string& s)
{
	if (s.length() == 0) return 0;
	long long ans = s[0] - 'a', ppow = 1;
	for (int i = 1; i < s.length(); i++)
	{
		ppow = (ppow*P) % Q;
		ans = (ans + (s[i] - 'a')*ppow) % Q;
	}
	return ans;
}
bool checkUnique(string& s, string& s1, string&s2)
{
	vector<int>dp(s.length(), 0);
	vector<long long>hs(s.length(), 0), ppows(s.length(), 0);
	hs[0] = s[0] - 'a';
	ppows[0] = 1;
	for (int i = 1; i < s.length(); i++)
	{
		ppows[i] = (ppows[i - 1] * P) % Q;
		hs[i] = (hs[i - 1] + (s[i] - 'a')*ppows[i]) % Q;
	}
	long long h1 = hashit(s1), h2 = hashit(s2);
	for (int i = 0; i < s.length(); i++)
	{
		int tmp = i - s1.length() + 1;
		long long curh = hs[i];
		int tmp2 = i - s1.length();
		if (tmp2 >= 0)
		{
			curh -= hs[tmp2];
		}
		if (curh < 0) curh += Q;
		if (tmp >= 0 && curh == (h1*ppows[i - s1.length() + 1]) % Q)
		{
			int tmp = i - s1.length();
			if (tmp >= 0)
			{
				dp[i] += dp[tmp];
			}
			else
			{
				dp[i]++;
			}
		}
		if (s2.length() == 0) continue;
		tmp = i - s2.length() + 1;
		curh = hs[i];
		tmp2 = i - s2.length();
		if (tmp2 >= 0)
		{
			curh -= hs[tmp2];
		}
		if (curh < 0) curh += Q;
		if (tmp >= 0 && curh == (h2*ppows[i - s2.length() + 1]) % Q)
		{
			int tmp = i - s2.length();
			if (tmp >= 0)
			{
				dp[i] += dp[tmp];
			}
			else
			{
				dp[i]++;
			}
		}
	}
	return dp[s.length() - 1] != 0;
}
int main()
{
	int l;
	cin >> l;
	string s;
	cin >> s;
	vector<long long>hs(s.length(), 0), ppows(s.length(), 0);
	hs[0] = s[0] - 'a';
	ppows[0] = 1;
	for (int i = 1; i < s.length(); i++)
	{
		ppows[i] = (ppows[i - 1] * P) % Q;
		hs[i] = (hs[i - 1] + (s[i] - 'a')*ppows[i]) % Q;
	}
	string cand;
	string emp;
	for (int i = 0; i < l; i++)
	{
		cand += s[i];
		if (checkUnique(s, cand, emp))
		{
			cout << 1 << endl;
			cout << cand << endl;
			return 0;
		}
	}
	int l1 = 0;
	long long c1h = 0, c1p = 1;
	string c1;
	for (int len1 = 1; len1 <= l && l1 + len1 - 1 < s.length(); len1++)
	{
		c1 += s[l1 + len1 - 1];
		c1h = (c1h + (s[l1 + len1 - 1] - 'a')*c1p) % Q;
		c1p = (c1p*P) % Q;
		int r2 = s.length() - 1;
		while (r2 - c1.length() + 1 >= 0)
		{
			long long curh = hs[r2];
			if (r2 - c1.length() >= 0)
			{
				curh -= hs[r2 - c1.length()];
			}
			if (curh < 0) curh += Q;
			if (curh != (c1p*ppows[r2 - c1.length() + 1]) % Q) break;
			r2 -= c1.length();
		}
		for (int l2 = max(0, r2 - l - 1); l2 <= r2; l2++)
		{
			string c2;
			int len2 = r2 - l2 + 1;
			if (len2 > l) continue;
			c2 += s[l2 + len2 - 1];
			if (checkUnique(s, c1, c2))
			{
				cout << 2 << endl;
				cout << c1 << endl;
				cout << c2 << endl;
				return 0;
			}
		}
	}

	cout << 3 << endl;
	cout << "a\nb\nc\n" << endl;
}