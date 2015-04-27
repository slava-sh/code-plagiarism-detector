#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <tuple>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

const int MAXN = 1e5 + 50;

typedef long long ll;

bool used[MAXN];
int cnt[MAXN];

void solve()
{
    int m, k;
    cin >> m >> k;
    cnt[0] = 0;
    for (int i = 1; i <= k; ++i)
    {
        cin >> cnt[i];
        used[i] = false;
    }
    bool ue = false;
    int a, b;
    int k1 = 0, k2;
    for (int i = 1; i < m; ++i)
    {
        cin >> a >> b;
        if (b && !ue)
        {
            ue = true;
            k1 = cnt[0];
        }
        if (ue) {
            used[a] = true;
        }
        cnt[a]--;
    }
    int k3 = MAXN;
    if (ue)
    {
        for (int i = 1; i <= k; ++i)
        {
            if (!used[i])
                k3 = min(k3, cnt[i]);
        }
        k2 = cnt[0] + k3;
    }
    else
    {
        k2 = cnt[0];
    }
    for (int i = 1; i <= k; ++i)
    {
        bool s = false;
        if (!used[i] && cnt[i] + k1 <= 0)
            s = true;
        if (cnt[i] + k2 <= 0)
            s = true;
        putc(s ? 'Y' : 'N', stdout);
    }
    putc('\n', stdout);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        solve();
}