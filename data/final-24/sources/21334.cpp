#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

string st, s1, s2;
bool flag1, flag2, flag3, flag;
vector<char> ans;
long long h1, h2;
int cur;

const long long mod = 1000000009;
const long long p = 5;
const long long bp = 200000002; 
long long h[20100];

long long bin_pow(long long a, int n)
{
	if(n == 0) 
		return 1;
	if(n == 1)
		return a;
	if(n & 1)
		return a * bin_pow(a, n - 1) % mod;
	return bin_pow(a * a % mod, n >> 1);
}
long long ha(string & s)
{
	long long res = s[0] - 'a';
	long long t = 5;
	for(int i = 1; i < s.size(); ++i)
	{
		res = (res + (s[i] - 'a') * t) % mod;
		t *= 5;
	}
	return res;
}

bool try_sep(int x1, int x2)
{
	s1 = s2 = "";
	for(int i = 0; i < x1; i++)
		s1 += st[i];
	h1 = ha(s1);
	cur = x1;
	while(st.size() - cur >= x1)
	{
		if(((h[cur + x1 - 1] - h[cur - 1] + mod) % mod) * bin_pow(bp, cur) % mod == h1)
			cur += x1;
		else
		{
			for(int i = 0; i < x2; i++)
				s2 += st[i + cur];
			break;
		}
	}
//	h2 = ha(s2);
	while(st.size() - cur >= min(x1, x2))
	{
		if(st.size() - cur >= x1 && ((h[cur + x1 - 1] - h[cur - 1] + mod) % mod) * bin_pow(bp, cur) % mod == h1)
		{
			cur += x1;
			continue;
		}
		flag = true;
		for(int i = 0; i < x2; i++)
			if(s2[i] != st[i + cur])
			{
				flag = false;
				break;
			}
		if(flag)
		{
			cur += x2;
			continue;
		}
		return false;
	}

	return st.size() == cur;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int l;
	flag1 = flag2 = flag3 = false;
	cin >> l;
	cin >> st;
	h[0] = (long long)(st[0] - 'a');
	long long t = p;
	for(int i = 1; i < st.size(); i++)
	{
		h[i] = ((st[i] - 'a') * t + h[i - 1]) % mod;
		t = t * 5 % mod;
	}

	for(int i = 0; i < st.size(); i++)
	{
		if(st[i] == 'a')
			flag1 = true;
		if(st[i] == 'b')
			flag2 = true;
		if(st[i] == 'c')
			flag3 = true;
	}

	bool flag = true;
	for(int x = min(l, (int)st.size()); x >= 1; x--)
	{
		if(st.size() % x != 0)
			continue;
		flag = true;
		for(int i = 1; i < st.size() / x; i++)
			if(h[x - 1] != ((h[i * x + x - 1] - h[(i - 1) * x + x - 1] + mod) % mod) * bin_pow(bp, i * x) % mod)
			{
				flag = false;
				break;
			}
		if(flag)
		{
			cout << "1\n" << st.substr(st.size() - x);
			return 0;
		}
	}

	for(int o = 1; o <= l; o++)
		for(int t = 1; t <= l; t++)
		{
			if(try_sep(o, t))
			{
				cout << 2 << '\n';
				cout << s1 + '\n' + s2;
				return 0;
			}
		}
		

	if(flag1)
		ans.push_back('a');
	if(flag2)
		ans.push_back('b');
	if(flag3)
		ans.push_back('c');
	cout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
	return 0;
}