//Bakuri Tsutskhashvili

#define _CRT_SECURE_NO_DEPRECATE

# include <cmath>
# include <cstdio>
# include <vector>
# include <bitset>
# include <iostream>
# include <algorithm>
# include <string>
# include <set>
# include <map>

# define ll long long
# define INF 100000000
# define fesvi(popo) sqrt(double(popo))
# define Pi acos(-1.0)
# define MAX(a,b) (a>b?a:b)
# define MIN(a,b) (a<b?a:b)
# define md 1000000007

using namespace std;
struct name{
	ll rao, ind;
};
bool func(name a, name b){
	return a.rao<b.rao;
}
ll n, p;
vector <name> a(300001);
ll ind[300001];
map<ll,ll> mp[300001];
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);   freopen("output.txt", "w", stdout);
#endif
	cin >> n >> p;
	for (int i = 1; i <= n; i++){
		a[i].ind = i;
		ll x, y;
		cin >> x >> y;
		a[x].rao++;
		a[y].rao++;
		mp[x][y]++;
		mp[y][x]++;
	};
	ll ans = 0;
	sort(a.begin() + 1, a.begin() + n + 1, func);
	for (int i = 1; i <= n; i++)
		ind[a[i].ind] = i;
	for (int i = 1; i <= n; i++){
		ll fnd = p - a[i].rao;
		ll kc = a[i].ind;
		ll l = 1;
		ll r = n;
		while (l < r){
			ll mid = (l + r) / 2;
			if (a[mid].rao < fnd)
				l = mid + 1;
			else
				r = mid;
		}
		if (a[r].rao + a[i].rao < p)
			continue;
		ans += n - r + 1;
		map<ll, ll> ::iterator it;
		for (it = mp[kc].begin(); it != mp[kc].end(); it++){
			ll nom = ind[it->first];
			ans -= (nom >= r && a[nom].rao + a[i].rao - it->second < p);
		}
		ans -= (ind[a[i].ind] >= r);
	}
	cout << ans / 2;
};