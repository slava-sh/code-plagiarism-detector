#include <bits\stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef long long ll;

void solve(int n)
{
    vector<pair<int, int> > v(n);
    for (int i = 0; i < n; i++)
        scanf(" %d %d", &v[i].first, &v[i].second);

    sort(v.begin(), v.end());

    ll ans = 0;
    int curArmy = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int sum = 0;
        for (int j = 0; j < i; j++)
            sum += v[j].first;

        while (sum + curArmy <= v[i].first)
            ans += v[i].second, v[i].first--,
            curArmy++;
    }

    cout << ans << endl;
}

int main()
{
   // freopen("input.txt", "rt", stdin);
   // freopen("output.txt", "w", stdout);
    freopen("conquest.in", "rt", stdin);
    freopen("conquest.out", "w", stdout);

    int n;
    while (cin >> n)
        solve(n);
}
