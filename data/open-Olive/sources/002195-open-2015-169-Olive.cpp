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

int h[5001];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> h[i];

    pair<int, int> ans = mp(-1, -1);
    int best = 0;

    for(int l = 1; l <= n; l++)
        for(int r = l + 1; r <= n; r++)
            if(h[l] > h[r])
            {
                int prof = abs(h[l] - l) + abs(h[r] - r) - abs(h[l] - r) - abs(h[r] - l);
                if(prof > best)
                {
                    best = prof;
                    ans = mp(l, r);
                }
            }
    cout << ans.first << ' ' << ans.second;
    return 0;
}
