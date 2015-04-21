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
    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> t;
    for (int i=1; i<=n; i++)
        cin >> ar[i];
    int mar = 0, a, b;
    for (int i=1; i<=n; i++)
        for (int j=i+1; j<=n; j++)
        if (ar[i] > ar[j])
        {
            int t = 0;
            for (int k=i+1; k<j; k++)
                t+=(ar[k]>ar[j]&&ar[k]<ar[i])*2;
            t++;
            if (t>mar)
            {
                mar = t;
                a = i;
                b = j;
            }
        }
    if (mar) cout << a << " " << b; else cout << -1;
}
