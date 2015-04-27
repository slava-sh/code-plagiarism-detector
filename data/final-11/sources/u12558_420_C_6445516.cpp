#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    long long n, p, z=0, i, j, x, y;
    cin>>n>>p;
    long long res=((n-1)*n)/2;
    map<pair<long long, long long>, long long> m;
    vector<long long> sum(n), sum2(n);
    for (i=0;i<n;++i)
    {
        cin>>x>>y;
        if (x>y)
        {
            swap(x, y);
        }
        ++m[make_pair(x-1, y-1)];
        ++sum[x-1];
        ++sum[y-1];
        ++sum2[x-1];
        ++sum2[y-1];
    }
    sort(sum.begin(), sum.end());
    x=0;
    y=n-1;
    while (x<n)
    {
        while (y>x && sum[x]+sum[y]>=p)
        {
            --y;
        }
        if (y>x)
        {
            res-=y-x;
        }
        ++x;
    }
    for (map<pair<long long, long long>, long long>::iterator it=m.begin();it!=m.end();++it)
    {
        pair<long long, long long> z=it->first;
        if (sum2[z.first]+sum2[z.second]>=p && sum2[z.first]+sum2[z.second]-it->second<p)
        {
            --res;
        }
    }
    cout<<res<<endl;
    return 0;
}
