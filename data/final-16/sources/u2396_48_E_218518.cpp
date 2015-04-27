#include "cmath"
#include "cstdio"
#include "cstring"
#include "algorithm"
#include "map"
#include "numeric"
#include "queue"
#include "set"
#include "string"
#include "utility"
#include "vector"
using namespace std;
typedef long long i64;

struct edge_t {
  edge_t(int src_, int dest_)
    : src(src_), dest(dest_) {}
  int src, dest;
};
typedef vector<edge_t> node_t;
struct graph_t {
  static const int MAX_N = 50001;
  node_t v[MAX_N]; int n;
};
struct state_t {
  state_t(int node_, int cost_) : node(node_), cost(cost_) {}
  int node, cost;
};
struct dfs_t {
  dfs_t(int n) : parent(n, -1), preindex(n, -1), postindex(n, -1), lowindex(n, n) {}
  vector<int> parent, preorder, preindex, postorder, postindex, lowindex, articulations;
  vector<const edge_t*> bridges;
};
const int INFINITE = 0x3f3f3f3f;
int minCost[graph_t::MAX_N];
int memo[graph_t::MAX_N];
bool mark[graph_t::MAX_N];

int node(int h, int t, int R) {
  if (h + t > R) return 0;
  return h * (R + 1) + t + 1;
}
void AddToFringe(queue<state_t>& fringe, int node, int cost) {
  if (cost < minCost[node])
    fringe.push(state_t(node, minCost[node] = cost));
}
int Dijkstra(const graph_t& graph, int src, int dest) {
  memset(minCost, INFINITE, sizeof(minCost));
  queue<state_t> fringe;
  for (AddToFringe(fringe, src, 0); !fringe.empty();) {
    const state_t s = fringe.front(); fringe.pop();
    if (s.node == dest) return s.cost;
    for (int k = 0; k < (int)graph.v[s.node].size(); ++k) {
      const edge_t& e = graph.v[s.node][k];
      AddToFringe(fringe, e.dest, s.cost + 1);
    }
  }
  return -1;
}
bool DepthFirstSearch(const graph_t& graph, dfs_t& dfs, int parent, int node) {
  dfs.parent[node] = parent;
  dfs.preindex[node] = dfs.preindex[node] = (int)dfs.preorder.size();
  dfs.preorder.push_back(node);
  bool cycle = false;
  for (int k = 0, n = (int)graph.v[node].size(); k < n && !cycle; ++k) {
    const edge_t* const edge = &graph.v[node][k];
    if (dfs.parent[edge->dest] == -1) { /* on forward edge... */
      cycle = DepthFirstSearch(graph, dfs, node, edge->dest);
    } else {
      cycle = dfs.postindex[edge->dest] == -1;
    }
    dfs.lowindex[node] = min(dfs.lowindex[node], dfs.lowindex[edge->dest]);
  }
  dfs.postindex[node] = (int)dfs.postorder.size();
  dfs.postorder.push_back(node);
  return cycle;
}
bool DepthFirstSearch(const graph_t& graph, int src) {
  dfs_t dfs(graph.n);
  return DepthFirstSearch(graph, dfs, src, src);
}
int f(const graph_t& graph, int src, int dest) {
  if (src == dest) return 0;
  int& best = memo[src];
  if (mark[src]) return best;
  best = 0, mark[src] = true;
  for (int k = 0; k < (int)graph.v[src].size(); ++k)
    best = max(best, f(graph, graph.v[src][k].dest, dest) + 1);
  return best;
}
int main() {
  int h, t, R; scanf("%d %d %d", &h, &t, &R);
  static graph_t graph; graph.n = graph_t::MAX_N;
  for (int i = 0; i < graph.n; ++i) graph.v[i].clear();
  int n; scanf("%d", &n);
  vector<int> head_hi(n), head_ti(n);
  for (int k = 0; k < n; ++k) scanf("%d %d", &head_hi[k], &head_ti[k]);
  int m; scanf("%d", &m);
  vector<int> tail_hi(m), tail_ti(m);
  for (int k = 0; k < m; ++k) scanf("%d %d", &tail_hi[k], &tail_ti[k]);
  for (int ch = 0; ch <= R; ++ch)
    for (int ct = 0; ct <= R - ch; ++ct) {
      if (ch + ct == 0 || ch + ct > R) continue;
      const int src = node(ch, ct, R);
      for (int i = 1; i <= n && i <= ch; ++i) {
        const int nch = ch - i + head_hi[i - 1];
        const int nct = ct + head_ti[i - 1];
        const int dest = node(nch, nct, R);
        graph.v[src].push_back(edge_t(src, dest));
      }
      for (int i = 1; i <= m && i <= ct; ++i) {
        const int nch = ch + tail_hi[i - 1];
        const int nct = ct - i + tail_ti[i - 1];
        const int dest = node(nch, nct, R);
        graph.v[src].push_back(edge_t(src, dest));
      }
    }
  const int root = node(h, t, R);
  const int minWin = Dijkstra(graph, root, 1);
  if (minWin != -1) printf("%s\n%d\n", "Ivan", minWin);
  else if (DepthFirstSearch(graph, root)) printf("%s\n", "Draw");
  else {
    memset(mark, false, sizeof(mark));
    printf("%s\n%d\n", "Zmey", f(graph, root, 0));
  }
  return 0;
}
