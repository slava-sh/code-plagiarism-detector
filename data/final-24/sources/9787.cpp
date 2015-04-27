#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define problem ""
typedef long long ll;
typedef long double ld;
const int inf = ((int)(1e9));
const ll llinf = ((ll)(1e18));
using namespace std;

int ok, l, dp[111];
string s, t[2];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> l >> s;
	for (int i = 1; i <= l; i++)
	{
		if (!(s.size() % i))
		{
			ok = 1;
			for (int j = 1; j < s.size() / i; j++)
				ok &= (s.substr(j * i, i) == s.substr(0, i));
			if (ok)
			{
				cout << "1\n" << s.substr(0, i);
				return 0;
			}
		}
	}
	for (int a = 1; a <= l; a++)
	{
		for (int b = 1; b <= l; b++)
		{
			for (int i = 0; i < s.size(); i++)
				dp[i] = 0;
			t[0] = s.substr(0, a);
			t[1] = s.substr(a, b);
			dp[a - 1] = 1;
			dp[a + b - 1] = 1;
			dp[b - 1] = (s.substr(0, b) == t[1]);
			for (int i = 0; i < s.size(); i++)
			{
				if (!dp[i])
					continue;
				if (i + a < s.size() && s.substr(i + 1, a) == t[0])
					dp[i + a ] = 1;
				if (i + b < s.size() && s.substr(i + 1, b) == t[1])
					dp[i + b ] = 1;
			}
			if (dp[s.size() - 1])
			{
				cout << "2\n" << t[0] << "\n" << t[1] << "\n";
				return 0;
			}
		}
	}
	set <char> t;
	for (int i = 0; i < s.size(); i++)
		t.insert(s[i]);
	cout << t.size() << "\n";
	for (set <char> :: iterator i = t.begin(); i != t.end(); i++)
		cout << (*i) << "\n";
	return 0;
}
