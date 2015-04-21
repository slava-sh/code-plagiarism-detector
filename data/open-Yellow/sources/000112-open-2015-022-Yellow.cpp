#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 1e5 + 11;

int n, q, ans;

int t[MAX];

bool good(int i)
{
	return i >= 0 && i < n;
}

void solve(int p, int c)
{
	if(good(p - 1) && t[p - 1] == t[p] && t[p - 1] != c)
		ans++;
	if(good(p - 1) && t[p - 1] != t[p] && t[p - 1] == c)
		ans--;
	if(good(p + 1) && t[p + 1] == t[p] && t[p + 1] != c)
		ans++;
	if(good(p + 1) && t[p + 1] != t[p] && t[p + 1] == c)
		ans--;
	t[p] = c;
}

int main()
{
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> t[i];
	for(int i = 1; i < n; i++)
	{
		if(t[i - 1] != t[i])
			ans++;
	}
	ans++;
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		int p, c;
		cin >> p >> c;
		solve(--p, c);
		cout << ans << "\n";
	}
	return 0;
}
