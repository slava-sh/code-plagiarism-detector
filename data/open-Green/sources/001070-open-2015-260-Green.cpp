#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long n, k, tmp, value;
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
    value = n;
    tmp = (long long)sqrt(n + .0) + 5;
    for(int i = 2; i <=tmp && i <= n; i++) {
        while(n%i == 0) {
            prime.push_back(i);
            n /= i;
        }
    }
    if(n != 1) prime.push_back(n);
    ans.resize(k);
    for(int i = 0; i < k; i++) ans[i] = 1;
    vector<int> prime_ans;
    prime_ans.resize(k);
    for(int i = 0; i < prime.size(); i++)
        prime_ans[i] = k-1;
    ans[k-1] = value;
    bool fl = true;
    do {
        long long min_a = 0;
        for(int i = 0; i < k; i++)
            if(ans[min_a] > ans[i])
                min_a = i;
        fl = false;
        for(int i = 0; i < prime.size() && !fl; i++)
            if(prime_ans[i] != min_a && ans[prime_ans[i]]/prime[i] > ans[min_a])
            {
                ans[min_a] *= prime[i];
                ans[prime_ans[i]] /= prime[i];
                prime_ans[i] = min_a;
                fl = true;
            }
    } while(fl);
    value = 1;
    for(int i = 0; i < k; i++)
        value *= (ans[i]+1)/2;
    printf("%lld", value);
    return 0;
}
