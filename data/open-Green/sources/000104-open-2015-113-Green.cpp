#include <bits/stdc++.h>

using namespace std;

vector<long long> fac;

long long arr[1000];

int main()
{
    ios_base::sync_with_stdio(0);
    long long n, k;
    cin >> n >> k;
    int to = sqrt(n) + 2;
    for(int i=2;i<to;i++)
    {
        while(n % i == 0)
        {
            fac.push_back(i);
            n /= i;
        }
    }
    if(n > 1)
        fac.push_back(n);
    while(fac.size() < k)
        fac.push_back(1);
    long long ans = n;
    for(int i=k;i<fac.size();i++)
    {
        fac[k - 1] *= fac[i];
    }
    arr[0] = 1;
    for(int i=1;i<=k;i++)
    {
        arr[i] = arr[i - 1] * ((fac[i - 1] + 1) / 2);
    }
    cout << arr[k];
    return 0;
}
