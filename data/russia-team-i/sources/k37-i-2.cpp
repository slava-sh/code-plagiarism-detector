#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout);
	long long n, d;
	cin >> n >> d;
	int a[100001];
	for(int i = 0; i<n;i++)
        cin >> a[i];
    if (n == 1)
    {
        cout << a[0];
        return 0;
    }
    sort(a, a + n);
    int r(0);
    while (a[r] <= d)
        r++;
    int q(r);
    for(int i = r; i < n; i++)
        if (a[i] < 3 * d)
            q = i;
    int ans(0);
    if (q == r)
            q = r + 1;
    for(int i = q + 1; i < n; i++)
        ans += (a[i] - 2 * d);
    ans = ans + a[q] - 2 * d + a[q - 1];
    cout << ans;
		return 0;
}
