#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define sz(v) int(v.size())
#define endl '\n'
typedef long long ll;
typedef pair<int,int> pii;

const int MAXn = 3e5+10;
int degs[MAXn];
vector<int> nb[MAXn];

int main() {
	ios::sync_with_stdio(false);
	int n, p;
	cin >> n >> p;
	for(int i = 0; i < n; i++) {
		int c1, c2;
		cin >> c1 >> c2;
		c1--; c2--;
		nb[c1].push_back(c2);
		nb[c2].push_back(c1);
	}
	for(int i = 0; i < n; i++)
		degs[i] = nb[i].size();
	sort(degs, degs+n);
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		ans += degs+n-lower_bound(degs, degs+n, p-(int)nb[i].size());
		if(nb[i].size() * 2 >= p)
			ans--;
		sort(nb[i].begin(), nb[i].end());
		int l = 0, r = 0;
		while(l < (int)nb[i].size()) {
			while(r < (int)nb[i].size() && nb[i][r] == nb[i][l])
				r++;
			if((int)nb[i].size() + nb[nb[i][l]].size() >= p && nb[i].size() + (int)nb[nb[i][l]].size() - (r-l) < p) {
				ans--;
			}
			l = r;
		}
	}
	cout << ans/2 << endl;
	return 0;
}
