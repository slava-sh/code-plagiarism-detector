#include <fstream>
#include <iostream>

#include<vector>
#include<algorithm>

#include<set>
#include <ctime>

#define ld long double
#define ll long long
#define mk make_pair
#define pb push_back


using namespace std;

int dp[200000];

vector <vector <int> > G;

int A, B;

void dfs1(int v, int p)
{
    for (int i = 0; i < (int)G[v].size(); i++)
        if (G[v][i] != p)
        {
            if (v == A && G[v][i] == B)
                continue;
            if (v == B && G[v][i] == A)
                continue;
            dfs1(G[v][i], v);
            dp[v] = max(dp[G[v][i]] + 1, dp[v]);
        }
}

vector <int> P;
bool ok = 0;

void get_path(int a, int b, int p)
{
    if (a == b)
    {
        ok = 1;
        return;
    }
    for (int i = 0; i < (int)G[a].size(); i++)
        if (G[a][i] != p)
        {
            P.push_back(G[a][i]);
            get_path(G[a][i], b, a);
            if (ok)
                return;
            P.pop_back();
        }
}

int main()
{
    for (int i = 0; i < 200000; i++)
        dp[i] = 1;
    ifstream cin ("dwarfs.in");
    ofstream cout("secure.out");
    int n;
    cin >> n;
    G.resize(n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    A = a;
    B = b;
    P.pb(a);
    get_path(a, b, -1);
    if (P.size() != 2)
        dfs1(P[1], -1);
    else
    {
        dfs1(P[0], -1);
        dfs1(P[1], -1);
    }
    int ans = -1;
    for (int i = 0; i < (int)P.size() - 1; i++)
    {
        int u = P[i];
        int v = P[i + 1];
        int d1 = 0;
        for (int j = 0; j < (int)G[u].size(); j++)
        {
            if ((i != 0 && P[i - 1] != G[u][j]))
                d1 = max(d1, dp[G[u][j]]);
        }
        int t1 = max(dp[a], i + d1);
        int d2 = 0;
        for (int j = 0; j < (int)G[v].size(); j++)
        {
            if (P[i] != G[v][j])
                d2 = max(d2, dp[G[v][j]]);
        }
        int t2 = max(dp[b], (int)P.size() - i - 1 + d2);
        ans = max(ans, min(t1, t2));
    }
    cout << ans << endl;
    return 0;
}
