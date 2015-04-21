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


int a, b, n;
vector <vector <P> > g;


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
			g[i].pb(P(x, y));
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			int p1 = 0, p2 = 0, u = 0, d = 0;
			while (p1 < g[i].size() && p2 < g[j].size()){
				if (g[i][p1].x == g[j][p2].x){
					if (g[i][p1].y > g[j][p2].y) u = 1;
					if (g[i][p1].y < g[j][p2].y) d = 1;
					p1++; p2++;
				} else if (g[i][p1].x > g[j][p2].x){
					double yy = g[i][p1 - 1].y + (g[j][p2].x - g[i][p1 - 1].x) * ((g[i][p1].y - g[i][p1 - 1].y) * 1. / (g[i][p1].x - g[i][p1 - 1].x));
					if (yy > g[j][p2].y) u = 1;
					if (yy < g[j][p2].y) d = 1;
					p2++;
				} else {
					double yy = g[j][p2 - 1].y + (g[i][p1].x - g[j][p2 - 1].x) * ((g[j][p2].y - g[j][p2 - 1].y) * 1. / (g[j][p2].x - g[j][p2 - 1].x));
					if (yy < g[i][p1].y) u = 1;
					if (yy > g[i][p1].y) d = 1;
					p1++;
				}
			}
			if (u + d == 2){
				cout << "No\n";
				cout << i + 1 << " " << j + 1 << '\n';
				return 0;
			}
		}
	}
	cout << "Yes\n";
}