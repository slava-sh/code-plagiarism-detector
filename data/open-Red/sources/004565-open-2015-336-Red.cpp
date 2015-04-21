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

vector<set<pair<int, int> >  > E(dd), W(dd);

set<pair<int, int> > F;

ll bfs(int a, int b){
	F.clear();
	deque<pair<ll, ll> > E;
	deque<ll> L;
	W[a].clear();
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
		auto r = W[u].upper_bound(mk(t + d + 1, -1));
		auto le = W[u].lower_bound(mk(t - d, -1));
		for(auto it = le; it != r; ++it){
			pair<int, int> te = *it;
			swap(te.first, te.second);
			if(F.find(te) == F.end()){
				F.insert(te);
				L.push_back(l + 1);
				E.push_back(te);
			}
		}
		W[u].erase(le, r);
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
		E[a].insert(mk(t, b));
		E[b].insert(mk(t, a));
	}
	cin >> q;
	forn(i, q){
		ll a, b;
		cin >> a >> b;
		a--, b--;
		forn(i, n)
			W[i] = E[i];
		cout << bfs(a, b) << '\n';
	}
}