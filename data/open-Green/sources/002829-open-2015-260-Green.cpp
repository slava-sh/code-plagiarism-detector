#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;

int main() {
    long long n, k, sqrt_n, value;
    vector<long long> divisors;
    scanf("%lld%lld", &n, &k);
    while(n%2 == 0 && k > 1) {
        n/=2; k--;
    }
    if (k==1) {
        printf("%lld\n", (n+1) / 2);
        return 0;
    }
    value = n;
    sqrt_n = (long long)sqrt(n + .0);
    if(sqrt_n*sqrt_n > n) sqrt_n--;
    if((sqrt_n+1)*(sqrt_n+1) < n) sqrt_n++;
    for(int i = 1; i <=sqrt_n && i <= n; i++) {
        if(n % i == 0)
            divisors.push_back(i);
    }
    if(sqrt_n * sqrt_n == n) divisors.pop_back();
    int size_d = divisors.size();
    for(int i = 0; i < size_d; i++)
        divisors.push_back(n / divisors[i]);
    if(sqrt_n * sqrt_n == n) divisors.push_back(sqrt_n);
    sort(divisors.begin(), divisors.end());
    map<long long, int> div_p;
    for(int i = 0; i < divisors.size(); i++)
        div_p[divisors[i]] = i;
    vector <vector<long long> > div_v;
    div_v.resize(divisors.size());
    for(int i = 0; i < divisors.size(); i++)
        for(int j = 0; j <=i; j++)
            if(divisors[i] % divisors[j] == 0)
                div_v[i].push_back(j);
    vector<vector<long long> > ans;
    ans.resize(divisors.size());
    for(int i = 0; i < ans.size(); i++)
        ans[i].resize(k+1);
    for(int i = 0; i < divisors.size(); i++) {
        for(int j = 1; j <=k; j++) {
            if(j == 1) {
                ans[i][j] = (divisors[i] + 1) / 2;
                continue;
            }
            if(i == 0) {
                ans[i][j] = 1;
                continue;
            }
            ans[i][j] = 0;
            for(int h = 0; h < div_v[i].size(); h++) {
                int q = div_p[divisors[i] / divisors[div_v[i][h]]];
                for(int t = 1; t < j; t++)
                    if(ans[i][j] == 0 || (ans[div_v[i][h]][t] * ans[q][j-t] < ans [i][j]))
                        ans[i][j] = ans[div_v[i][h]][t] * ans[q][j-t];
            }
        }
    }
    printf("%lld", ans[divisors.size()-1][k]);
    return 0;
}
