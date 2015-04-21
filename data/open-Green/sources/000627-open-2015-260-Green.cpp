#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long n, k, tmp, value = 1;
    vector<long long> prime;
    vector<long long> ans;
    scanf("%lld%lld", &n, &k);
    while(n%2 == 0 && k > 1) {
        n/=2; k--;
    }
    if (k==1) {
        printf("%lld\n", (n+1) / 2);
        return 0;
    }
    tmp = (long long)sqrt(tmp + .0) + 5;
    for(int i = 2; i <=tmp && i <= n; i++) {
        while(n%i == 0) {
            prime.push_back(i);
            n /= i;
        }
    }
    if(n != 1) prime.push_back(n);
    reverse(prime.begin(), prime.end());
    ans.resize(k);
    for(int i = 0; i < k; i++) ans[i] = 1;
    for(int i = 0; i < prime.size(); i++) {
        ans[0] *= prime[i];
        sort(ans.begin(), ans.end());
    }
    for(int i = 0; i < k; i++)
        value *= (ans[i]+1)/2;
    printf("%lld", value);
    return 0;
}
