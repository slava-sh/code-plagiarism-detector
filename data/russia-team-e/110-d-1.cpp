#include <fstream>
#include <iostream>

#include<vector>
#include<algorithm>

#define int long long int

using namespace std;

main()
{
    ifstream cin ("fence.in");
    ofstream cout("fence.out");
    int n, k;
    cin >> n >> k;
    vector <int> V;
    V.resize(n);
    for (int i = 0; i < n; i++)
        cin >> V[i];
    sort(V.begin(), V.end());
    int MIN = V[0];
    int l = 0, r = MIN + 1;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        bool ok = 1;
        int last = 0;
        for (int i = 0; i < n; i++)
        {
            last += m;
            if (last <= V[i])
                last = V[i];
            if (last > k)
                ok = 0;
        }
        if (ok)
            l = m;
        else
            r = m;
    }
    cout << l << endl;
}
