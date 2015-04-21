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

vector<int> a;
bool cmp(int a, int b) {
	if (a == 2) {
		return a != b;
	}
	if (b == 2) 
		return false;
	return a > b;
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