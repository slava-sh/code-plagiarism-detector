// esta3anna 3al sha2a belAllah ..
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#include<sstream>
#include<limits.h>
#include<iomanip>
#include<cstring>
#include<bitset>
#include<fstream>
#include<cmath>
#include<cassert>
#include <stdio.h>
#include<ctype.h>
using namespace std;
#define rep(i,n,m) for(int i = (int)(n), _m = (int)(m); i < _m; ++ i)
#define rrep(i,n,m) for(int i = (int)(n), _m = (int)(m); i >= _m; -- i)
#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz size()
#define pb push_back
#define mp make_pair
#define mems(arr, v) memset(arr, v, sizeof arr)
#define setBit(mask, bit) ((mask) | (1LL << (bit)))
#define resetBit(mask, bit) ((mask) & (~(1LL << (bit))))
#define flipBit(mask, bit) ((mask) ^ (1LL << (bit)))
#define is0(mask, bit)(((mask) & (1LL << (bit))) == 0)
#define is1(mask, bit)(((mask) & (1LL << (bit))) != 0)
#define removeLastBit(mask) ((mask) & ((mask) - 1LL))
#define firstBitOn(mask) ((mask) & ~((mask) - 1LL))
#define grayCode(mask) ((mask) ^ ((mask) << 1LL))
#define repSubMasks(subMask, mask) for(ll subMask = (ll)(mask), _mask = subMask; subMask; subMask = _mask & (subMask - 1))
int countBits(long long mask) {int res = 0; while(mask) mask &= (mask - 1), ++ res; return res;}
string toString(long long n) {stringstream ss; ss << n; return ss.str();}
long long toNumber(string s) {stringstream ss; long long n; ss << s; ss >> n; return n;}
#define INT_MAX  1000000000
#define INT_MIN -1000000000
#define INF 1000000000
#define EPS 1e-9
#define debug(x) cout << #x << " : " << x << endl
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define Read() freopen("input.txt","r",stdin)
#define Write() freopen("output.txt","w",stdout)
ll mod;
ll dp[501][501];
ll rec(int r, int ones) {
    int twos = (r * 2) - ones;
    twos /= 2;
    if(r == 0) return ones == 0 && twos == 0;
    ll &res = dp[r][ones];
    if(res != -1) return res;
    res = 0;
    if(ones >= 2) {
        res = rec(r - 1, ones - 2) * ((ones * (ones - 1)) / 2);
        res %= mod;
    }
    if(twos >= 2) {
        res += (rec(r - 1, ones + 2) * ((twos * (twos - 1)) / 2)) % mod;
        res %= mod;
    }
    res += (rec(r - 1, ones) * ones * twos) % mod;
    res %= mod;
    return res;
}
int main() {
  //  Read();
    int n, m;
    string str;
    while(cin >> n >> m >> mod) {
        mems(dp, -1);
        int col[501];
        mems(col, 0);
        bool valid = true;
        rep(i, 0, m) {
            cin >> str;
            rep(j, 0, str.size()) if(str[j] == '1') col[j] ++;
            valid &= count(all(str), '1') == 2;
        }
        int ones = 0;
        rep(i, 0, n)
            if(col[i] == 1) ones ++;
        if(!valid) cout << 0 << endl;
        else cout << rec(n - m, ones) << endl;
    }
}