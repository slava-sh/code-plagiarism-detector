#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

const int N = 5010;
const int inf = (int)1e9;

bool used[N];
vector<pair<int, int> > v[N];
int cur[N];
int prev[N];

#define pb push_back
#define mp make_pair

int main()
{
    freopen("secure.in", "rt", stdin);
    freopen("secure.out", "w", stdout);

    int n, m;

    cin >> n >> m;


    int a;
    int i, j;

    for (i = 1; i <= n; i++)
    {
        cin >> a;

        if(a == 1)
        {
            v[i].pb(mp(n + 1, 0));
            v[n + 1].pb(mp(i, 0));
        }

        if (a == 2)
        {
            v[i].pb(mp(n + 2, 0));
            v[n + 2].pb(mp(i, 0));
        }
    }

    int s, t, c;

    for (i = 0; i < m; i++)
    {
        scanf(" %d %d %d", &s, &t, &c);

        v[s].pb(mp(t, c));
        v[t].pb(mp(s, c));
    }



    int mini = 0;
    int pos;

    int x, y;

    n += 2;

    for (i = 1; i <= n; i++)
        cur[i] = inf;

    cur[n - 1] = 0;

  //  cerr << "adsfdfa" << endl;

    for (i = 1; i <= n; i++)
    {
        mini = inf;

     //   cerr << i << endl;

        for (j = 1; j <= n; j++)
            if (!used[j] && cur[j] < mini)
            {
                mini = cur[j];
                pos = j;
            }

        for (j = 0; j < (int)v[pos].size(); j++)
        {
            x = v[pos][j].first;
            y = v[pos][j].second;

            if (used[x])
                continue;

            if (cur[pos] + y < cur[x])
            {
                cur[x] = cur[pos] + y;
                prev[x] = pos;
            }
        }

        used[pos] = true;
    }

  //  cerr << cur[n] << endl;

    if (cur[n] >= inf)
    {
        cout << -1 << endl;

        return 0;
    }

    x = n;
    y = prev[n];

    int memx, memy;

    memy = y;

    while (y != n - 1)
    {
        x = y;
        y = prev[y];
    }

    memx = x;

    cout << memx << " " << memy << " " << cur[n] << endl;

    return 0;
}
