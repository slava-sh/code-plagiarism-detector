#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll n;
int k, timer = 0;
vector<ll> v;

int main()
{
    cin >> n >> k;
    for(int i = 2; i*1LL*i <= n; ++i){
        if(timer >= k-1)
            break;
        if(n % i == 0){
            while(n > 1 && n % i == 0 && timer < k-1){
                v.push_back(i);
                n /= i;
            }
        }
    }
    ll result = 1;
    v.push_back(n);
    while(v.size() <= k)
        v.push_back(1);
    for(int i = 0; i < k; ++i){
        result *= 1LL*(v[i] + 1LL)>>1LL;
    }
    cout << result << '\n';
    return 0;
}
