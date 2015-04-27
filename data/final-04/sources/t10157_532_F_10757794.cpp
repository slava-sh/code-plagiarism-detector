#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>
#include <set>
//#include <memory>
//#include <thread>
using namespace std;


#define INF 1e+9
#define mp make_pair
#define lint long long
#define pii pair<int, int>
#define MAXN 300000
#define HBASE 1000000007


struct hashqueue{
    int delb = 0;
    lint powH = 1;
    lint lowH = 1;
    int curr = 0;
    set<pair<int, char> > latest;  
    lint hashes[255];
    int pos[255];
    int cnt[255];
    vector<char> corder;
    hashqueue() {
        memset(pos, -1, sizeof pos);
        memset(hashes, 0, sizeof hashes);
        memset(cnt, 0, sizeof cnt);
    }
    void delc(char c) {
        cnt[c]--;
        if (cnt[c] == 0) {
            latest.erase(mp(pos[c], c));
            pos[c] = -1;
        }
        hashes[c] -= lowH;
        delb++;
        lowH *= HBASE;
    }
    pair<int, lint> getHash() {
        lint ans = 0;
        int cc = 1;
        corder.clear();
        for (auto i = latest.begin(); i != latest.end(); i++) {
            corder.push_back(i->second);
            ans += hashes[i->second] * (cc++);
        }
        return mp(delb, ans);
    }
    void addc(char c) {
        latest.erase(mp(pos[c], c));
        pos[c] = curr++;
        latest.insert(mp(pos[c], c));
        hashes[c] += powH;
        powH = powH * HBASE;
        cnt[c]++;
    }
};

string s, t;

lint prec[MAXN];

bool cmp(pair<int, lint> a, pair<int, lint> b) {
    return prec[MAXN - 1 - a.first] * a.second == prec[MAXN - 1 - b.first] * b.second;
}

char cmap[255];

int main() {
    ios_base::sync_with_stdio(false);
    prec[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        prec[i] = prec[i - 1] * HBASE;
    }
    int nn, n;
    cin >> nn >> n;
    cin >> s >> t;
    hashqueue q, qe;
    for (int i = 0; i < n; i++) {
        qe.addc(t[i]);
    }
    auto h1 = qe.getHash();
    for (int i = 0; i < n; i++) {
        q.addc(s[i]);
    }
    vector<int> ans;
    for (int i = 0; i <= ((int)s.length()) - n; i++) {
        if (cmp(h1, q.getHash()) && q.corder.size() == qe.corder.size()) {
            memset(cmap, -1, sizeof cmap);
            for (int i = 0; i < q.corder.size(); i++) {
                cmap[q.corder[i]] = qe.corder[i];
            }
            bool toadd = true;
            for (int i = 0; i < 255; i++) {
                if (cmap[i] != -1) {
                    if (cmap[cmap[i]] != -1 && cmap[cmap[i]] != i) toadd = false;
                }
            }
            if (toadd)
                ans.push_back(i);
        }
        q.delc(s[i]);
        if (i + n < s.length())
            q.addc(s[i + n]);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << " " << ans[i] + 1;
    }
}
