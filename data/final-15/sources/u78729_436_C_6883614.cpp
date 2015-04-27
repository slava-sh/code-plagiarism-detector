
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <map>
#include <cmath>
#include <assert.h>

#define rep(i,n) for(int i=0; i<(n); i++)
#define repf(i,a,b) for (int i=(a); i<=(b); i++)
#define repb(i,a,b) for(int i=(a); i>=(b); i--)

#define ABS(X) ( ((X)>0) ? (X) : -(X) )
#define pb push_back

typedef long long int LL;

using namespace std;

template <typename T>
ostream& operator<<(ostream &a, const vector<T> &v) {
    a << "(";
    if (v.size()>=1) a << v[0];
    for (int i=1; i<v.size(); i++) {
        a << ", " << v[i];
    }
    a << ")";
    return a;
}

void init() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
}

class DSet {
    int N;
    int *parent;
public:
    void clear() {
        rep(i,N) parent[i] = i;
    }

    DSet(int n) {
        N=n;
        parent=new int[N];
        clear();
    }

    ~DSet() {delete [] parent;}

    int find(int u) {
        if (parent[u]==u) return u;
        parent[u] = find(parent[u]);
        return parent[u];
    }

    int un(int u, int v) {
        if (find(u) != find(v)) parent[find(u)] = find(v);
    }
};

typedef vector<string> Board;
typedef pair<int,int> ip;
typedef pair<int,ip> Edge;

int n,m,k,w;

int cmpCost(const Board &a, const Board &b) {
    int ans=0;
    rep(i,n) rep(j,m)
        if (a[i][j] != b[i][j]) ans += w;
    return ans;
}

int solve(const vector<Board> &boards, vector<ip> &ans_edges) {
    int ans=0;
    vector<Edge> edges;
    DSet ds(k+1);
    int bcost = n*m;
    rep(i,k) {
        edges.pb( make_pair(bcost, make_pair(0,i+1)) );
        repf(j,i+1,k-1) {
            int ocost = cmpCost(boards[i],boards[j]);
            edges.pb( make_pair(ocost, make_pair(i+1,j+1)) );
        }
    }
    sort(edges.begin(),edges.end());
    rep(i,edges.size()) {
        ip edge = edges[i].second;
        if (ds.find(edge.first) != ds.find(edge.second)) {
            ans += edges[i].first;
            ds.un(edge.first, edge.second);
            ans_edges.pb(edge);
        }
    }
    return ans;
}

int main(int argc, char **argv) {
    init();
    while (cin >> n >> m >> k >> w) {
        vector<Board> boards;
        rep(i,k) {
            Board b;
            string l;
            rep(i,n) {
                cin >> l;
                b.pb(l);
            }
            boards.pb(b);
        }
        assert(boards.size() == k);
        vector<ip> edges;
        int ans = solve(boards,edges);
        cout << ans << endl;

        vector<bool> used(k+1,false);
        list<ip> ledges(edges.begin(),edges.end());
        used[0]=true;
        while (!ledges.empty()) {
            for (list<ip>::iterator it=ledges.begin(); it!=ledges.end(); ) {
                list<ip>::iterator it2 = it;
                ++it2;
                if (used[it->first]) {
                    cout << it->second << " " << it->first << endl;
                    used[it->second] = true;
                    ledges.erase(it);
                } else if (used[it->second]) {
                    cout << it->first << " " << it->second << endl;
                    used[it->first] = true;
                    ledges.erase(it);
                }
                it = it2;
            }
        }
    }
}

