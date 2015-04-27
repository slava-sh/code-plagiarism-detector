#include "assert.h"
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


class dsuClass {
	public:

	int n;
	vector<int> parent;
	vector<int> size;
	
	int sccCount;
	
	void init(int n) {
		this->n = n;
		parent.resize(n);
		size.resize(n);
		reset();
	}
	
	void reset() {
		sccCount = n;
		FOR (i, 0, n) parent[i] = i;
		FOR (i, 0, n) size[i] = 1;
	}
	
	int update(int a) {
		if (parent[a] == a) return a;
		return parent[a] = update(parent[a]);
	}
	
	void join(int a, int b) {
		a = update(a);
		b = update(b);
		if (size[b] > size[a]) swap(a, b);
		if (a == b) return;
		
		size[a] += size[b];

		parent[b] = a;
		sccCount--;
	}
	
	void updateAll() {
		FOR (i, 0, n) update(i);
	}
};

dsuClass dsu;

vector<bool> used;

const int MAXN = 2000;
int timer, tin[MAXN], fup[MAXN];
 
void dfs (int v, int p, vector<vector<int>> &vEdges) {
	used[v] = true;
	tin[v] = fup[v] = timer++;
	for (auto to : vEdges[v]) {
		if (to == p)  continue;
		if (used[to]) {
			fup[v] = min (fup[v], tin[to]);
			dsu.join(v,to);
		} else {
			dfs (to, v, vEdges);
			fup[v] = min (fup[v], fup[to]);
			if (fup[to] <= tin[v])
				dsu.join(v,to);
		}
	}
}
 
void find_bridges(vector<vector<int>> &vEdges) {
	timer = 0;
	for (int i=0; i<used.size(); ++i)
		if (!used[i])
			dfs (i, -1, vEdges);
}

int calc_tree_size(int v, int parent, vector<vector<int>> &edges, vector<int> &sizes, int &result_acc) {
	int result = 0;
	
	for (auto child : edges[v]) if (child != parent) {
		result += calc_tree_size(child, v, edges, sizes, result_acc);
	}
	
	result_acc += sizes[v] * result;
	
	result += sizes[v];
	
	return result;
}

int calc_tree_best_result(vector<int> sizes, vector<pair<int, int>> &edges_list) {
	int best = 0;
	int n = sizes.size();
	vector<vector<int>> edges(n);
	for (auto e : edges_list) {
		edges[e.first].push_back(e.second);
		edges[e.second].push_back(e.first);
	}
	
	const int MAXSUM = 2000;
	
	FOR (v, 0, n) {
		int cur = 0;
		vector<int> childrenSizes(edges[v].size());
		FOR (i, 0, childrenSizes.size()) 
			childrenSizes[i] = calc_tree_size(edges[v][i], v, edges, sizes, cur);
			
		vector<int> achievable_sum(MAXSUM + 1);
		achievable_sum[0] = true;
		for (auto cs : childrenSizes) {
			FORD (x, MAXSUM, cs) if (achievable_sum[x - cs]) achievable_sum[x] = true;
		}
		
		int full_sum = accumulate(all(childrenSizes), 0);
		FOR (x, 0, MAXSUM + 1) if (achievable_sum[x]) {
			int rem = full_sum - x;
			maximize(best, (x + sizes[v]) * rem + x * sizes[v] + cur);
		}
	}
	
	return best;
}

int main() {
	srand (time(NULL));
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	next(int, n);
	next(int, m);
	
	auto edges = readVector<pair<int, int>>(m);
	vector<vector<int>> vEdges(n);
	for (auto &e : edges) {
		e.first--;
		e.second--;
	}
	for (auto &e : edges) {
		vEdges[e.first].push_back(e.second);
		vEdges[e.second].push_back(e.first);
	}
	used.resize(n);
	dsu.init(n);
	find_bridges(vEdges);
	
	vector<int> newParents;
	FOR (i, 0, n) if (dsu.update(i) == i) newParents.push_back(i);
	
	map<int, int> parentsMapping;
	FOR (i, 0, newParents.size()) parentsMapping[newParents[i]] = i;
	vector<pair<int, int>> newEdges;
	
	int result = 0;
	for (auto parent : newParents) {
		result += dsu.size[parent] * dsu.size[parent];
	}
	
	for (auto e : edges) {
		if (dsu.update(e.first) != dsu.update(e.second)) 
			newEdges.push_back( make_pair(parentsMapping[dsu.update(e.first)] , parentsMapping[dsu.update(e.second)]) );
	}
	
	vector<int> sizes(newParents.size());
	FOR (i, 0, sizes.size()) sizes[i] = dsu.size[newParents[i]];
	
	result += calc_tree_best_result(sizes, newEdges);
	
	cout << result;
}