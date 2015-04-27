#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <utility>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>


using namespace std;

typedef unsigned long long LL;
template<class T> inline T Abs(const T& x) { return x < 0 ? -x : x; }
template<class T> inline T Sqr(const T& x) { return x * x; }


const int maxn = 4 * 101 * 1000;
const int alpha = 26;



inline LL GetHash(LL* h, LL* p, int pos, int len) {
    if (len == 0) {
        return 0;
    } else {
        return h[pos] - h[pos + len] * p[len];
    }
}


const LL P = 1543;
LL hs[alpha][maxn], ht[alpha][maxn];
LL p[maxn];
char s[maxn];
char t[maxn];
int ne[alpha][maxn];
int n, m;



int main() {
    scanf("%d%d", &n, &m);
    scanf("%s", s);
    scanf("%s", t);

    p[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        p[i] = p[i-1] * P;
    }

    for (int ch = 0; ch < 26; ++ch) {
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == 'a' + ch) {
                hs[ch][i] = hs[ch][i + 1] * P + 1;
            } else {
                hs[ch][i] = hs[ch][i + 1] * P;
            }
        }
    }
    for (int ch = 0; ch < 26; ++ch) {
        for (int i = m - 1; i >= 0; --i) {
            if (t[i] == 'a' + ch) {
                ht[ch][i] = ht[ch][i + 1] * P + 1;
            } else {
                ht[ch][i] = ht[ch][i + 1] * P;
            }
        }
    }

    for (int i = n; i >= 0; --i) {
        for (int j = 0; j < alpha; ++j) {
            ne[j][i] = n;
            if (i < n && ne[j][i + 1] < n) {
                ne[j][i] = ne[j][i + 1];
            }
            if (i < n && s[i] == 'a' + j) {
                ne[j][i] = i;
            }
        }
    }

    vector<int> ans;
    for (int i = 0; i + m <= n; ++i) {
        bool can = true;
        vector<int> use(alpha, -1);
        for (int j = 0; j < alpha; ++j) {
            if (ne[j][i] < i + m) {
                use[j] = t[ne[j][i] - i] - 'a';
                if (use[use[j]] == -1) {
                    use[use[j]] = j;
                } else if (use[use[j]] != j) {
                    can = false;
                }
            }
        }
        if (!can) {
            continue;
        }
        for (int j = 0; j < alpha; ++j) {
            if (use[j] != -1 && use[j] != j && use[use[j]] != j) {
                can = false;
                break;
            }
        }
        if (!can) {
            continue;
        }

        for (int j = 0; j < alpha; ++j) {
            if (use[j] != -1) {
                if (GetHash(hs[j], p, i, m) != GetHash(ht[use[j]], p, 0, m)) {
                    can = false;
                    break;
                }
            }
        }
        if (can) {
            ans.push_back(i + 1);
        }
    }
    printf("%d\n", int(ans.size()));
    for (size_t i = 0; i < int(ans.size()); ++i) {
        printf("%d ", ans[i]);
    }
    printf("\n");



    return 0;
}


