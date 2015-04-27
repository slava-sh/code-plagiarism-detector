#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

const int MAXN = 305000;
bool isPrime(int x) {
    for (int i = 2; i*i <= x; ++i)
        if (x % i == 0)
            return false;
    return true;
}

long long MOD1, MOD2;
const long long OSN1 = 179;
const long long OSN2 = 309;

long long step1[MAXN], step2[MAXN];

struct MakeHash {
    vector<int> v1, v2;
    MakeHash(){}
    MakeHash(const vector<int> &v) {
        v1.assign(v.size(), 0);
        v2.assign(v.size(), 0);
        v1[0] = v2[0] = v[0];
        for (int i = 1; i < (int)v.size(); ++i) {
            v1[i] = (v1[i-1] * OSN1 + v[i]) % MOD1;
            v2[i] = (v2[i-1] * OSN2 + v[i]) % MOD2;
        }
    }

    pair<long long, long long> getHash(int l, int r) {
        pair<long long, long long> ans(v1[r], v2[r]);
        if (l) {
            ans.first = ((ans.first - v1[l-1]*step1[r-l+1])%MOD1 + MOD1) % MOD1;
            ans.second = ((ans.second - v2[l-1]*step2[r-l+1])%MOD2 + MOD2) % MOD2;
        }
        return ans;
    }
};

int n, m;
string s, t;

MakeHash hs[26], ht[26];
int fl[26];

int main() {
    ios_base::sync_with_stdio(0);

    MOD1 = 1004242567;
    while (!isPrime(MOD1))
        MOD1 += 2;
    MOD2 = MOD1 + 2;
    while (!isPrime(MOD2))
        MOD2 += 2;

//cerr << MOD1 << ' ' << MOD2 << "\n";
    step1[0] = step2[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        step1[i] = (step1[i-1] * OSN1) % MOD1;
        step2[i] = (step2[i-1] * OSN2) % MOD2;
    }
//cerr << "OP\n";
    cin >> n >> m >> s >> t;
    n = s.length();
    m = t.length();

    for (int i = 0; i < 26; ++i) {
        vector<int> vs(s.length(), 0);
        for (int j = 0; j < n; ++j)
            if (s[j] == ('a' + i))
                vs[j] = 1;
        hs[i] = MakeHash(vs);
        //cerr << "OP " << i << "\n";
        vs.assign(t.length(), 0);
        for (int j = 0; j < m; ++j)
            if (t[j] == ('a' + i))
                vs[j] = 1;
        ht[i] = MakeHash(vs);
        fl[i] = -1;
      //  cerr << "OP " << i << "\n";
    }


    for (int i = m-1; i >= 0; --i)
        fl[t[i]-'a'] = i;
    //cerr << "PREVED\n";
    vector<int> ans;
    for (int i = 0; i <= n-m; ++i) {
        vector<int> go(26, -1);
        vector<int> kol(26, 0);
        for (int j = 0; j < 26; ++j)
            if (fl[j] >= 0) {
                go[j] = s[i + fl[j]] - 'a';
                kol[go[j]]++;
            }
        bool isOK = true;
        //cerr << "TEST " << i << "\n";

        for (int j = 0; j < 26; ++j) {
          //  cerr << go[j] << ' ';
            if (kol[j] >= 2)
                isOK = false;
            if (go[j] >= 0)
                if (go[go[j]] >= 0 && go[go[j]] != j)
                    isOK = false;
        }
        //cerr << "\n";
        if (!isOK)
            continue;
        //cerr << "TEST " << i << "\n";
        for (int j = 0; j < 26; ++j)
            if (go[j] >= 0) {
                auto p1 = ht[j].getHash(0, m-1);
                auto p2 = hs[go[j]].getHash(i, i+m-1);
                //cerr << "j: " << p1.first << ' ' << p1.second << ' ' << p2.first << ' ' << p2.second << "\n";
                if (ht[j].getHash(0, m-1) != hs[go[j]].getHash(i, i+m-1))
                    isOK = false;
            }
        if (isOK)
            ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < (int)ans.size(); ++i) {
        if (i)
            cout << " ";
        cout << ans[i]+1;
    }
    cout << "\n";
    return 0;
}
