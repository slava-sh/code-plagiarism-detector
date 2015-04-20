#include <bits\stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back

void solve(int n)
{
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        scanf(" %d", &a[i]);

    vector<pair<int, int> > ans;

    int col = 0;
    while (a[col] >= col + 1 &&
            col < n)
    {
        ans.pb(mp(col + 1, col + 1));
        col++;
    }

    printf("%d\n", (int)ans.size());
    for (auto x : ans)
        printf("%d %d\n", x.first, x.second);
}

int main()
{
   // freopen("input.txt", "rt", stdin);
   // freopen("output.txt", "w", stdout);
    freopen("chess.in", "rt", stdin);
    freopen("chess.out", "w", stdout);

    int n;
    while (cin >> n)
        solve(n);
}
