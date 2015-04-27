#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

typedef long long ll;

int L;
string s;
int best_n = 1e14;
unordered_set<string> best;

void pi(vector<ll>& p, const string& s) {
	p.resize(s.size());
	p[0] = 0;
	for (ll i = 1; i < s.size(); i++) {
		ll j = p[i - 1];
		while (j > 0 && s[i] != s[j]) {
			j = p[j - 1];
		}
		if (s[i] == s[j]) {
			j++;
		}
		p[i] = j;
	}
}

const ll INF = 1e14;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> L;
	cin >> s;
	ll ans = INF;
	for (ll i = 1; i <= L; i++) {
		vector<ll> p;
		unordered_set<string> hashmap;
		string h = s.substr(0, i);
		string k = h + "$" + s;
		pi(p, k);
		hashmap.insert(h);
		ll last = i;
		for (ll j = 2 * i + 1; j < p.size(); j++) {
			ll pos = j - i - 1;
			bool w = p[j] == i;
			bool q = pos - i - 1 >= last;
			if (p[j] == i && pos - i + 1 >= last) {
				if (pos - last > 0) {
					string w = s.substr(last, pos - last);
					hashmap.insert(w);
				}
				last = pos + i;
			}
		}
		bool flg = true;
	
		for (unordered_set<string>::iterator it = hashmap.begin(); it != hashmap.end(); it++) {
			if ((*it).size() > L) {
				flg = false;
			}
		}
		if (flg) {
			if (best_n > hashmap.size()) {
				best_n = hashmap.size();
				best = hashmap;
			}
		}
	}
	cout << best_n << endl;
	for (unordered_set<string>::iterator it = best.begin(); it != best.end(); it++) {
		cout << *(it) << endl;
	}
	return 0;
}