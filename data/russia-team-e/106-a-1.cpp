#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <queue>

#define x first
#define y second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int N = (int)1000 + 7;
const int INF = 2e9 + 5;
const int MOD = 1e9 + 7;

int n;
int z[N], clr[N];
int a[N][N];

int cnt = 0;

void dfs(int v)
{
    for (int i = 0; i < n; i++)
    {
        if (!a[v][i]) continue;

        if (!clr[i])
        {
            if (a[v][i] == 1)
                clr[i] = clr[v];
            else
                clr[i] = 3 - clr[i];
            dfs(i);
        }
        else
        {
            if ((a[v][i] == 1 && clr[i] != clr[v]) || (a[v][i] == 2 && clr[i] == clr[v]))
            {
                cout << 0 << endl;
                exit(0);
            }
        }
    }
}

int main()
{
    freopen("binary.in", "r", stdin);
    freopen("binary.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", &z[i]);

    if (z[0] != 0 && z[0] != -1)
    {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 1; i < n; i++)
    {
        if (z[i] == -1) continue;

        if (i + z[i] > n)
        {
            cout << 0 << endl;
            return 0;
        }
        for (int j = 0; j < z[i]; j++)
            a[i + j][j] = a[j][j + i] = 1;

        a[z[i]][i + z[i]] = a[i + z[i]][z[i]] = 2;
    }

    for (int i = 0; i < n; i++)
        if (!clr[i])
        {
            clr[i] = 1;
            dfs(i);
            cnt++;
        }

    ll ans = 1;
    for (int i = 0; i < cnt; i++)
        ans = (ans * 2) % MOD;

    cout << ans << endl;

    return 0;
}
