#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll MOD = 1e9+9;
const ll PM  = 4;
const ll PM_INV = 750000007;

inline
ll mymod(ll a) {
	if (a < 0) {
		ll z = (-a+MOD-1)/(MOD);
		a += z*MOD;
	}
	return a%MOD;
}

struct hash_t {
	ll val, len;
};

struct hash_sum {
	vector<ll> p, pinv, v;
	hash_sum(const string &str) {
		p.resize(str.length()+1);
		pinv.resize(str.length()+1);
		v.resize(str.length()+1);
		p[0] = pinv[0] = 1;
		for (ll i = 1; i < p.size(); ++i) {
			p[i] = mymod(p[i-1]*PM);
		}
		for (ll i = 1; i < pinv.size(); ++i) {
			pinv[i] = mymod(pinv[i-1]*PM_INV);
		}
		v[0] = 0;
		for (ll i = 0; i < str.size(); ++i) {
			v[i+1] = mymod(v[i]+p[i]*(str[i]-'a'+1));
		}
	}
	ll hash(ll l, ll r) {
		return mymod((v[r+1]-v[l])*pinv[l]);
	}
};

string s;
ll l;
ll n;

vector<pll> ss;

ll hashof(const string &t) {
	hash_sum hs(t);
	return hs.hash(0, t.length()-1);
}

string palindromize(string t) {
	hash_sum hs(t);
	string res = t;
	for (ll j = 1; j*j<=t.length(); ++j) {
		if (t.length() % j == 0) {
			ll len = t.length()/j;
			if (len <= l) {
				bool ok = true;
				for (ll k = 0; len*k < t.length(); ++k) {
					if (hs.hash(k*len, k*len+len-1) != hs.hash(0, len-1)) {
						ok = false;
						break;
					}
				}

				if (ok && res.length() > len) {
					res = s.substr(0, len);
				}
			}
			len = j;
			if (len <= l) {
				bool ok = true;
				for (ll k = 0; len*k < t.length(); ++k) {
					if (hs.hash(k*len, k*len+len-1) != hs.hash(0, len-1)) {
						ok = false;
						break;
					}
				}

				if (ok && res.length() > len) {
					res = s.substr(0, len);
				}
			}
		}
	}
	return res;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> l;
	cin >> ws >> s;
	n = s.length();

	if (s.length()<=l) {
		cout << 1 << endl << s << endl;
		return 0;
	}

	set<char> z;
	for (ll i = 0; i < s.length(); ++i) {
		z.insert(s[i]);
	}
	if (z.size() == 1) {
		cout << z.size() << endl;
		for (auto it = z.begin(); it != z.end(); ++it) {
			cout << *it << endl;
		}
		return 0;
	}

	hash_sum hs(s);

	for (ll j = 1; j*j<=n; ++j) {
		if (n % j == 0) {
			ll len = n/j;
			if (len <= l) {
				bool ok = true;
				for (ll k = 0; len*k < n; ++k) {
					if (hs.hash(k*len, k*len+len-1) != hs.hash(0, len-1)) {
						ok = false;
						break;
					}
				}

				if (ok) {
					cout << 1 << endl;
					cout << s.substr(0, len) << endl;
					return 0;
				}
			}
		}
		if (n % j == 0) {
			ll len = j;
			if (len <= l) {
				bool ok = true;
				for (ll k = 0; k < n; ++k) {
					if (s[k%len] != s[k]) {
						ok = false;
						break;
					}
				}
				if (ok) {
					cout << 1 << endl;
					cout << s.substr(0, len) << endl;
					return 0;
				}
			}
		}
	}

	if (z.size() == 3) {
		set<string> sss;
		for (ll i = 0; i < n; ++i) {
			string cs;
			for (ll j = i; j < min<ll>(i+l, n); ++j) {
				cs.push_back(s[j]);
				string ncs = palindromize(cs);
				if (sss.find(ncs) == sss.end()) {
					sss.insert(ncs);
					ss.push_back(pll(i, i+ncs.size()-1));
				}
			}
		}
		for (ll ai = 0; ai < ss.size(); ++ai) {
			if (ss[ai].first == 0) {
				continue;
			}
			string as = s.substr(ss[ai].first, ss[ai].second-ss[ai].first+1);
			string bs = palindromize(s.substr(0, ss[ai].first));
			if (bs.length()>l) {
				continue;
			}
			ll b = hs.hash(0, bs.size()-1);
			ll a = hs.hash(ss[ai].first, ss[ai].second);
			ll al = ss[ai].second-ss[ai].first+1;
			ll bl = bs.size();

			
			vector<bool> can(n+1);
			can[0] = true;
			for (ll i = 1; i <= n; ++i) {
				if (i-al>=0&&can[i-al]&&hs.hash(i-al, i-1)==a) {
					can[i] = true;
				}
				if (i-bl>=0&&can[i-bl]&&hs.hash(i-bl, i-1)==b) {
					can[i] = true;
				}
			}
			if (can[n]) {
				cout << 2 << endl;
				cout << as << endl;
				cout << bs << endl;
				return 0;
			}
		}
		for (ll ai = 0; ai < ss.size(); ++ai) {
			for (ll bi = ai+1; bi < ss.size(); ++bi) {
				ll a = hs.hash(ss[ai].first, ss[ai].second);
				ll b = hs.hash(ss[bi].first, ss[bi].second);
				ll al = ss[ai].second-ss[ai].first+1;
				ll bl = ss[bi].second-ss[bi].first+1;
				vector<bool> can(n+1);
				can[0] = true;
				for (ll i = 1; i <= n; ++i) {
					if (i-al>=0&&can[i-al]&&hs.hash(i-al, i-1)==a) {
						can[i] = true;
					}
					if (i-bl>=0&&can[i-bl]&&hs.hash(i-bl, i-1)==b) {
						can[i] = true;
					}
				}
				if (can[n]) {
					cout << 2 << endl;
					cout << s.substr(ss[ai].first, al) << endl;
					cout << s.substr(ss[bi].first, bl) << endl;
					return 0;
				}
			}
		}
	}

	cout << z.size() << endl;
	for (auto it = z.begin(); it != z.end(); ++it) {
		cout << *it << endl;
	}
	return 0;
}