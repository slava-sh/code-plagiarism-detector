#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <random>
#include <map>
#include <algorithm>
#include <ctime>
#include <stack>
#include <queue>
#include <cmath>

#define ll long long
#define ull unsigned ll
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define pll pair <ll, ll>
#define S second
#define F first


const int INF = int(1e9) + 7;


using namespace std;


ll INFll;


struct P{
	ll x, y;
	P(): x(0), y(0){}
	P(ll x, ll y): x(x), y(y){}
	P operator +(const P a){
		return P(x + a.x, y + a.y);
	}
	ll operator *(const P a){
		return  x * a.x + y * a.y;
	}
	ll operator %(const P a){
		return x * a.y - y * a.x;
	}
	P operator -(const P a){
		return P(x - a.x, y - a.y);
	}
	double operator ^(const P a){
		return atan2((x * a.y - y * a.x) * 1., (x * a.x + y * a.y) * 1.);
	}
	bool operator ==(const P a){
		return (a.x == x && a.y == y);
	}
};


int a, b, n, c[100005], e[100005], u[100005], d[100005];
pii mx[100005];
vector <vector <P> > g;
vector < vector <int> > t;


bool cmp(pii a, pii b){
	P p1 = (g[a.S][1] - g[a.S][0]), p2 = (g[b.S][1] - g[b.S][0]);
	double l = (p1 ^(P(0, 1)) ), r = (p2 ^ (P(0, 1)) );
	return l > r;
}

int sign(ll x){
	if (x > 0) return 1;
	if (x == 0) return 0;
	return -1;
}

int main(){
	INFll = 1e18;
	INFll *= 2;
	srand(time(NULL));
//	ifstream cin ("test.in");
	cin >> a >> b >> n;
	int l;
	vector <int> tmp (3);
	g.resize(n);
	for (int i = 0; i < n; i++){
		cin >> l;
		for (int j = 0; j < l + 1; j++){
			int x, y; cin >> x >> y;
			if (!j) mx[i] = mp(y, i);
			g[i].pb(P(x, y));
			if (j < l){
				tmp[0] = x, tmp[1] = i, tmp[2] = j;
				t.pb(tmp);
			}
		}
	}
	sort(mx, mx + n);
	vector <pii> f;
	f.pb(mx[0]);
	for (int i = 1; i < n; i++){
		if (mx[i].F == mx[i - 1].F){
			f.pb(mx[i]);
		} else {
			sort(f.begin(), f.end(), &cmp);
			int pp = 0;
			for (int j = i - f.size(); j < i; j++){
				c[f[pp++].S] = j;
			}
			f.clear();
			f.pb(mx[i]);
		}
	}
	sort(f.begin(), f.end(), &cmp);
	int pp = 0;
	for (int j = n - f.size(); j < n; j++){
		c[f[pp++].S] = j;
	}
	for (int i = 0; i < n; i++){
		e[c[i]] = i;
	}
	for (int i =0 ;i < n; i++) {
		if (c[i] - 1 >= 0) d[i] = e[c[i] - 1];
		else d[i] = INF;
		if (c[i] + 1 < n) u[i] = e[c[i] + 1];
		else u[i] = INF;
	}

	vector <int> p;
	p.resize(n, 0);
	sort (t.begin(), t.end());
	tmp.resize(3);
	for (int q = 0; q < t.size(); q++){
		int x = t[q][0], i = t[q][1], j = t[q][2], y = g[i][j].y;
		if (u[i] < 1e7){
			if (g[u[i]][p[u[i]]].x != b){
				P p1 = g[u[i]][p[u[i]]];
				P p2 = g[u[i]][p[u[i]] + 1];
				P p3 = g[i][j];
				P p4 = g[i][j + 1];
				if (!((p4 - p3) % (p2 - p3))){
					if (p[u[i]] + 2 < g[u[i]].size()) p2 = g[u[i]][p[u[i]] + 2];
				}
				if (!((p4 - p1) % (p2 - p1))){
					if (p[i] + 2 < g[i].size()) p4 = g[i][p[i] + 2];
				}
				if (sign((p1 - p3) % (p4 - p3)) * sign((p4 - p3) % (p2 - p3)) == 1 && sign((p3 - p1) % (p2 - p1)) * sign((p2 - p1) % (p4 - p1)) == 1){
					cout << "No\n";
					cout << i + 1 << " " << u[i] + 1 << '\n';
					return 0;
				} 
			}

		}
		if (d[i] < 1e7){
			if (g[d[i]][p[d[i]]].x != b){
				P p1 = g[d[i]][p[d[i]]];
				P p2 = g[d[i]][p[d[i]] + 1];
				P p3 = g[i][j];
				P p4 = g[i][j + 1];
				if (sign((p1 - p3) % (p4 - p3)) * sign((p4 - p3) % (p2 - p3)) == 1 && sign((p3 - p1) % (p2 - p1)) * sign((p2 - p1) % (p4 - p1)) == 1){
					cout << "No\n";
					cout << i + 1 << " " << u[i] + 1 << '\n';
					return 0;
				} 
			}
		}
		p[i]++;
	}


	cout << "Yes\n";
}