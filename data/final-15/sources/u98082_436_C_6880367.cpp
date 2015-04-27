#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <time.h>
#include <vector>

#if LOCAL
	#define DO_NOT_SEND
#endif

typedef long long LL;

int IntMaxVal = (int) 1e20;
int IntMinVal = (int) -1e20;
LL LongMaxVal = (LL) 1e20;
LL LongMinVal = (LL) -1e20;

#define FOR(i, a, b) for(int i = a; i < b ; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)

template<typename T> inline void minimize(T &a, T b) { a = std::min(a, b); }
template<typename T> inline void maximize(T &a, T b) { a = std::max(a, b); }

#define all(v) v.begin(),v.end()

using namespace std;

#define endl '\n'
template<typename T> struct argument_type;
template<typename T, typename U> struct argument_type<T(U)> { typedef U type; };
#define next(t, i) argument_type<void(t)>::type i; cin >> i;
#define nextVector(t, v, size) vector< argument_type<void(t)>::type > v(size); { for (int i = 0 ; i < size ; i++) cin >> v[i]; }

#define range(name, start, count) vector<int> name(count); { for (int i = 0 ; i < count ; i++) name[i] = i + start; }

template <typename T1, typename T2> istream& operator >>(istream& is, pair<T1, T2>& s) { is >> s.first >> s.second; return is; }
template <typename T> ostream& operator << (ostream& os, const vector<T> &v) { for (int i = 0 ; i < v.size() ; i++) os << v[i] << ' '; os << endl; return os; }
template <typename T1, typename T2> ostream& operator <<(ostream& s, pair<T1, T2>& t) { s << t.first << ' ' << t.second; return s; }
template <typename T> vector<T> readVector(int n) { vector<T> res(n); for (int i = 0 ; i < n ; i++) cin >> res[i]; return res; }

bool visited[1000];

void print(vector<pair<int, int>> &edges, int v, int from) {
	for (auto e : edges) {
		int a = e.first;
		int b = e.second;
		if (a != v) swap(a, b);
		if (a != v) continue;
		if (b != from) {
			cout << b + 1 << ' ' << a + 1 << endl;
			visited[b] = true;
			print(edges, b, a);
		}
	}
}

int main() {
	srand (time(NULL));
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	next(int, n);
	next(int, m);
	next(int, k);
	next(int, w);
	
	vector<vector<char>> levels(k);
	FOR (i, 0, k) {
		auto lvl = readVector<string>(n);
		levels[k].reserve(n * m);
		for (auto x : lvl) for (auto c : x) levels[i].push_back(c);
	}
	
	vector<pair<int, pair<int, int>>> edges;
	edges.reserve(k * k / 2);
	FOR (i, 0, k) FOR (j, i + 1, k) {
		int res = 0;
		FOR (x, 0, n * m) if (levels[i][x] != levels[j][x]) res++;
		edges.push_back(make_pair(res, make_pair(i, j)));
	}
	
	int fullRes = 0;
	sort(all(edges));
	
	vector<int> parent(k);
	vector<int> size(k, 1);
	FOR (i, 0, k) parent[i] = i;
	
	function<int(int)> update = [&] (int v) {
		if (parent[v] != v) parent[v] = update(parent[v]);
		return parent[v];
	};
	
	auto link = [&] (int a, int b) {
		a = update(a);
		b = update(b);
		if (a == b) return;
		if (size[a] < size[b]) swap(a, b);
		size[a] += size[b];
		parent[b] = a;
	};
	
	vector<pair<int, int>> e2;
	
	for (auto &edge : edges) {
		auto a = edge.second.first;
		auto b = edge.second.second;
		update(a);
		update(b);
		if (parent[a] == parent[b]) continue;
		if (edge.first * w > n * m) break;
		link(a, b);
		e2.push_back(make_pair(a, b));
		fullRes += edge.first * w;
	}
	
	FOR (i, 0, k) {
		update(i);
		if (parent[i] == i) fullRes += n * m;
	}
	cout << fullRes << endl;
	
	FOR (i, 0, k) if (!visited[i]) {
		visited[i] = true;
		cout << i + 1 << ' ' << 0 << endl;
		print(e2, i, -1);
	}
	
}