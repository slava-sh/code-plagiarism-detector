#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

#pragma comment(linker, "/STACK:16777216")

enum LockType {NO, IN_PATH, TOTAL};

struct Vertex {
	vector< int > neighs;
	int height;
	LockType locked;

	Vertex(): locked(NO) {}
};

Vertex *nodes;

int make_paths(int vertex, int target, int parent) {
	nodes[vertex].height = (parent == -1) ? 0 : (nodes[parent].height + 1);
	int res = -1;
	for (unsigned i = 0; i < nodes[vertex].neighs.size(); i++) {
		int neigh = nodes[vertex].neighs[i];
		if (neigh == parent)
			continue;
		int cur = make_paths(neigh, target, vertex);
		if (cur != -1) {
			nodes[vertex].locked = IN_PATH;
			res = cur + 1;
		}
	}
	if (vertex == target)
		return 0;
	return res;
}

int process_subtree(int vertex, int parent, int max_ignored) {
	int res = 0;
	for (unsigned i = 0; i < nodes[vertex].neighs.size(); i++) {
		int neigh = nodes[vertex].neighs[i];
		if (neigh == parent || nodes[neigh].locked > max_ignored)
			continue;
		int cur = process_subtree(neigh, vertex, max_ignored) + 1;
		if (cur > res)
			res = cur;
	}
	return res;
}

inline int lock_branches(int vertex) {
	int res = -1;
	for (unsigned i = 0; i < nodes[vertex].neighs.size(); i++) {
		int neigh = nodes[vertex].neighs[i];
		if (nodes[neigh].locked == IN_PATH) {
			res = neigh;
			continue;
		}
		nodes[neigh].locked = TOTAL;
	}
	return res;
}

#define FILENAME "dwarfs"
int main() {
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);

	int n;
	scanf("%d", &n);
	nodes = new Vertex [n];
	for (int i = 0; i < n - 1; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;
		u--;
		nodes[v].neighs.push_back(u);
		nodes[u].neighs.push_back(v);
	}
	int v0, u0;
	scanf("%d%d", &v0, &u0);
	v0--;
	u0--;
	
	int path_len = make_paths(v0, u0, -1) - 1;
	int best = 0;
	for (int t = 0; t <= path_len / 2; t++) {
		nodes[v0].locked = TOTAL;
		nodes[u0].locked = TOTAL;
		int subtree_v0 = process_subtree(v0, -1, NO);
		int subtree_u0 = process_subtree(u0, -1, NO);
		int x = lock_branches(v0);
		int y = lock_branches(u0);
		int subpath_v0 = process_subtree(v0, -1, IN_PATH);
		int subpath_u0 = process_subtree(u0, -1, IN_PATH);

		int cur_res = t + 1 + max(
			min(subtree_v0, subtree_u0),
			max(
				min(subpath_v0, subtree_u0),
				min(subpath_u0, subtree_v0)
			)
		);
		if (cur_res > best)
			best = cur_res;

		v0 = x;
		u0 = y;
	}
	printf("%d\n", best);
	return 0;
}