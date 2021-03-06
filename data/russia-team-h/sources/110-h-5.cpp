#include <fstream>
#include <iostream>

#include<vector>
#include<algorithm>

#include<set>
#include <ctime>

#define ll long long

using namespace std;

bool TL()
{
    return ((double)clock() / CLOCKS_PER_SEC > 1.8);
}

int main()
{
    srand(179);
    ifstream cin ("secure.in");
    ofstream cout("secure.out");
    int n, m;
    cin >> n >> m;
    int t[n], c1 = 0, c2 = 0;
    for(int i = 0; i < n; ++i)
    {
        cin >> t[i];
        if(t[i] == 1)
            ++c1;
        else if(t[i] == 2)
            ++c2;
    }
    int st_type;
    if(c1 < c2)
        st_type = 1;
    else
        st_type = 2;

    vector<vector<pair<int, int> > > G(n);
    for(int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        G[u - 1].push_back(make_pair(v - 1, w));
        G[v - 1].push_back(make_pair(u - 1, w));
    }

    ll answer = 1000ll * 1000 * 1000 * 1000 * 1000;
    int start, finish;

    vector <int> QQ;
    for (int i = 0; i < n; i++)
        QQ.push_back(i);
    random_shuffle(QQ.begin(), QQ.end());
    for(int q = 0; q < n; ++q)
    {
        int i = QQ[q];
        if(t[i] != st_type)
            continue;
        if (TL())
            break;
        vector<ll> D(n, 1000ll * 1000 * 1000 * 1000 * 1000);
        D[i] = 0ll;
        set<pair<ll, int> > S;
        S.insert(make_pair(0ll, i));

        while(!S.empty())
        {
            int u = S.begin()->second;
            S.erase(S.begin());
            if(t[u] == 3 - st_type)
            {
                if(answer > D[u])
                {
                    answer = D[u];
                    start = i;
                    finish = u;
                }
                break;
            }
            for(int j = 0; j < G[u].size(); ++j)
            {
                int v = G[u][j].first, cost = G[u][j].second;
                if(D[u] + cost < D[v] && t[v] != st_type)
                {
                    S.erase(make_pair(D[v], v));
                    D[v] = D[u] + cost;
                    S.insert(make_pair(D[v], v));
                }
            }
        }
    }
    if (answer == 1000ll * 1000 * 1000 * 1000 * 1000)
    {
        cout << -1 << endl;
        return 0;
    }
    if(t[start] == 2)
        swap(start, finish);
    cout << start + 1 << " " << finish + 1 << " " << answer << endl;
    return 0;
}
