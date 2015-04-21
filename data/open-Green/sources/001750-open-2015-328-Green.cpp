#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n;
int k, timer = 0;
vector<ll> v;
int s = 0;

int main()
{
    cin >> n >> k;
    while(n % (1 << s) == 0) s++;
    --s;
    s = min(s, k-1);
    n /= (1 << s);
    k -= s;
    if(k == 1){
        cout << (n+1)/2 << '\n';
        return 0;
    }
    for(int i = 3; i * 1LL * i <= n; ++i){
        if(n % i == 0){
            while(n > 1 && n % i == 0){
                v.push_back(i);
                n /= i;
            }
        }
    }
    if(n > 1)
        v.push_back(n);
    while(v.size() > k){
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        int a = v.back();
        v.pop_back();
        v.back()*=a;
    }
    ll result = 1;
    for(int i = 0; i < v.size(); ++i){
        result *= 1LL*(v[i]+1LL) >> 1LL;
    }
    cout << result << '\n';
    return 0;
}
