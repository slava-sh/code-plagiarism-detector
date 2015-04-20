#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
typedef long long ll;

using namespace std;

map<int, set<int> > mp;

int main(){
	freopen("numbers.in", "r", stdin);
	freopen("numbers.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int c, k;
		cin >> c >> k;
		for (int j = 0; j < k; j++) {
			int v;
			cin >> v;
			mp[c].insert(v);
		}
	}
	int m;
	cin >> m;
	string s;
	for (int i = 0; i < m; i++) {
		cin >> s;
		int kdstr = 0;
		bool fl = 0;
		for (int j = 0; j < 3; j++) {
			if (fl) {
				break;
			}
			kdstr *= 10;
			kdstr += s[j] - '0';
			if (mp.find(kdstr) != mp.end()) {
				int kdreg = 0;
				for (int q = j + 1; q < j + 3; q++) {
					kdreg *= 10;
					kdreg += s[q] - '0';
				}
				for (int q = j + 3; q <j + 6; q++) {
					if (fl) {
						break;
					}
					kdreg *= 10;
					kdreg += s[q] - '0';
					if (mp[kdstr].find(kdreg) != mp[kdstr].end()) {
						if (s[q + 1] == '0') {
							continue;
						}
						fl = 1;
						cout << "+" << kdstr << "(" << kdreg << ")";
						
						if (11 - q - 1 == 3) {
							cout << s[8] << s[9] << s[10];
						}
						if (11 - q - 1 == 4) {
							cout << s[7] << s[8] << "-" << s[9] << s[10];
						}
						if (11 - q  - 1 == 5) {
							cout << s[6] << s[7] << s[8] << "-" << s[9] << s[10];
						}
						if (11 - q  - 1 == 6) {
							cout << s[5] << s[6] << "-" << s[7] << s[8] << "-" << s[9] << s[10];
						}
						if (11 - q - 1 == 7) {
							cout << s[4] << s[5] << s[6] << "-" << s[7] << s[8] << "-" << s[9] << s[10];
						}
						cout << endl;
					}
				}
			}
		}
		if (!fl) {
			cout << "Incorrect" << endl;
		}
	}
	return 0;
}













/*
ll a[100010];
ll n, k;

bool f(long long m) {
	long long uk = 0;
	for (long long i = 0; i < n; i++) {
		if (a[i] - uk >= m) {
			uk = a[i];
			continue;
		}
		if (uk + m < k) {
			uk = uk + m;
		} else {
			return 0;
		}
	}
	return 1;
}

int main() {
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	ll l = 0, r = 1000000000;
	cin >> n >> k;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		r = min(r, a[i]);
	}
	r++;
	sort(a + 0, a + n);
	//reverse(a + 0, a + n);
	while (r - l > 1) {
		ll m = (l + r) / 2;
		if (f(m)) {
			l = m;
		} else {
			r = m;
		}
	}
	cout << l;
	return 0;
}
	
	
	
	
	
	
	
	
	/*
	freopen("input.txt", "r", stdin);
	//freopen("sochi.out", "w", stdout);
	ll n, d;
	cin >> n >> d;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	ll uk = n + 1;// укакзатель на первое >= 3d
	ll x = n + 1;// укакзатель на первое >= d, <= 3d
	bool b = 1, bb = 1;
	if (n == 1) {
		cout << a[1];
		return 0;
	}
	if (a[n] < d) {
		cout << a[n];
		return 0;
	}	
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		if (a[i] >= 3 * d) {
			uk = i;
			break;
		}
		if (a[i] >= d && b) {
			x = i;
			b = 0;
		}
	}	
	if (uk > n) {
		ll v = n - x + 1;
		if (v >= 2) {
			cout << max(a[n] - d + a[n - 1] - d, a[n]);
			return 0;
		}
		if (v == 1) {
			cout << a[n];
		return 0;
		}
	}
	if (x > n) {
		for (ll i = uk; i <= n; i++) 
			ans += a[i] - d - d;
		ans += d + d;
		cout << max(ans, a[n]);
		return 0;
	}
	for (ll i = uk; i <= n; i++) 
		ans += a[i] - d - d;
	if (uk - x >= 2) {
		ans += a[uk - 1] - d + a[uk - 2] - d;
		cout << max(ans, a[n]);
		return 0;
	}
	if (uk - x == 1) {
		ans += a[uk - 1] - d + d;
		cout << max(ans, a[n]);
		return 0;
	}
	//if (uk - x == 0) {
}
	
	
	/*if (x == 0) {
		ans += a[n] - d;
		ans += a[n - 1] - d;
		for (ll i = 1; i <= n -2; i++)
			ans += a[i] - d- d;
		cout << ans;
		return 0;
	}
	if (uk - x >= 2)
		p = a[uk - 1], k = a[uk - 2];
	if (uk - x == 1 || n - x == 0) {
		p = a[x];
		o = 2;
	}
	if (uk - x == 0)
		b = 0;
	if (b) {
		if (n - uk == 0) {
			cout << a[n];
			return 0;
		}
		ans += a[n] - d;
		ans += a[n - 1] - d;
		for (ll i = uk; i <= n - 2; i++)
			ans += a[i] - d - d;
		cout << ans; 
		return 0;
	}
	if (uk == 0) {
		if (o == 2) {
			cout << p;
			return 0;
		}
		cout << a[n] - d + a[n - 1] - d;
		return 0;
	}
	if (o == 2) {
		ans += p - d;
		ans += a[n] - d;
		for (ll i = uk; i <= n - 1; i++) 
			ans += a[i] - d - d;
		cout << ans;
		return 0;
	}
	ans += p - d + k - d;
	for (ll i = uk; i <= n; i++)
		ans += a[i] - d - d;
	cout << ans;
	return 0;
}*/