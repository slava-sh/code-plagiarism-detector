#pragma comment(linker, "/STACK:1000000000")

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <cassert>
#include <iomanip>
#include <memory>
#include <set>
#include <map>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>

using namespace std;

#define pb push_back
#define pob pop_back
#define mp make_pair
#define upb upper_bound
#define lwb lower_bound
#define sz(a) (int)a.size()

typedef long long ll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef pair <int, int> ii;
typedef pair <ll, int> li;
typedef pair <int, ll> il;
typedef pair <ll, ll> lll;
typedef vector <ii> vii;
typedef vector <ll> vll;
typedef double db;
typedef long double ldb;
typedef vector <bool> vb;
typedef vector <vb> vvb;
typedef vector <vvb> vvvb;
typedef set <int> si;
typedef set <ii> sii;
typedef set <ll> sl;
typedef set <lll> sll;
typedef set <li> sli;
typedef set <il> sil;
typedef vector <db> vdb;
typedef vector <ldb> vldb;
typedef vector <si> vsi;

const int N = (int)2e4 + 5;
const ll P = 131;
const ll inf = (ll)1e9 + 7;

ll h[N], p[N];
int dp[N];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	string s;
	int k;
	cin >> k >> s;
	int n = sz(s);
	p[0] = 1;
	for (int i = 1; i < n; ++i)
		p[i] = (p[i - 1] * P) % inf;
	for (int i = 0; i < n; ++i)
		h[i] = ((i > 0 ? h[i - 1] : 0) + ((ll)s[i] * p[i]) % inf) % inf;
	for (int i = 1; i <= min(n, k); ++i)
		if (n % i == 0)
		{
			string ap = "";
			for (int j = 0; j < i; ++j)
				ap += s[j];
			bool f = 0;
			for (int j = 0; j < n; j += i)
				if ((h[j + i - 1] - (j >= 0 ? h[j - 1] : 0) + inf) % inf != (p[j] * h[i - 1]) % inf)
				{
					f = 1;
					break;
				}
			if (!f)
			{
				cout << "1\n" << ap;
				return 0;
			}
		}

	for (int i = 1; i <= min(n, k); ++i)
		for (int q = i - 1; q < n; q += i)
			if ((h[q] - (q >= i ? h[q - i] : 0) + inf) % inf != (p[q - i + 1] * h[i - 1]) % inf)
			{
				for (int j = 1; j <= min(n - q + 1, k); ++j)
				{
					string a1 = "", a2 = "";
					for (int t = 0; t < i; ++t)
						a1 += s[t];
					for (int t = q; t < q + j; ++t)
						a2 += s[t];
					vi dp(n, (int)1e9);
					for (int t = 0; t < n; ++t)
					{
						if (t + 1 >= j && ((h[q + j - 1] - h[q - 1] + inf) % inf * (t - j + 1 >= q ? p[t - j + 1 - q] : 1)) % inf == ((h[t] - (t >= j ? h[t - j] : 0) + inf) % inf * (t - j + 1 < q ? p[q - t + j - 1] : 1)) % inf && (t == j - 1 || dp[t - j] + 1 < dp[t]))
							dp[t] = (t == j - 1 ? 0 : dp[t - j]) + 1;
						if (t + 1 >= i && (h[i - 1] * p[t + 1 - i]) % inf == (h[t] - (t >= i ? h[t - i] : 0) + inf) % inf && (t == i - 1 || dp[t - i] + 1 < dp[t]))
							dp[t] = (t == i - 1 ? 0 : dp[t - i]) + 1;
					}
					if (dp[n - 1] != (int)1e9)
					{
						cout << "2\n" << a1 << '\n' << a2;
						return 0;
					}
				}
				break;
			}
	cout << "3\na\nb\nc\n";
	return 0;
}