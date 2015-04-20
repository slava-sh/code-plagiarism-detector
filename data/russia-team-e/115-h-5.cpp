#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
#include <ctime>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define int long long

int inf = 1e9;

main()
{
    freopen("secure.in", "r", stdin);
    freopen("secure.out", "w", stdout);
    int num1 = 0, num2 = 0;
    int n, m;
    cin >> n >> m;
    vector <pair <int, int> > A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i].s;
        if (A[i].s == 1)
            num1++;
        else if (A[i].s == 2)
            num2++;
        A[i].f = i;
    }
    vector <vector <pair <int, int> > > g(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        a--;
        b--;
        g[a].push_back(mp(b, cost));
        g[b].push_back(mp(a, cost));
    }
    srand(time(NULL));
    random_shuffle(A.begin(), A.end());
    pair <pair <int, int>, int> answer(mp(mp(0, 0), inf));
    if (num1 > num2)
    {
        int now = 0;
        for (int i = 0; i < n && now < 1500; i++)
        {
            if (A[i].s == 2)
            {
                now++;
                vector <int> d(n, inf);
                int s = A[i].f;
                d[s] = 0;
                set <pair <int ,int> > q;
                q.insert(mp(d[s], s));
                while (!q.empty())
                {
                    int  v = q.begin() -> second;
                    q.erase(q.begin());

                    for (int j = 0; j < g[v].size(); j++)
                    {
                        int to = g[v][j].first;
                        int len = g[v][j].second;
                        if (d[v] + len < d[to])
                        {
                            q.erase(mp(d[to], to));
                            d[to] = d[v] + len;
                            q.insert(mp(d[to], to));
                        }
                    }
                }
                for (int j = 0; j < n; j++)
                {
                    if (A[j].s == 1 && d[A[j].f] < answer.s)
                    {
                        answer.s = d[A[j].f];
                        answer.f.f = A[j].f;
                        answer.f.s = s;
                    }
                }
            }
        }
    }
    else
    {
        int now = 0;
        for (int i = 0; i < n && now < 1500; i++)
        {
            if (A[i].s == 1)
            {
                now++;
                vector <int> d(n, inf);
                int s = A[i].f;
                d[s] = 0;
                set <pair <int ,int> > q;
                q.insert(mp(d[s], s));
                while (!q.empty())
                {
                    int  v = q.begin() -> second;
                    q.erase(q.begin());

                    for (int j = 0; j < g[v].size(); j++)
                    {
                        int to = g[v][j].first;
                        int len = g[v][j].second;
                        if (d[v] + len < d[to])
                        {
                            q.erase(mp(d[to], to));
                            d[to] = d[v] + len;
                            q.insert(mp(d[to], to));
                        }
                    }
                }
                //cout << "LOL" << endl;
                for (int j = 0; j < n; j++)
                {
                    if (A[j].s == 2 && d[A[j].f] < answer.s)
                    {
                        answer.s = d[A[j].f];
                        answer.f.f = s;
                        answer.f.s = A[j].f;
                    }
                }
            }
        }
    }
    if (answer.s == inf)
    {
        cout << "-1" << endl;
        return 0;
    }
    cout << answer.f.f + 1 << " " << answer.f.s + 1 << " " << answer.s << endl;
}
