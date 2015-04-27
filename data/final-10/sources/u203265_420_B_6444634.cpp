#include <vector>
#include<cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <deque>
#include <set>
#ifdef __GXX_EXPERIMENTAL_CXX0X__
#include <unordered_map>
#include <cassert>
#endif
#include <ctime>
#include <queue>
#include <stack>
#include<iomanip>
#include <sstream>
#include <cmath>
using namespace std;
typedef pair<int, int> PII;
typedef long long ll;
void solve(int ncase) {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> mark(n + 1, 0);
    set<int> early_comer;
    vector<PII> log;
    for(int i = 0; i < m; i ++) {
        char s[2];
        int id;
        scanf("%s %d", s, &id);
        if (s[0] == '+') {
            log.push_back(PII(1, id));
            mark[id] ++;
        } else {
            log.push_back(PII(0, id));
            if (mark[id] % 2 == 0) {
                early_comer.insert(id);
                mark[id] ++;
            }
            mark[id] ++;
        }
    }
    vector<int> ban(n + 1, 0);
    //vector<int> vst(n + 1, 0);
    int cnt = early_comer.size();
    set<int> maybe;
    //cout <<"test" << cnt  << endl;
    for(int i = 0; i < m; i ++) {
        if (log[i].first == 1 && cnt == 0) {
            maybe.insert(log[i].second);
        }
        if (log[i].first == 0 && cnt == 1) {
            maybe.insert(log[i].second);
        }
        if (log[i].first == 1 && cnt > 0 ||
            log[i].first == 0 && cnt > 1) {
            ban[log[i].second] = 1;
            //cout << "ban = " <<
        }
        //cout << "cnt = " << cnt << endl;
        cnt += log[i].first ? 1 : -1;
    }
    if (maybe.size() > 1) {
        for(auto i : maybe) ban[i] = 1;
    }
    vector<int> ans;
    for(int i = 1; i <= n; i ++) {
        if (!ban[i]) {
            ans.push_back(i);
        }
    }
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i ++) {
        printf("%d%c", ans[i], (i < ans.size() - 1 ? ' ' : '\n'));
    }
}
int main() {
    ios::sync_with_stdio(false);
    //cout << setprecision(16) << endl;
#ifdef _zzz_
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T = 1;
    //cin >> T;
    int ncase = 0;
    while(T --) {
        solve(++ ncase);
    }
}
