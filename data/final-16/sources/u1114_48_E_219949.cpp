#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <stack>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <memory>
using namespace std;
#define pb push_back
#define INF 1000000000
#define L(s) (int)((s).end()-(s).begin())
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define C(a) memset((a),0,sizeof(a))
#define llint long long
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define VI vector<int>
#define ppb pop_back
#define mp make_pair
#define pii pair<int,int>
#define pdd pair<double,double>
#define x first
#define y second
#define sqr(a) (a)*(a)
#define D(a,b) sqrt(((a).x-(b).x)*((a).x-(b).x)+((a).y-(b).y)*((a).y-(b).y))
#define pi 3.1415926535897932384626433832795028841971
//#define tt (ll+rr)/2
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define rnd() ((rand() << 16) ^ rand())

int n, m, R;
vector<pii> H;
vector<pii> T;

vector<pii> edges(pii a)
{
	int nx = min(a.x, n),
		mx = min(a.y, m);

	vector<pii> res;

	rept(i, nx)
		res.pb(mp(a.x - (i + 1) + H[i].x , a.y + H[i].y));

	rept(i, mx)
		res.pb(mp(a.x + T[i].x , a.y - (i + 1) + T[i].y));

	return res;
}

int used[400][400];
int df[400][400];

int tryWin(pii cur)
{
	rept(i, 400) rept(j, 400) df[i][j] = INF;
	queue<pii> Q;
	Q.push(cur);
	df[cur.x][cur.y] = 0;

	while (!Q.empty())
	{
		pii c = Q.front(); Q.pop();
		if (c.x == 0 && c.y == 0) return df[0][0];

		vector<pii> E = edges(c);

		rept(i, L(E))
			if (E[i].x + E[i].y <= R && df[E[i].x][E[i].y] == INF)
			{
				df[E[i].x][E[i].y] = df[c.x][c.y] + 1;
				Q.push(E[i]);
			}
	}

	return df[0][0];
}



bool tryDraw(pii cur)
{
	if (used[cur.x][cur.y] == 2) return false;
	if (used[cur.x][cur.y] == 1) return true;
	if (cur.x + cur.y > R) return false;

	used[cur.x][cur.y] = 1;

	vector<pii> E = edges(cur);

	rept(i, L(E))
		if (tryDraw(E[i]))
			return true;

	used[cur.x][cur.y] = 2;

	return false;
}

int tryLose(pii cur)
{
	if (used[cur.x][cur.y]) return df[cur.x][cur.y];
	if (cur.x + cur.y > R) return 0;

	vector<pii> E = edges(cur);
	
	int mx = 0;
	rept(i, L(E))
		mx = max(mx, tryLose(E[i]));
	mx++;

	used[cur.x][cur.y] = true;
	return df[cur.x][cur.y] = mx;
}

int main()
{
	#ifndef ONLINE_JUDGE 
	freopen("input.txt","rt",stdin); freopen("output.txt","wt",stdout); 
	#endif
	
	int h, t;
	scanf("%d%d%d", &h, &t, &R);

	scanf("%d", &n);
	H.resize(n);
	rept(i, n) scanf("%d%d", &H[i].x, &H[i].y);

	scanf("%d", &m);
	T.resize(m);
	rept(i, m) scanf("%d%d", &T[i].x, &T[i].y);

	C(used);
	int c = tryWin(mp(h, t));

	if (c < INF)
	{
		cout << "Ivan" << endl;
		cout << c << endl;
		return 0;
	}
	
	C(used);
	bool d = tryDraw(mp(h, t));

	if (d)
	{
		cout << "Draw" << endl;
		return 0;
	}

	C(used);
	int l = tryLose(mp(h, t));
	cout << "Zmey" << endl;
	cout << l << endl;

	return 0;
}






