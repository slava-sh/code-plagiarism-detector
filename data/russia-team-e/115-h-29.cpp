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
//#define int long long

int inf = 1e9;

main()
{
    freopen("secure.in", "r", stdin);
    freopen("secure.out", "w", stdout);
    int num1 = 0, num2 = 0;
    int n, m;
    scanf("%d%d", &n, &m);
    //cin >> n >> m;
    vector <pair <int, int> > A(n);
    vector <pair <int, int> > B(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", & A[i].s);
        //cin >> A[i].s;
        if (A[i].s == 1)
            num1++;
        else if (A[i].s == 2)
            num2++;
        A[i].f = i;
        B[i].f = i;
        B[i].s = A[i].s;
    }
    vector <vector <pair <int, int> > > g(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, cost;
        scanf("%d%d%d", &a, &b, &cost);
        //cin >> a >> b >> cost;
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
        for (int i = 0; i < n && now < 1800; i++)
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
                    if (B[v].s == 1)
                    {
                        if (d[v] < answer.s)
                        {
                            answer.s = d[v];
                            answer.f.f = v;
                            answer.f.s = s;
                        }
                        break;
                    }
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
            }
        }
    }
    else
    {
        int now = 0;
        for (int i = 0; i < n && now < 2000; i++)
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
                    if (B[v].s == 2)
                    {
                        if (d[v] < answer.s)
                        {
                            answer.s = d[v];
                            answer.f.f = s;
                            answer.f.s = v;
                        }
                        break;
                    }
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
            }
        }
    }
    if (answer.s >= inf)
    {
        printf("-1\n");
        //cout << "-1" << endl;
        return 0;
    }
    printf("%d %d %d", answer.f.f + 1, answer.f.s + 1, answer.s);
    //cout << answer.f.f + 1 << " " << answer.f.s + 1 << " " << answer.s << endl;
}
