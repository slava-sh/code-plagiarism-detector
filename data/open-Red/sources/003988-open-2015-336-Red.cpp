#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;


typedef long long ll;
typedef unsigned long long ull;
#define forn(i, n) for(ll i = 0; i < n; i++)
#define fornn(i, be, n) for(ll i = be; i < n; i++)
#define mk make_pair
const int infi = 1e9 + 7;
const int dd = 50000 + 7;
int n, m, d, q;

vector<pair<int, int> > P[dd];

set<pair<int, int> > F;

ll bfs(int a, int b){
	F.clear();
	deque<pair<int, int> > E;
	deque<int> L;
	forn(i, P[a].size()){
		E.push_back(P[a][i]);
		F.insert(P[a][i]);
		L.push_back(1);
	}
	while(!L.empty()){
		int u = E.front().first, t = E.front().second, l = L.front();
		E.pop_front();
		L.pop_front();
		if(u == b)
			return l;
		int ma = -infi, ima, mi = infi, imi;
		forn(j, P[u].size()){
			int o = P[u][j].second;
			if(abs(t - P[u][j].second) <= d){
				if(P[u][j].first == b)
					return l + 1;
				if(ma < o)
					ma = o, ima = j;
				if(mi > o)
					mi = o, imi = j;
			}
		}
		if(F.find(P[u][ima]) == F.end()){
			F.insert(P[u][ima]);
			L.push_back(l + 1);
			E.push_back(P[u][ima]);
		}
		if(F.find(P[u][imi]) == F.end()){
			F.insert(P[u][imi]);
			L.push_back(l + 1);
			E.push_back(P[u][imi]);
		}
	}
	return -1;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> n >> m >> d;
	forn(i, m){
		int a, b, t;
		cin >> a >> b >> t;
		a--, b--;
		P[a].push_back(mk(b, t));
		P[b].push_back(mk(a, t));
	}
	cin >> q;
	forn(i, q){
		ll a, b;
		cin >> a >> b;
		a--, b--;
		cout << bfs(a, b) << '\n';
	}
}