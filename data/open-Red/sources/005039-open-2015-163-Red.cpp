#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <array>
#include <random>
#include <string>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;
const int INF = (int)2e9;
const ll LINF = (ll)8e18;
const ld EPS = 1e-9;

mt19937_64 mt;

int N, M, D, Q;

vector<bool> used;

struct tedge{
	int temp, to, num;
	tedge() {}
	tedge(int a, int b) : to(a), temp(b) {
		num = used.size();
		used.push_back(false);
	}
	bool operator <(const tedge &o) const {
		return temp < o.temp;
	}
};

vector<vector<tedge> > edges;

int bfs(int from, int to){
	fill(used.begin(), used.end(), false);
	int turn = 1;
	queue<pair<int, int> > q;
	for(auto x = edges[from].begin(); x != edges[from].end(); x++){
		used[x->num] = true;
		q.push(make_pair(x->to, x->temp));
	}
	q.push(make_pair(0, 0));
	while(1){
		if(q.front().first == 0){
			q.pop();
			turn++;
			if(q.empty()){
				return -1;
			}
			q.push(make_pair(0, 0));
		}
		if(q.front().first == to){
			return turn;
		}
		auto x = lower_bound(edges[q.front().first].begin(), edges[q.front().first].end(), tedge(0, q.front().second - D));
		auto y = upper_bound(edges[q.front().first].begin(), edges[q.front().first].end(), tedge(0, q.front().second + D));
		for(; x != y; x++){
			if(!used[x->num]){
				used[x->num] = true;
				q.push(make_pair(x->to, x->temp));
			}
		}
		q.pop();
	}
	return -1;
}

int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("xxx.in", "r", stdin);
	//freopen("xxx.out", "w", stdout);
#endif
	cin >> N >> M >> D;
	int u, v, t;
	edges.resize(N + 1);
	for(int i = 0; i < M; i++){
		scanf("%d%d%d", &u, &v, &t);
		edges[u].emplace_back(tedge(v, t));
		edges[v].emplace_back(tedge(u, t));
	}
	for(int i = 1; i <= N; i++){
		sort(edges[i].begin(), edges[i].end());
	}
	cin >> Q;
	for(int req = 0; req < Q; req++){
		scanf("%d%d", &u, &v);
		cout << bfs(u, v) << "\n";
	}
	return 0;
}