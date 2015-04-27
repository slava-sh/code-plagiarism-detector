#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <memory.h>

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>

#define NAME "test"

#define EPS (1e-9)
#define INF ((int)(1e+9))
#define LINF ((long long)(1e+18))

#define ve vector<int>
#define pb push_back

#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define fs first
#define sc second

using namespace std;

typedef long long li;
typedef long long ll;
typedef long long lint;

void solve(int test_number);

int main() {
#ifdef _GEANY
    freopen(NAME ".in", "r", stdin);
    freopen(NAME ".out", "w", stdout);
#else
#endif
    cout.setf(ios::fixed);
    cout.precision(9);
    cerr.setf(ios::fixed);
    cerr.precision(3);
    int n = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        solve(i + 1);
    }
    return 0;
}

const int MAXN = 100100;

int n, m;
int a[MAXN];
int t[MAXN];
int r[MAXN];
int first[MAXN];
int last_entry[MAXN];
int cnt_entries[MAXN];
bool bad[MAXN];
int cnt_entries_before_death[MAXN];

void solve(int test_number) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &t[i], &r[i]);
    }

    for (int i = 0; i < m; i++) {
        first[i] = -1;
        last_entry[i] = -1;
        cnt_entries[i] = 0;
        cnt_entries_before_death[i] = 0;
        bad[i] = false;
    }
    int first_death = -1;
    int free_cells = 0;
    for (int i = 0; i < n - 1; i++) {
        if (t[i] != 0) {
            last_entry[t[i] - 1] = i;
            cnt_entries[t[i] - 1]++;
        } else
            free_cells++;
        if (r[i] == 1 && first_death == -1) {
            first_death = i;
        }
    }

    if (first_death == -1) {
        for (int i = 0; i < m; i++)
            if (cnt_entries[i] + free_cells >= a[i]) {
                printf("Y");
            } else {
                printf("N");
            }
        printf("\n");
    } else {
        for (int i = 0; i < m; i++)
            if (last_entry[i] >= first_death)
                bad[i] = true;
        int free_before_death = 0;
        for (int i = 0; i < first_death; i++)
            if (t[i] == 0)
                free_before_death++;
            else
                cnt_entries_before_death[t[i] - 1]++;
        int free_after_death = free_cells - free_before_death;

        for (int i = 0; i < m; i++)
            if (!bad[i] && free_before_death + cnt_entries_before_death[i] >= a[i]) {
                int rem = a[i] - cnt_entries_before_death[i];
                if (rem <= 0)
                    first[i] = free_before_death + free_after_death;
                else
                    first[i] = free_before_death - rem + free_after_death;
            } else
                bad[i] = true;
        
        int best = -1;
        for (int i = 0; i < m; i++) {
            if (!bad[i]) {
                if (best == -1 || first[best] < first[i])
                    best = i;
            }
        }

        for (int i = 0; i < m; i++) {
            if (!bad[i] || a[i] <= first[best] + cnt_entries[i])
                printf("Y");
            else
                printf("N");
        }
        printf("\n");
    }
}

