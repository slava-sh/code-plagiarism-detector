#include <bits/stdc++.h>
using namespace std;
vector<long long> prom;
long long n, k, c, d;

int main()
{
    long long n, k, c, d;
    cin >> n >> k >> c >> d;
    long long apr = 0;
    long long mir = 0;
    for (long long i=0; i<n; i++)
    {
        long long ai, bi;
        cin >> ai >> bi;
        mir += bi - ai;
        if (apr) prom.push_back(ai - apr);
        apr = bi;
    }
    prom.push_back(0);
    sort (prom.begin(), prom.end());
    for (long long i=1; i<prom.size(); i++)
        prom[i] += prom[i-1];
    long long mires = INFINITY;
    for (long long i=0; i<prom.size(); i++)
    {
      //  cout << i << " " << prom[i] * d + ((n-i-1) / k) * (c) << "\n";
        mires = min(mires, prom[i] * d + ((n-i-1) / k) * (c));
    }
    cout << mires + mir * d;
}
