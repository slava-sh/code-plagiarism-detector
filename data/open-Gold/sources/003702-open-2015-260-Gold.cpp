#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, k, c, d;
    scanf("%lld%lld%lld%lld", &n, &k, &c, &d);
    long long *a = new long long[n];
    long long *b = new long long[n];
    for(int i = 0; i < n; i++) {
        scanf("%lld%lld", &a[i], &b[i]);
    }
    vector <long long> seg;
    for(int i = 1; i < n; i++)
        seg.push_back(- a[i] + b[i - 1]);
    sort(seg.begin(), seg.end());
    long long tmp = (b[n-1] - a[0]) * d, ans = tmp;
    int t = 0;
    for(; t < k-1 && t < n-1; t++)
        tmp += seg[t] * d;
    ans = tmp;
    while(t != n-1) {
        for(int i = 0; i < k && t < n-1; i++) {
            tmp += seg[t] * d;
            t++;
        }
        tmp += c;
        if(tmp < ans) ans = tmp;
    }
    printf("%lld", ans);
    return 0;
}
