#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

long long a[100000];

int main()
{
    freopen("merlin.in", "r", stdin);
    freopen("merlin.out", "w", stdout);
    int n;
    cin >> n;
    long long prev = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n - 1; i++)
    {
        prev += a[n - 1] - a[i];
    }
    if (prev == 0)
    {
        cout << 0;
        return 0;
    }
    long long sum = 0;
    for (long long i = n - 1; i >= 0; i--)
    {
        sum += a[i];
        if (prev <= sum)
        {
            cout << n - i;
            return 0;
        }
        prev -= i * (a[i] - a[i - 1]);
    }
}


