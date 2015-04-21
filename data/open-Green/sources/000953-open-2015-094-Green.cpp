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

vector<ll> a;
bool cmp(ll a, ll b) {
	return a * (b / 2 + b % 2) > b * (a / 2 + a % 2); 
}

int main(void) {
	ll n;
	int k;
	cin >> n >> k;
	for (int i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			a.pb(i);
			n /= i;
		}
	}
	
	if (n != 1) {
		a.pb(n);
	}
	ll ans = 1;
	for (int i = cs(a) - 1; i >= k; --i)
		ans *= a[i];
	for (int i = min(cs(a) - 1, k - 1); i >= 0; --i) {
		ans *= (a[i] / 2 + a[i] % 2);
	}
	cout << ans << endl;
}