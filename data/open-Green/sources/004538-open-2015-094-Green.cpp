#include<iostream>
#include<cstdlib>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<time.h>
#define ll long long
#define ld long double
#define cs(a) ((int)a.size())
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define BAD -1001230000
using namespace std;



unordered_map<ll, ll> ma;
ll a[1000000];
int as  = 0;

ll solve(ll n, int k) {
	if (ma.count(n * 11 + k))
		return ma[n * 11 + k];
	if (k == 0) {
		return n;
	}
	ll c = n;
	for (int i = 0; i < as; ++i) {
		if (a[i] * a[i] > n) break;
		if (n % a[i] == 0) {
			c = min(c, (a[i] / 2 + a[i] % 2) * solve(n / a[i], k - 1));
			c = min(c, (n / a[i] % 2 + n / a[i] / 2) * solve(a[i], k - 1));
		}
	}
	return ma[n * 11 + k] = c;
}

int main(void) {
	ll n;
	int k;
	cin >> n >> k;
	for (ll i = 1; i * i <= n; ++i)
		if (n % i == 0) {
			a[as++] = i;
		}
	cout << solve(n, k) << "\n";
}