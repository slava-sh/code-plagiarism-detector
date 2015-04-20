#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define pb push_back;
#define rs resize;
#define inf 1e9;

typedef vector <int> vi;
typedef pair <int, int> pii;
typedef long long ll;

int main()
{
	freopen("prizes.in", "r", stdin);
	freopen("prizes.out", "w", stdout);
	ll n, m;
	cin >> n >> m;
	if (n == 1)
	{
		cout << (m + 1) / 4;
		return 0;
	}
	if (m == 1)
	{
		cout << (n + 1) / 4;
		return 0;
	}
	cout << min((n + 1) / 4, (m + 1) / 4);
	return 0;
}