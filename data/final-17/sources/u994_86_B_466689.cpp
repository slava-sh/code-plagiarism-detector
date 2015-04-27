#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define IT(c)           __typeof((c).begin())
#define FORIT(i, c)     for(IT(c) i = (c).begin(); i != (c).end(); ++i)
#define FOR(i, a, b)    for(int i = a; i < int(b); ++i)
#define FORE(i, a, b)   for(int i = a; i <= int(b); ++i)
#define FORD(i, a, b)   for(int i = b - 1; i >= int(a); --i)
#define FORDE(i, a, b)  for(int i = b; i >= int(a); --i)
#define REP(i, n)       FOR(i, 0, n)
#define REPE(i, n)      FORE(i, 0, n)
#define REPD(i, n)      FORD(i, 0, n)
#define REPDE(i, n)     FORDE(i, 0, n)
#define SZ(c)           (int((c).size()))

typedef long long LL;

const int DR[4] = { -1,  0,  0, +1 };
const int DC[4] = {  0, -1, +1,  0 };

/* UNION-FIND DATASTRUCTURE

   Keeps track of a partition of elements (identified by integers in the range
   0 to count) into disjoint sets.

   Union and find operations run in 'almost' constant amortized time. */
class UnionFind
{
    vector<pair<int, int> > pr;
    /* first:  parent node */
    /* second: rank (number of nodes in subtree */

public:
    /* Constructs a union-find datastructure, consisting of 'nodes' distinct
       sets of one node each. */
    UnionFind(int nodes) {
        pr.reserve(nodes);
        REP(n, nodes) pr.push_back(make_pair(n, 1));
    }

    /* Combines the distinct sets to which u and v belong and returns true,
       or returns false if u and v were already in the same set. */
    bool combine(int u, int v) {
        if((u = find(u)) != (v = find(v)))
        {
            if(pr[u].second < pr[v].second) swap(u, v);
            pr[u].second += pr[v].second; /* update rank of set of u */
            pr[v].first  = u;         /* add v to set of u */
            return true;
        }
        return false;
    }

    /* Returns a set identifier for v, so that find(u) == find(v) if
       u and v are in the same set. */
    int find(int v) {
        if (pr[v].first == v) return v;
        return pr[v].first = find(pr[v].first);
    }

    /* Returns the size of the set containing v. */
    int size(int v) { return pr[find(v)].second; }

    /* Returns the number of disjount sets (by counting, so it's slow). */
    int count()
    {
        int res = 0;
        for (int i = 0; i < (int)pr.size(); ++i)
        {
            if (pr[i].first == i) ++res;
        }
        return res;
    }
};

static int H, W;

vector<vector<char> > visited;

int find_adjacent(const vector<vector<int> > &input,
                  const vector<vector<int> > &output,
                  int r, int c)
{
    visited[r][c] = true;
    int res = 0;
    REP(d, 4) {
        int nr = r + DR[d], nc = c + DC[d];
        if (input[nr][nc] == input[r][c] && !visited[nr][nc]) {
            res |= find_adjacent(input, output, nr, nc);
        }
        if (output[nr][nc] >= 0) res |= (1<<output[nr][nc]);
    }
    visited[r][c] = false;
    return res;
}

void place_recursive(const vector<vector<int> > &input, vector<vector<int> > &output, int r, int c, int digit)
{
    output[r][c] = digit;
    REP(d, 4) {
        int nr = r + DR[d], nc = c + DC[d];
        if (input[nr][nc] == input[r][c] && output[nr][nc] < 0) place_recursive(input, output, nr, nc, digit);
    }
}

void place(const vector<vector<int> > &input, vector<vector<int> > &output, int r, int c)
{
    int adj = find_adjacent(input, output, r, c);
    int digit = 0;
    while (adj & (1<<digit)) ++digit;
    assert(digit < 10);
    place_recursive(input, output, r, c, digit);
}

int main()
{
    cin >> H >> W;
    vector<vector<int> > grid(H + 2, vector<int>(W + 2, -1));
    int grp = 0;
    REP(i, H) {
        string line;
        cin >> line;
        REP(j, W) grid[i+1][j+1] = line[j] == '.' ? grp++ : -1;
    }
    UnionFind uf(grp);
    FORE(r, 1, H) FORE(c, 1, W) if (grid[r][c] >= 0 && uf.size(grid[r][c]) == 1) {
        int best_g = -1, best_s = 5;
        REP(d, 4) {
            int nr = r + DR[d], nc = c + DC[d];
            if (grid[nr][nc] >= 0) {
                int g = grid[nr][nc];
                int s = uf.size(g);
                if (s > 0 && s < best_s) {
                    best_g = g;
                    best_s = s;
                }
            }
        }
        if (best_g < 0) {
            std::cout << -1 << endl;
            return 0;
        }
        uf.combine(grid[r][c], best_g);
    }

    vector<vector<char> > (H + 2, vector<char>(W + 2, 0)).swap(visited);
    vector<vector<int> > output(H + 2, vector<int>(W + 2, -1));
    FORE(r, 1, H) FORE(c, 1, W) if (grid[r][c] >= 0) grid[r][c] = uf.find(grid[r][c]);
    FORE(r, 1, H) FORE(c, 1, W) if (grid[r][c] >= 0 && output[r][c] < 0) place(grid, output, r, c);

    FORE(r, 1, H) {
        FORE(c, 1, W) cout << (output[r][c] < 0 ? '#' : char('0' + output[r][c]));
        cout << '\n';
    }
}
