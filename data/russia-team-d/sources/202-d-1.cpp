#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> a;
    a.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int l = 0;
    int r = min(k / n + 1, a[0]) + 1;
    while(l + 1 < r)
    {
        int m = (l + r) / 2;
        //cout << m << endl;
        int cur = 0;
        for(int i = 0; i < n; i++)
            cur = max(cur + m, a[i]);
        if(cur <= k) l = m;
        else r = m;
    }
    cout << l << endl;
    return 0;
}
