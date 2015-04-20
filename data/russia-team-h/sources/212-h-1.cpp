#include <iostream>
#include <cstdio>
#include <vector>


using namespace std;


const int INF = (int) 1e9 + 1;

vector < vector < pair < int, int > > > mat (5001);
vector < pair < int, int > > d (5001);
vector < int > prev (5001);
bool used[5001];
int n, m;


void dijkstra() {
    for (int i = 0; i < n; ++i) {
        int mn = INF + 1;
        int u = 0;
        for (int j = 0; j < n; ++j) {
            if (!used[j] && d[j].first < mn) {
                mn = d[j].first;
                u = j;
            }
        }
        used[u] = true;
        for (int j = 0; j < (int) mat[u].size(); ++j) {
            int v = mat[u][j].first;
            if (d[v].first > d[u].first + mat[u][j].second) {
                prev[v] = u;
                d[v].first = d[u].first + mat[u][j].second;
            }
        }
    }
}



int main() {
    freopen("secure.in", "r", stdin);
    freopen("secure.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        cin >> d[i].second;
        if (d[i].second == 1) {
            d[i].first = 0;
        }
        else {
            d[i].first = INF;
        }
    }
    int s, t, c;
    for (int i = 0; i < m; ++i) {
        cin >> s >> t >> c;
        mat[s - 1].push_back(make_pair(t - 1, c));
        mat[t - 1].push_back(make_pair(s - 1, c));
    }

    dijkstra();
    int mn = INF + 1;
    int u = 0;
    for (int i = 0; i < n; ++i) {
        if (d[i].second == 2 && d[i].first < mn) {
            mn = d[i].first;
            u = i;
        }
    }
    if (d[u].first == INF) {
        cout << -1;
        return 0;
    }
    int v = u;
    for(; d[u].second != 1; u = prev[u]);
    cout << u + 1 << " " << v + 1 << " " << d[v].first; 
    return 0;
}