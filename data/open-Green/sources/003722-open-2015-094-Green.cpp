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
#define ll long long
#define ld long double
#define cs(a) ((int)a.size())
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define BAD -1001230000
using namespace std;

unordered_map<ll, ll> ma;

ll solve(ll n, int k) {
	if (ma.count(n * 11 + k))
		return ma[n * 11 + k];
	if (k == 0) {
		return n;
	}
	ll c = n;
	for (ll i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			c = min(c, (i / 2 + i % 2) * solve(n / i, k - 1));
			c = min(c, (n / i % 2 + n / i / 2) * solve(i, k - 1));
		}
	}
	return ma[n * 11 + k] = c;
}

int main(void) {
	ll n;
	int k;
	cin >> n >> k;
	cout << solve(n, k) << "\n";
}