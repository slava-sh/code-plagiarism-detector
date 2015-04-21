#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;

int h[76000];
int tree[76000];
int n;

void add(int x, int val)
{
    for(int i = x; i < n; i |= i + 1)
        tree[i] += val;
}

int sum(int r)
{
    int res = 0;
    for(int i = r; i >= 0; i = (i & (i + 1)) - 1)
        res += tree[i];
    return res;
}

int sum(int l, int r)
{
    int res = sum(r) - res -= sum(l - 1);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> h[i];

    pair<int, int> ans = mp(-1, -1);
    int best = 0;

    for(int l = 0; l < n; l++)
    {
        if(l + 1 < n && h[l + 1] > h[l])
            continue;
        memset(tree, 0, sizeof(tree));
        for(int r = l + 1; r < n; r++)
        {
            if(h[l] >= h[r] + 2 && (r == l + 1 || h[r - 1] > h[r]))
            {
                int prof = sum(h[r] + 1, h[l] - 1);
                if(prof > best)
                {
                    best = prof;
                    ans = mp(l + 1, r + 1);
                }
            }
            add(h[r], 1);
        }
    }

    cout << ans.first << ' ' << ans.second;
    return 0;
}
