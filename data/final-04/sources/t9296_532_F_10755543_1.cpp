#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <memory.h>
#include <set>
#include <ctime>
#include <map>
#include <cstring>
#include <queue>
 
using namespace std;
 
const int mod = (1e9 + 7);
const long long p1 = 31;
const long long mod1 = (1e9 + 7);
const long long mod2 = 1e9 + 9;
const int ver1 = (62 * 62);
const int maxm = 10000;
const long long p2 = 37;
const long long p3 = 29;
const int maxx = 1e9, maxy = 1e9;

string ar, arz;
pair<long long, long long> st[200500];
pair<long long, long long> sum[30];
int p[30];
int pos[30];
pair<long long, long long> hash1[200500];
int used[30];
vector <int> res;

int main() {
    int n, m;    cin >> n >> m;    cin >> ar >> arz;

    st[0] = make_pair(1LL, 1LL);
    for (int i = 1; i <= n; ++i) {        st[i] = st[i - 1];        st[i].first *= p1;        st[i].second *= p2;        st[i].second %= mod2;    }
    for (int i = 0; i < n; ++i) {
        if (i) {    hash1[i] = hash1[i - 1];}
        hash1[i].first += st[i].first * (long long)(ar[i] - 'a' + 1);
        hash1[i].second += st[i].second * (long long)(ar[i] - 'a' + 1);
        hash1[i].second %= mod2;
    }
    for (int i = 0; i < 26; ++i) {        pos[i] = -1;    }
    for (int i = 0; i < m; ++i) {        int j = arz[i] - 'a';        pos[j] = i;        sum[j].first += st[i].first;        sum[j].second += st[i].second;        sum[j].second %= mod2;    }
    int ans = 0;
    for (int i = 0; i + m - 1 < n; ++i) {
        pair<long long, long long> q = make_pair(0LL, 0LL);
        memset(used, 0, sizeof used);        memset(p, 0, sizeof p);
        int flag = 0;        for (int j = 0; j < 26; ++j) {
    if (pos[j] == -1) {         continue;
    }
    long long k = ar[pos[j] + i] + 1 - 'a';
    if (used[j]) {        if (k - 1 != p[j]) {
    flag = 1;
    break;
}
    }
    else {
        if (used[k - 1]) {
    flag = 1;
            break;
                }
                used[k - 1] = used[j] = 1;
                p[j] = k -1;                p[k - 1] = j;
            }
            q.first += k * st[i].first * sum[j].first;            q.second += ((k * st[i].second) % mod2 ) * sum[j].second;            q.second %= mod2;
        }
        if (flag) {            continue;        }
        pair<long long, long long> w = hash1[i + m - 1];
        if (i) {            w.first -= hash1[i - 1].first;            w.second -= hash1[i - 1].second;            w.second += mod2;
            w.second %= mod2;
        }
        if (w == q) {            ++ans;
            res.push_back(i + 1);
        }
    }
    cout << ans << endl;    for (int i = 0; i < ans; ++i) {
        cout << res[i] << ' ';
    
    
    
    
    }

    return 0;
}