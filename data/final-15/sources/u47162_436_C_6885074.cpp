#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

struct SEdge
{
//    int w;
    int u;
    int v;
    int w;
//    int next;
};

struct SEdge2
{
    int v;
    int next;
};

int n, m, k;
char data[1000][10][10];

//int first[1000] = {};
SEdge edge[1000*1000];
int edgeCnt;
int first[1000];
SEdge2 edge2[1000*2];
int edgeCnt2;
bool vis[1000];

int father[1000] = {};

inline void add(const int &u, const int &v)
{
//    edge[edgeCnt].w = w;
    edge2[edgeCnt2].v = v;
    edge2[edgeCnt2].next = first[u];
    first[u] = edgeCnt2++;
}

inline int getFather(const int &x)
{
    return (father[x] == x) ? x : father[x] = getFather(father[x]);
}

inline void fatherUnion(const int &x, const int &y)
{
    father[getFather(x)] = getFather(y);
}

inline void addEdge(const int &u, const int &v, const int &w)
{
//    add(u, v, w);
//    add(v, u, w);
    edge[edgeCnt].u = u;
    edge[edgeCnt].v = v;
    edge[edgeCnt++].w = w;
}

inline int sortCmp(const SEdge &a, const SEdge &b)
{
    return a.w < b.w;
}

inline int cmp(char *a, char *b)
{
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
//            ans += (int)(a[i][j] != b[i][j]);
            ans += (int)(*(a++) != *(b++));
        }
        a += 10 - m;
        b += 10 - m;
    }
    return ans;
}

inline void dfs(const int &u, const int &fa)
{
    vis[u] = true;
    cout << u + 1 << ' ' << fa + 1 << endl;
    for (int i = first[u]; i != -1; i = edge2[i].next) {
        if (!vis[edge2[i].v]) {
            dfs(edge2[i].v, u);
        }
    }
}

int main(void)
{
    int w;
//    cin >> n >> m >> k >> w;
    scanf("%d %d %d %d", &n, &m, &k, &w);
    int limit = n * m / w;
    
    string s;
    getline(cin, s);
    
    for (int i = 0; i < k; ++i) {
        for (int ix = 0; ix < n; ++ix) {
            getline(cin, s);
            for (int iy = 0; iy < m; ++iy) {
                //                cin >>
                data[i][ix][iy] = s[iy];
            }
        }
    }
//    for (int i = 0; i < k; ++i) {
//        for (int ix = 0; ix < n; ++ix) {
//            for (int iy = 0; iy < m; ++iy) {
//                //                cin >>
//                cout << data[i][ix][iy];
//            }
//            cout << endl;
//        }
//    }
    
    edgeCnt = 0;
//    memset(first, 0xff, sizeof(first));
    
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            if (i != j) {
                int cnt = cmp(&data[i][0][0], &data[j][0][0]);
//                cout << i << ' ' << j << ' ' << cnt << endl;
                if (cnt <= limit) {
                    addEdge(i, j, cnt);
                }
            }
        }
    }
    
    sort(edge, edge + edgeCnt, sortCmp);
//    cout << k << endl;
    for (int i = 0; i < k; ++i) {
        father[i] = i;
    }
    memset(first, 0xff, sizeof(first));
    edgeCnt2 = 0;
//    cout << k << endl;
    int ans = 0;
    int ttt = k;
    for (int i = 0; i < edgeCnt; ++i) {
        if (getFather(edge[i].u) != getFather(edge[i].v)) {
            add(edge[i].u, edge[i].v);
            add(edge[i].v, edge[i].u);
//            cout << edge[i].u << ' ' << edge[i].v << endl;
            fatherUnion(edge[i].u, edge[i].v);
            ans += edge[i].w;
            --ttt;
        }
    }
    ans *= w;
    ans += n * m * ttt;
    cout << ans << endl;
    
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < k; ++i) {
        if (!vis[i]) {
            cout << i + 1 << ' ' << 0 << endl;
            vis[i] = true;
            for (int j = first[i]; j != -1; j = edge2[j].next) {
//                cout << edge2[j].v << ' ';
                dfs(edge2[j].v, i);
            }
//            cout << endl;
        }
    }
    
    return 0;
}