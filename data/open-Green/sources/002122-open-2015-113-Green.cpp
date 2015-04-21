#include <bits/stdc++.h>

using namespace std;

vector<long long> fac;
priority_queue<long long> q;
int cnt2 = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    long long n;
    int k;
    cin >> n >> k;
    while(n % 2 == 0)
    {
        cnt2++;
        n /= 2;
    }
    for(int i=0;i<min(cnt2, k-1);i++)
    {
        fac.push_back(2);
        cnt2--;
    }
    if(n == 1 && cnt2 == 1)
    {
        fac.push_back(2);
        cnt2 = 0;
    }
    if(fac.size() == k - 1)
    {
        fac.push_back(n * (1<<cnt2));
        n = 1;
    }
    int to = sqrt(n) + 2;
    for(int i=3;i<to;i++)
    {
        while(n % i == 0)
        {
            q.push(-i);
            n /= i;
        }
    }
    if(n > 1)
        q.push(-n);
    if(fac.size() < k)
    {
        while(q.size() > k - fac.size())
        {
            long long a, b;
            a = q.top();
            q.pop();
            b = q.top();
            q.pop();
            q.push(-a*b);
        }
        while(q.size())
        {
            long long a = q.top();
            q.pop();
            fac.push_back(-a);
        }
    }
    while(fac.size() < k)
        fac.push_back(1);
    long long ans = 1;
    for(int i=0;i<k;i++)
    {
        ans *= ((fac[i] + 1) / 2);
    }
    cout << ans;
    return 0;
}
