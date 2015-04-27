#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>

using namespace std;

#include <ext/hash_set>
#include <ext/hash_map>

using namespace __gnu_cxx;

#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz size()
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define rep2(i,n,m) for(int i=n;i<(int)(m);i++)
#define For(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define dot(a,b) ((conj(a)*(b)).X)
#define X real()
#define Y imag()
#define length(V) (hypot((V).X,(V).Y))
#define vect(a,b) ((b)-(a))
#define cross(a,b) ((conj(a)*(b)).imag())
#define normalize(v) ((v)/length(v))
#define rotate(p,about,theta) ((p-about)*exp(point(0,theta))+about)
#define pointEqu(a,b) (comp(a.X,b.X)==0 && comp(a.Y,b.Y)==0)

typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long long ll;
typedef long double ld;
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;

const int oo = (int) 1e9;
const double PI = 2 * acos(0);
const double eps = 1e-9;

const int MX = 409;

int n, m;
pii ns[MX], ms[MX];
int c;

pii dp[MX][MX];

pii NT(-2, -2), DR(-3, -3);

pii calc(int a, int b) {
	if (a + b > c)
		return mp(-1, 0);
	if (a + b == 0)
		return mp(1, 0);
	if (dp[a][b] == DR)
		return mp(0, 0);
	if (dp[a][b] != NT)
		return dp[a][b];
	dp[a][b] = DR;
	pii ret(-4, -4);
	rep(i,n) {
		if (i + 1 > a)
			continue;
		pii temp = calc(a - i - 1 + ns[i].first, b + ns[i].second);
		if (temp.first == 1)
			temp.second--;
		else if (temp.first == -1)
			temp.second++;
		ret = max(ret, temp);
	}
	rep(i,m) {
		if (i + 1 > b)
			continue;
		pii temp = calc(a + ms[i].first, b - i - 1 + ms[i].second);
		if (temp.first == 1)
			temp.second--;
		else if (temp.first == -1)
			temp.second++;
		ret = max(ret, temp);
	}
	return dp[a][b] = ret;
}

#define ind(x,y) ((x)*MX+(y))

vii g;

int aaa, bbb;
bool vis[MX * MX];
int best[MX * MX];

void bfs() {
	mem(vis,0);
	mem(best,-1);
	queue<int> q;
	int t = ind(aaa,bbb);
	vis[t] = 1;
	q.push(t);
	int ret = 0;
	while (!q.empty()) {
		int size = q.sz;
		while (size--) {
			t = q.front();
			q.pop();
			best[t] = ret;
			rep(i,g[t].sz)
				if (!vis[g[t][i]]) {
					vis[g[t][i]] = 1;
					q.push(g[t][i]);
				}
		}
		ret++;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.txt", "rt", stdin);
#endif
	while (cin >> aaa >> bbb >> c) {
		cin >> n;
		rep(i,n)
			cin >> ns[i].first >> ns[i].second;
		cin >> m;
		rep(i,m)
			cin >> ms[i].first >> ms[i].second;
		g.clear();
		g.resize(MX * MX);
		rep(a,MX) rep(b,MX) {
				if (a + b == 0 || a + b > c)
					continue;
				int x = ind(a,b);
				rep(i,n) {
					if (i + 1 > a)
						continue;
					int aa = a - i - 1 + ns[i].first;
					int bb = b + ns[i].second;
					int y = ind(aa,bb);
					if (y < MX * MX)
						g[x].pb(y);
				}
				rep(i,m) {
					if (i + 1 > b)
						continue;
					int aa = a + ms[i].first;
					int bb = b - i - 1 + ms[i].second;
					int y = ind(aa,bb);
					if (y < MX * MX)
						g[x].pb(y);
				}
			}
		bfs();
		if (best[0] != -1) {
			cout << "Ivan" << endl;
			cout << best[0] << endl;
			return 0;
		}
		rep(i,209) rep(j,209)
				dp[i][j] = NT;
		pii ret = calc(aaa, bbb);
		if (ret.first == 1) {
			cout << "Ivan" << endl;
			cout << -ret.second << endl;
		} else if (ret.first == -1) {
			cout << "Zmey" << endl;
			cout << ret.second << endl;
		} else
			cout << "Draw" << endl;
		break;
	}
	return 0;
}
