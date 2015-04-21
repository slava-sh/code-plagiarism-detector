#include <iostream>
#include <vector>
#include <queue>
#include <tuple>


using namespace std;
const long long inf = 1e15;

int main()
{
    long long n, m , d, a, b, q, t, j, i, ans = inf, v, time;
    cin >> n >> m >> d;
    vector<vector< pair< long long, long long> > > tr(n);
    vector <vector<bool> > used(n);

    queue<tuple<long long, long long, long long> > och;
    for (i = 0; i < m; i++)
    {
        cin >> a >> b >> t;
        a--;
        b--;
        tr[a].push_back(make_pair(b, t));
        if (a != b) tr[b].push_back(make_pair(a, t));
        used[a].push_back(false);
        if (a != b) used[b].push_back(false);

    }

    cin >> q;
    for (j = 0; j < q; j++)
    {
        cin >> a >> b;
        while(!och.empty()) och.pop();
        ans = inf;
        a--; b--;
        for (i = 0; i < n; i++)
            used[i].assign(used[i].size(), false);
        used[a].assign(used[i].size(), true);

        for (i = 0; i < tr[a].size(); i++)
        {
            och.emplace(tr[a][i].first, tr[a][i].second, 0);
            used[a][i] == true;
        }
        while (!och.empty())
        {
            tie(v, t, time) = och.front();

            time++;
            och.pop();
            if (v == b) {ans = time; break;}
            for (i = 0; i < tr[v].size(); i++)
            if ((tr[v][i].second >= t - d) && (tr[v][i].second <= t + d))
                if (!used[v][i])
                {och.emplace(tr[v][i].first, tr[v][i].second, time); used[v][i] = true;}

        }
        if (ans == inf) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}
