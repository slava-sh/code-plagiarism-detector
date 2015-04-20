#include <bits\stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef long long ll;

void solve(int n)
{
   vector<int> v(n);
   for (int i = 0; i < n; i++)
      scanf(" %d", &v[i]);

   sort(v.begin(), v.end());
   reverse(v.begin(), v.end());
   vector<ll> prefsum(n + 1);

   for (int i = 0; i < n; i++)
        prefsum[i + 1] = prefsum[i] + v[i];

   for (int i = 0; i < n; i++)
   {
        ll total = prefsum[i];
        ll litre = prefsum[n] - prefsum[i];
        litre = (ll)v[i] * (ll)(n - i) - litre;

        if (litre <= total)
        {
            printf("%d\n", i);
            return;
        }
   }
}

int main()
{
   // freopen("input.txt", "rt", stdin);
   // freopen("output.txt", "w", stdout);
    freopen("merlin.in", "rt", stdin);
    freopen("merlin.out", "w", stdout);

    int n;
    while (cin >> n)
        solve(n);
}
