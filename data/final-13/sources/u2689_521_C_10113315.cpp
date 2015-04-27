#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <bitset>
#include <time.h>
#define MODD 1000000007
#define MAXN 100000
#define ll long long
using namespace std;

int k,n;
string S;


ll sums[MAXN+2];
ll fact[MAXN+2];
ll factinv[MAXN+2];


ll modpow(ll x, ll y) {
    ll xs = x;
    ll answer = 1;
    while(y) {
        if (y&1) {
            answer = (answer * xs) % MODD;
        }
        y >>= 1;
        xs = (xs * xs) % MODD;
    }
    return answer;
}


ll binomial(ll n, ll k) {
    if (k > n)
        return 0;
    ll x =  (fact[n] * factinv[k])%MODD;
    return (x*factinv[n-k])%MODD;
}

ll solve() {
    if (k==0) {
        ll answer = 0;
        for(int i=0;i<n;i++) {
            answer = (answer*10 + S[i]-'0') % MODD;
        }
        return answer;
    }

    ll answer = 0;
    // the corners.
    ll x = 0;
    for (int i=0;i<n-1;i++) {
        x = (x * 10 + S[i]-'0')%MODD;
        answer = (answer + x * binomial(n-2-i, k-1))%MODD;
    }
    ll tenpow = 1;
    x = 0;
    for(int i=n-2;i>=0;i--) {
        x = (x + tenpow * (S[i+1]-'0'))%MODD;
        answer = (answer + x * binomial(i, k-1))%MODD;
        tenpow = (tenpow * 10)%MODD;
    }
    
    if (k == 1)
        return answer;
    
    sums[1]=0;
    for(int i=1;i<n-1;i++) {
        sums[1] = (sums[1] + S[i]-'0') % MODD;
    }
    
    ll sum_all_digs = sums[1];
    ll last = 0;
    tenpow = 1;
    for(int i=2;i<=n-2;i++) {
        last = (last + tenpow * (S[n-i]-'0'))%MODD;
        sum_all_digs -= S[i-1]-'0';
        sum_all_digs %= MODD;
        sums[i] = (sums[i-1] - last)*10 + sum_all_digs;
        sums[i] %= MODD;
        tenpow = (tenpow * 10)%MODD;
    }

    
    for (int l=1;l<=n-2;l++) {
        answer = (answer + binomial(n-2-l, k-2) * sums[l])%MODD;
    }
    
    while(answer < 0)
        answer = (answer + MODD)%MODD;
    
    return answer;
    
    
    
    
}

int main() {
    fact[0]=factinv[0]=1;
    for(int i=1;i<=100000;i++) {
        fact[i]=(fact[i-1]*i)%MODD;
        factinv[i]=modpow(fact[i], MODD-2);
    }

    
    
    cin>>n>>k;
    cin>>S;
    
    cout << solve() << endl;
    
    
}