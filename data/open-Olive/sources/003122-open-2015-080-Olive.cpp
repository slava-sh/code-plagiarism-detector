#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ar[n+1];
    int inv[n+1];
    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> t[n+1];

    for (int i=1; i<=n; i++)
    {
        t[i] = t[i-1];
        cin >> ar[i];
        t[i].insert(ar[i]);
    }
    int mar = 0, a, b;
    for (int i=1; i<=n; i++)
        for (int j=i+1; j<=n; j++)
        if (ar[i] > ar[j])
        {
            int te = 0;
            te = t[j].order_of_key(ar[i]) - t[i].order_of_key(ar[i]) + t[i].order_of_key(ar[j]) - t[j].order_of_key(ar[j]);
            te++;
            if (te>mar)
            {
                mar = te;
                a = i;
                b = j;
            }
        }
    if (mar) cout << a << " " << b; else cout << -1 << " " << -1;
}
