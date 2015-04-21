#include <bits/stdc++.h>

using namespace std;

pair<long long, long long> arr[200005];
vector<long long> betw;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    long long n, k, c, d;
    cin >> n >> k >> c >> d;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    long long ans = (long long)(arr[n-1].second - arr[0].first) * d;
    long long cans = ans;
    for(int i=1;i<n;i++)
    {
        betw.push_back(-arr[i-1].second + arr[i].first);
    }
    sort(betw.begin(), betw.end());
    int ck = k;
    while(!betw.empty())
    {
        long long t = betw[betw.size() - 1];
        betw.pop_back();
        cans -= t * d;
        ck--;
        if(!ck)
        {
            ck = k;
            cans += c;
        }
        ans = min(ans, cans);
    }
    cout << ans;
    return 0;
}
