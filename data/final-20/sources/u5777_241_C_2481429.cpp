
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)

pair<pii, int> mirror[2][111];
int N1, N2, hl, hr, N;

ll gcd(ll a, ll b){
	if(b == 0)return a;
	return gcd(b, a % b);
}
int calc(){
	int res = 0;
	ll L = 100000;
	ll dy = hr - hl;
	FOR(ii,0, N + 1){
		if(ii&1){
			dy -= (100 - hr) * 2;
		} else {
			dy -= 2 * hr;
		}
		ll ay = -dy;
		ll x = hl * L;
		ll dx = 100*L;
		int ib = 0, it = 0;
		int boni = 0;
		while(true){
			if(x >= L * ay){
				res = max(res, boni);
				break;
			}
			while(ib < N2 && mirror[1][ib].first.second *ay < x){
				ib++;
			}
			if(ib == N2)break;
			if(mirror[1][ib].first.first * ay > x)break;
			boni += mirror[1][ib++].second;
			x += dx;
			if(x >= L * ay){
				res = max(res, boni);
				break;
			}
			while(it < N1&& mirror[0][it].first.second *ay < x){
				it++;
			}
			if(it == N1)break;
			if(mirror[0][it].first.first * ay > x)break;
			boni += mirror[0][it++].second;
			x += dx;
		}
	}
	return res;
}
int main() {
	N1 = 0;
	N2 = 0;
	cin >> hl >> hr >> N;
	FOR(i,0,N){
		int v, a, b;
		string tmp;
		cin >> v >> tmp >> a>> b;
		if(tmp == "T"){
			mirror[0][N1++] = mp(mp(a,b),v);
		} else if(tmp == "F"){
			mirror[1][N2++] = mp(mp(a,b),v);
		} else {
			cout << "FAIL\n";
		}
	}
	sort(mirror[0], mirror[0] + N1);
	sort(mirror[1], mirror[1] + N2);
	int res = calc();
	FOR(i,0,N)swap(mirror[0][i], mirror[1][i]);
	hl = 100 - hl;
	hr = 100 - hr;
	swap(N1, N2);
	res = max(calc(), res);
	cout << res << endl;
	return 0;
}
