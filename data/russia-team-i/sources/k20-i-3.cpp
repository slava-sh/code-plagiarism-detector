#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

const int MAXN = (int) 1e5 + 10;

#define fname "sochi"
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define forp(i, a, b) for(int i = a; i <= b; ++i)
#define form(i, a, b) for(int i = a; i >= b; --i)

	int n, d, a[MAXN], b[MAXN], ans, cnt;
	
int main() {
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);

	cin >> n >> d;

	if(n == 1){
		cin >> a[1];
		cout << a[1];
		return 0;
	}
	if(n == 2) {
		cin >> a[1] >> a[2];
		if(a[1] > d && a[2] > d) ans = max(a[1] + a[2] - 2 * d, ans);
		ans = max(ans, max(a[1], a[2]));
		cout << ans;
		return 0;
	}
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	sort(a + 1, a + 1 + n);

	for(int i = n; i >= 2; i--){
		int v = 0;
		if(a[i] > d) v += a[i] - d;
		if(a[i - 1] > d) v += a[i - 1] - d; 
		v += cnt;
		ans = max(v, ans);
		if(a[i] >= 3 * d) cnt += a[i] - (2 * d);
	}
	cout << max(ans, a[n]);


	return 0;
}