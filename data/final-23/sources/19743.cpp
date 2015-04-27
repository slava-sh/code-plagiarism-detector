#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int a[400001], tree1[400001], tree2[400001], p, n;

void build_tree()
{
    p = 1;
    while (p < n) p *= 2;

    for (int i = n + 1; i <= p; i++) a[i] = 0;

    for (int i = p; i <= p * 2 - 1; i++)
    {
        if (i % 2 == 0)
            tree1[i] = - a[i - p + 1];
        else
            tree1[i] = a[i - p + 1];
    }

    for (int i = p - 1; i >= 1; i--)
        tree1[i] = tree1[i * 2] + tree1[i * 2 + 1];


    for (int i = p; i <= p * 2 - 1; i++)
    {
        if (i % 2 == 0)
            tree2[i] = a[i - p + 1];
        else
            tree2[i] = - a[i - p + 1];
    }

    for (int i = p - 1; i >= 1; i--)
        tree2[i] = tree2[i * 2] + tree2[i * 2 + 1];
}

void update(int a, int b)
{
    if (a % 2 == 0)
    {
        a += p - 1;
        tree1[a] = b;
        tree2[a] = - b;
    }
    else
    {
        a += p - 1;
        tree1[a] = - b;
        tree2[a] = b;
    }

    while (a > 1)
    {
        a /= 2;
        tree1[a] = tree1[a * 2] + tree1[a * 2 + 1];
        tree2[a] = tree2[a * 2] + tree2[a * 2 + 1];
    }
}

int sum1(int l, int r, int L, int R, int v)
{
    if (l > R || r < L) return 0;
    if (l <= L && r >= R) return tree1[v];
    else
        return sum1(l, r, L, (L + R) / 2, v * 2) +
                sum1(l, r, (L + R) / 2 + 1, R, v * 2 + 1);
}

int sum2(int l, int r, int L, int R, int v)
{
    if (l > R || r < L) return 0;
    if (l <= L && r >= R) return tree2[v];
    else
        return sum2(l, r, L, (L + R) / 2, v * 2) +
                sum2(l, r, (L + R) / 2 + 1, R, v * 2 + 1);
}

int main()
{
    freopen("signchange.in","r",stdin);
    freopen("signchange.out","w",stdout);

    int m;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    build_tree();

    cin >> m;

    for (int i = 1; i <= m; i++)
    {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 0) update(l,r);
        else
        {
            if (l % 2 == 1) cout << sum2(l,r,1,p,1) << endl;
            else cout << sum1(l,r,1,p,1) << endl;
        }
    }

    return 0;
}
