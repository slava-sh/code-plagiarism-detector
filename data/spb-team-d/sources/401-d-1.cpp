#include <bits\stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back

void solve(int n)
{
    int m;
    cin >> m;

    vector<pair<int, int> > v(n);
    vector<int> Inc(n);

    for (int i = 0; i < n; i++)
        scanf(" %d %d %d", &v[i].first, &v[i].second,
              &Inc[i]);

    for (int i = 0; i < m; i++)
    {
        int q;
        scanf(" %d", &q);

        int ans = 0;
        for (int j = 0; j < n; j++)
            if (q >= v[j].first && q <= v[j].second)
            {
                if ((q - v[j].first) % 2 == 0)
                    ans += Inc[j];
                else
                    ans -= Inc[j];
            }

        printf("%d\n", ans);
    }
}

int main()
{
   // freopen("input.txt", "rt", stdin);
   // freopen("output.txt", "w", stdout);
    freopen("dunes.in", "rt", stdin);
    freopen("dunes.out", "w", stdout);

    int n;
    while (cin >> n)
        solve(n);
}
