#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const long long int Max_n = 6000;
const long long int inf = 10000000000000000;
long long int G[Max_n][Max_n];
long long int A[Max_n];
long long int dist[Max_n];
bool used[Max_n];
long long int prev[Max_n];
vector<long long int> answ;

int main()
{
    freopen("secure.in", "r", stdin);
    freopen("secure.out", "w", stdout);
    long long int n, m;
    long long int i, j;
    long long int st, en;
    cin >> n >> m;
    for (i = 0; i < n; ++i)
    {
        cin >> A[i];
        if (A[i] == 1)
        {
            st = i;
        }
        if (A[i] == 2)
        {
            en = i;
        }
    }
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            if (A[i] == A[j] and (A[i] == 1 or (A[i] == 2)))
            {
                G[i][j] = 0;
            }
            else
            {
                G[i][j] = inf;
            }
        }
    }
    long long int s, e, w;
    for (i = 0; i < m; ++i)
    {
        cin >> s >> e >> w;
        G[s - 1][e - 1] = min(G[s - 1][e - 1], w);
        G[e - 1][s - 1] = G[s - 1][e - 1];
    }

    for (i = 0; i < Max_n; ++i)
    {
        dist[i] = inf;
    }

    dist[st] = 0;
    for (i = 0; i < n; ++i)
    {
        long long int mn = 2 * inf;
        long long int ind_mn = -1;
        for (j = 0; j < n; ++j)
        {
            if (not used[j] and dist[j] < mn)
            {
                mn = dist[j];
                ind_mn = j;
            }
        }
        long long int v = ind_mn;
        used[v] = true;
        for (long long int u = 0; u < n; ++u)
        {
            long long int w = G[v][u];
            if (dist[u] > dist[v] + w)
            {
                dist[u] = dist[v] + w;
                prev[u] = v;
            }
        }
    }
    long long int toansw = dist[en];
    if (toansw >= inf / 2)
    {
        cout << -1;
        return 0;
    }
    long long int x, y;
    //cout << st + 1 << ' ' << en + 1 << '\n';
    //cout << dist[en] << '\n';
    while (en != st)
    {
        answ.push_back(en);
        en = prev[en];
    }
    answ.push_back(st);
    bool started = false;
    for (i = 0; i < answ.size(); ++i)
    {
        if (not started)
        {
            if (A[answ[i]] == 1 or A[answ[i]] == 0)
            {
                y = answ[i - 1] + 1;
                started = true;
            }
        }
        if (started)
        {
            if (A[answ[i]] == 1)
            {
                x = answ[i] + 1;
                break;
            }
        }
    }
    cout << x << ' ' << y << ' ' << toansw;
    return 0;
}
