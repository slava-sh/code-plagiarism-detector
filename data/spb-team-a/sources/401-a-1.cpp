#include <bits\stdc++.h>
using namespace std;

void solve(int n)
{
    string cur;

    for (int i = 0; i < n; i++)
    {
        cin >> cur;
        int first = (cur[0] - '0') * 10 +
        cur[1] - '0';
        int second = (cur[2] - '0') * 10
        + cur[3] - '0';

        int ans = first * first + second * second;
        ans %= 7;

        if (ans == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
}

int main()
{
   // freopen("input.txt", "rt", stdin);
   // freopen("output.txt", "w", stdout);
    freopen("abcd.in", "rt", stdin);
    freopen("abcd.out", "w", stdout);

    int n;
    while (cin >> n)
        solve(n);
}
