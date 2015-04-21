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

pair<int, int> visit[200000];
vector<int> space;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n,k,c,d;
    cin >> n >> k >> c >> d;
    for(int i = 0; i < n; i++)
        cin >> visit[i].first >> visit[i].second;

    ll ans = 0;
    for(int i = 0; i < n; i++)
        ans += (visit[i].second - visit[i].first) * (ll)d;

    for(int i = 0; i < n - 1; i++)
        space.pb(visit[i + 1].first - visit[i].second);
    sort(space.begin(), space.end(), greater<int>());
    int pnt = min(k - 1, (int)space.size() - 1);
    while(pnt < space.size())
    {
        ll profit = 0;
        for(int i = pnt; i < min(pnt + k, (int)space.size()); i++)
            profit += space[i] * (ll)d;
        if(profit > c)
        {
            pnt = min(pnt + k, (int)space.size() - 1);
            ans += c;
        }
        else
            break;
    }
    for(int i = pnt; i < space.size(); i++)
        ans += space[i] * (ll)d;
    cout << ans << '\n';
    return 0;
}
