#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
const long long P = 5, Q = 1000000007;
inline long long hashit(string& s)
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
vector<long long>hs, ppows;
inline bool checkUnique(string& s, long long h1,long long h2,int len1,int len2)
{
	vector<int>dp(s.length(), 0);	
	for (int i = 0; i < s.length(); i++)
	{
		int tmp = i - len1 + 1;
		long long curh = hs[i];
		int tmp2 = i - len1;
		if (tmp2 >= 0)
		{
			curh -= hs[tmp2];
		}
		if (curh < 0) curh += Q;
		if (tmp >= 0 && curh == (h1*ppows[i - len1 + 1]) % Q)
		{
			int tmp = i - len1;
			if (tmp >= 0)
			{
				dp[i] += dp[tmp];
			}
			else
			{
				dp[i]++;
			}
		}
		if (h2==-1) continue;
		tmp = i - len2 + 1;
		curh = hs[i];
		tmp2 = i - len2;
		if (tmp2 >= 0)
		{
			curh -= hs[tmp2];
		}
		if (curh < 0) curh += Q;
		if (tmp >= 0 && curh == (h2*ppows[i - len2 + 1]) % Q)
		{
			int tmp = i - len2;
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
	hs.resize(s.length());
	ppows.resize(s.length());
	hs[0] = s[0] - 'a';
	ppows[0] = 1;
	for (int i = 1; i < s.length(); i++)
	{
		ppows[i] = (ppows[i - 1] * P) % Q;
		hs[i] = (hs[i - 1] + (s[i] - 'a')*ppows[i]) % Q;
	}
	long long candh = 0, candp = 1;
	string cand;	
	for (int i = 0; i < l; i++)
	{
		candh = (candh + (s[i] - 'a')*candp) % Q;
		candp = (candp*P) % Q;
		cand += s[i];
		if (checkUnique(s,candh,-1,i+1,0))
		{
			cout << 1 << endl;
			cout << cand << endl;
			return 0;
		}
	}	
	long long c1h=0, c1p = 1;
	string c1;
	for (int len1 = 0; len1 < l && len1 < s.length(); len1++)
	{
		c1 += s[len1];
		c1h = (c1h + (s[len1] - 'a')*c1p) % Q;
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
			if (curh != (c1h*ppows[r2 - c1.length() + 1]) % Q) break;
			r2 -= c1.length();
		}
		string c2;
		long long c2h = 0;
		int c2l = 0;
		for (int l2 = r2; l2 >= max(0, r2 - l - 1);l2--)
		{
			c2l++;
			c2h = (c2h*P + s[l2] - 'a') % Q;			
			if (c2l>l) continue;
			if (checkUnique(s, c1h,c2h,len1+1,c2l))
			{
				for (int i = l2; i <= r2; i++)
				{
					c2 += s[i];
				}
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