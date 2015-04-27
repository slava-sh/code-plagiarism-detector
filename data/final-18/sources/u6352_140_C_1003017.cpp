#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <cassert>
#include <ctime>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<ll> vll;
typedef vector<vll> vvll;

#define TASKNAME "text"
#define pb push_back
#define mp make_pair
#define EPS (1E-9)
#define INF ((int)1E9)
#define sqr(x) ((x) * (x))

int main() {
    #ifdef DEBUG
        freopen(TASKNAME".in", "r", stdin);
        freopen(TASKNAME".out", "w", stdout);
    #endif
    
    int n;
    while(scanf("%d", &n) >= 1) {
        vi a(n, 0);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a.begin(), a.end());
        vector<pii> rs;
        int cnt = 0;
        for (int i = 0; i < n;) {
            int i0 = i;
            while (i < n && a[i] == a[i0])    
                i++;
            rs.pb(mp(i - i0, a[i0]));
            cnt++;
        }

        if (cnt < 3) {
            printf("0\n");
            continue;
        }

        set<pii> s;
        for (int i = 0; i < cnt; i++)
            s.insert(rs[i]);
        int ans;
        set<pii>::iterator iter;
        vvi res;

        for (ans = 0; ans < n / 3; ans++) {
            iter = s.end();
            iter--;
            pii p1 = *iter;
            iter--;
            pii p2 = *iter;
            iter--;
            pii p3 = *iter;
            if (!p3.first)
                break;
            for (int i = 0; i < 3; i++) {
                iter = s.end();
                iter--;
                s.erase(iter);
            }
            p1.first--;
            p2.first--;
            p3.first--;
            s.insert(p1);
            s.insert(p2);
            s.insert(p3);
            res.pb(vi(3));
            res[ans][0] = p1.second;
            res[ans][1] = p2.second;
            res[ans][2] = p3.second;
            sort(res[ans].begin(), res[ans].end());
        }

        printf("%d\n", ans);
        for (int i = 0; i < ans; i++)
            for (int j = 2; j >= 0; j--)
                printf("%d%c", res[i][j], " \n"[!j]);
    }   
    return 0;
}
