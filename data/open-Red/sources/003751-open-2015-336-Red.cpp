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

vector<pair<ll, ll> > P[dd];

set<pair<ll, ll> > F;

ll bfs(int a, int b){
	F.clear();
	deque<pair<ll, ll> > E;
	deque<ll> L;
	forn(i, P[a].size()){
		E.push_back(P[a][i]);
		F.insert(P[a][i]);
		L.push_back(1);
	}
	while(!L.empty()){
		ll u = E.front().first, t = E.front().second, l = L.front();
		E.pop_front();
		L.pop_front();
		if(u == b)
			return l;
		forn(j, P[u].size()){
			if(abs(t - P[u][j].second) <= d){
				if(F.find(P[u][j]) == F.end()){
					F.insert(P[u][j]);
					L.push_back(l + 1);
					E.push_back(P[u][j]);
				}
			}
		}
	}
	return -1;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> n >> m >> d;
	forn(i, m){
		ll a, b, t;
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