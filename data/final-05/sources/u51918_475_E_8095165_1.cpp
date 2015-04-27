#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define iii int
#define fff for

const iii DDEEEW = 2005;

iii dw281, sj22;

vector<iii> sk3822[DDEEEW];

bool fe27191161[DDEEEW];
iii kd332[DDEEEW], dlw2822[DDEEEW], de2lws[DDEEEW];

vector<iii> ooso;
vector<vector<iii> > dewww;

iii sksss_Ss__Ss[DDEEEW];

void dfs(iii u) {
    fe27191161[u] = true;
    de2lws[u] = dlw2822[u];
    ooso.push_back(u);
    fff (iii _ss = 0; _ss < (iii)sk3822[u].size(); ++_ss) {
        iii v = sk3822[u][_ss];
        if (fe27191161[v]) {
            if (dlw2822[v] < dlw2822[u] - 1) {
                de2lws[u] = min(de2lws[u], dlw2822[v]);
            }
        } else {
            dlw2822[v] = dlw2822[u] + 1;
            dfs(v);
            de2lws[u] = min(de2lws[u], de2lws[v]);
        }
    }
    if (de2lws[u] == dlw2822[u]) {
        vector<iii> tmp;
        do {
            tmp.push_back(ooso.back());
            ooso.pop_back();
        } while (tmp.back() != u);
        dewww.push_back(tmp);
    }
}

vector<iii> edge2[DDEEEW], ch[DDEEEW];

iii size[DDEEEW], all;

vector<iii> ord2;

void dfs2(iii u, iii fa) {
    fff (iii _ss = 0; _ss < (iii)edge2[u].size(); ++_ss) {
        iii v = edge2[u][_ss];
        if (v == fa) {
            continue;
        }
        dfs2(v, u);
        ch[u].push_back(size[v]);
        size[u] += size[v];
        sksss_Ss__Ss[u] += sksss_Ss__Ss[v] + size[v] * dewww[u].size();
    } 
}

bool dp[2][DDEEEW];

iii solve(iii u) {
    iii ret = 0;
    dewww.clear();
    dfs(u);
    fff (iii _ss = 0; _ss < (iii)dewww.size(); ++_ss) {
        fff (iii j = 0; j < (iii)dewww[_ss].size(); ++j) {
            iii u = dewww[_ss][j];
            kd332[u] = _ss;
        }
        ret += dewww[_ss].size() * dewww[_ss].size();
    }
    iii sj22 = dewww.size();
    if (sj22 == 1) {
        return ret;
    }
    all = 0;
    fff (iii _ss = 0; _ss < sj22; ++_ss) {
        edge2[_ss].clear();
        fff (iii j = 0; j < (iii)dewww[_ss].size(); ++j) {
            iii u = dewww[_ss][j];
            fff (iii k = 0; k < (iii)sk3822[u].size(); ++k) {
                iii v = sk3822[u][k];
                if (kd332[u] != kd332[v]) {
                    edge2[kd332[u]].push_back(kd332[v]);
                }
            }
        }
        ch[_ss].clear();
        sort(edge2[_ss].begin(), edge2[_ss].end());
        edge2[_ss].erase(unique(edge2[_ss].begin(), edge2[_ss].end()), edge2[_ss].end());
        size[_ss] = dewww[_ss].size();
        all += size[_ss];
    }
    iii best = 0;
    fff (iii _ss = 0; _ss < sj22; ++_ss) {
        fff (iii j = 0; j < sj22; ++j) {
            size[j] = dewww[j].size();
            sksss_Ss__Ss[j] = 0;
            ch[j].clear();
        }
        dfs2(_ss, -1);
        iii tmp = 0;
        vector<iii> &s = ch[_ss]; 
        iii cur = dewww[_ss].size();
        sort(s.begin(), s.end());
        if (s.back() >= all - cur - s.back()) {
            iii in = s.back(), out = all - cur - in;
            tmp = in * out;
        } else {
            memset(dp[0], 0, sizeof(bool) * (all + 1));
            iii now = 0, sum = 0;
            dp[now][0] = true;
            fff (iii j = 0; j < (iii)s.size(); ++j) {
                iii delta = s[j], next = now ^ 1;
                memset(dp[next], 0, sizeof(bool) * (sum + delta + 1));
                fff (iii k = 0; k <= sum; ++k) {
                    if (dp[now][k]) {
                        dp[next][k + delta] = dp[next][abs(k - delta)] = true;
                    }
                }
                now = next;
                sum += delta;
            }
            fff (iii j = 0; j <= sum; ++j) {
                if (dp[now][j]) {
                    iii in = (all - cur + j) / 2, out = (all - cur - j) / 2;
                    tmp = max(tmp, in * out);
                }
            }
        }
        best = max(best, tmp + sksss_Ss__Ss[_ss]);
    }
    return ret + best;
}

iii main() {
    scanf("%d%d", &dw281, &sj22);
    fff (iii _ss = 0; _ss < sj22; ++_ss) {
        iii u, v;
        scanf("%d%d", &u, &v);
        --u, --v;
        sk3822[u].push_back(v);
        sk3822[v].push_back(u);
    }
    iii ans = 0;
    fff (iii _ss = 0; _ss < dw281; ++_ss) {
        if (!fe27191161[_ss]) {
            ans += solve(_ss);
        }
    }
    printf("%d\n", ans);
    return 0;
}
