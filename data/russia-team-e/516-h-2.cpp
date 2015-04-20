#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef double de;
typedef pair<de, de> pde;
typedef vector<ll> vecl;
typedef vector<pll> vecpl;
typedef string str;
typedef vector<bool> veb;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define si size

const ll INF = 1e18 + 1, maxn = 1e5 + 1;
const de eps = 1e-9;

ll n, i, j, k, m, answer, a[5005], dist[5005], p[5005], ax, bx;
vecpl g[5005];
bool used[5005];

struct tr{
	ll x, y, c;
};

tr mtr(ll x0, ll y0, ll z0){
	tr ans;
	ans.x = x0;
	ans.y = y0;
	ans.c = z0;
	return ans;
}

vector<tr> gk[5005];

ll minimum(){
	ll ans = n, i1, mi = INF;
	for(i1 = 0; i1 < n + 3; ++i1){
		if(dist[i1] < mi && !used[i1]){
			mi = dist[i1];
			ans = i1;
		}
	}
	return ans;
}

void dx(ll st){
	ll i1, id, jd, t;
	dist[st] = 0;
	for(i1 = 0; i1 < n; ++i1){
		t = minimum();
		if(t == n){
			break;
		}
		used[t] = 1;
		for(id = 0; id < gk[t].si(); ++id){
			ll to, nm;
			to = gk[t][id].x;
			nm = gk[t][id].c;
			if(!used[to] && dist[to] > nm + dist[t]){
				dist[to] = nm + dist[t];
				p[to] = t;
			}
		}
	}
}

int main(){

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#else
	freopen("secure.in", "r", stdin);
	freopen("secure.out", "w", stdout);
#endif

	cin >> n >> m;
	for(i = 0; i < n; ++i){
		cin >> a[i];
		if(a[i] == 0){
			gk[i + 3].pb(mtr(1,-1,INF));
			gk[i + 3].pb(mtr(2,-1,INF));
		}
		if(a[i] == 1 && gk[1].si() == 0){
			gk[1].pb(mtr(2,-1,INF));
		}
		if(a[i] == 2 && gk[2].si() == 0){
			gk[2].pb(mtr(1,-1,INF));
		}
		dist[i] = INF;
		dist[i + 3] = INF;
	}
	for(i = 0; i < m; ++i){
		ll a1, b1, c1;
		cin >> a1 >> b1 >> c1;
		a1--;
		b1--;
		g[a1].pb(mp(b1, c1));
		g[b1].pb(mp(a1, c1));
	}
	for(i = 0; i < n; ++i){
		if(a[i] == 0){
			continue;
		}
		if(a[i] == 1){
			for(j = 0; j < g[i].si(); ++j){
				ll to, nm;
				to = g[i][j].x;
				nm = g[i][j].y;
				if(a[to] == 2){
					if(nm < gk[1][0].c){
						gk[1][0] = mtr(2, to, nm);
					}
				}
			}
		}
		else{
			for(j = 0; j < g[i].si(); ++j){
				ll to, nm;
				to = g[i][j].x;
				nm = g[i][j].y;
				if(a[to] == 1){
					if(nm < gk[2][0].c){
						gk[2][0] = mtr(1, to, nm);
					}
				}
			}
		}
	}
	for(i = 0; i < n; ++i){
		if(a[i] == 1 || a[i] == 2){
			continue;
		}
		for(j = 0; j < g[i].si(); ++j){
			ll to, nm;
			to = g[i][j].x;
			nm = g[i][j].y;
			if(a[to] == 1){
				if(gk[i + 3][0].c > nm){
					gk[i + 3][0] = mtr(1, to, nm);
				}
				continue;
			}
			if(a[to] == 2){
				if(gk[i + 3][1].c > nm){
					gk[i + 3][1] = mtr(2, to, nm);
				}
				continue;
			}
			gk[i + 3].pb(mtr(to + 3, to, nm));
		}
		if(gk[i + 3][0].y != -1){
			gk[1].pb(mtr(i + 3, i, gk[i + 3][0].c));
		}
		if(gk[i + 3][1].y != -1){
			gk[2].pb(mtr(i + 3, i, gk[i + 3][1].c));
		}
	}
	dx(1);
	answer = dist[2];
	if(!used[2]){
		cout << -1;
		return 0;
	}
	i = 2;
	j = p[2];
	if(j != 1){
		bx = gk[j][1].y;
	}
	else{
		bx = gk[j][0].y;
	}
	while(p[i] != 1){
		i = p[i];
	}
	ax = gk[i][0].y;
	cout << ax + 1 << " " << bx + 1 << " " << answer;
}