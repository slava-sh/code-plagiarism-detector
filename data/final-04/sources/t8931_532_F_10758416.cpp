#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cstdlib>
#define y0 trololoy0
#define y1 trololoy1


using namespace std;

const int N = 211111;
const int INF = (int)1e9;
const long long P1 = 31;
const long long P2 = 59;
const int L = 26;

int n, m, cnt[L];
char s[N], t[N];
long long p1[N], p2[N], hashes1[L], hashes2[L], mask_hash1[L], mask_hash2[L];
vector<int> ans;

void update(int i) {
    hashes1[s[i]] += p1[i];
    hashes2[s[i]] += p2[i];
}

void remove(int i) {
    hashes1[s[i]] -= p1[i];
    hashes2[s[i]] -= p2[i];
}

void update_hashes() {
    for (int i = 0; i < L; ++i) {
        mask_hash1[i] *= P1;
        mask_hash2[i] *= P2;
    }
}

bool check() {
    for (int i = 0; i < L; ++i) {
        if (!cnt[i]) {
            continue;
        }
        bool found = false;
        for (int j = 0; j < L && !found; ++j) {
            if (mask_hash1[i] == hashes1[j] && mask_hash2[i] == hashes2[j]) {
                found = true;
                if (mask_hash1[j] != hashes1[i] || mask_hash2[j] != hashes2[i]) {
                    return false;
                }
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

void init() {
    p1[0] = p2[0] = 1;
    for (int i = 1; i <= n; ++i) {
        p1[i] = p1[i - 1] * P1;
        p2[i] = p2[i - 1] * P2;
    }
    for (int i = 0; i < n; ++i) {
        s[i] -= 'a';
    }
    for (int j = 0; j < m; ++j) {
        t[j] -= 'a';
        ++cnt[t[j]];
        mask_hash1[t[j]] += p1[j];
        mask_hash2[t[j]] += p2[j];
    }
    for (int i = 0; i < m; ++i) {
        update(i);
    }
    if (check()) {
        ans.push_back(0);
    }
}

int main() {
    scanf("%d %d\n", &n, &m);
    gets(s);
    gets(t);
    if (m > n) {
        puts("0");
        return 0;
    }
    init();
    for (int i = m; i < n; ++i) {
        update(i);
        remove(i - m);
        update_hashes();
        if (check()) {
            ans.push_back(i - m + 1);
        }
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d ", ans[i] + 1);
    }
    puts("");
    return 0;
}
