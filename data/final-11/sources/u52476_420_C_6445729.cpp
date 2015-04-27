#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

#define FILE freopen("../data.in","r",stdin)
#define REP(i,n) for(int i=0; i<(n); i++)
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin(); it!=(a).end(); it++)

const int N = 300010;

int c[N];
int cnt[N];
multiset<int> st[N];

void add(int p, int d) {
    p = N - p - 1;
    for (int i = p; i < N; i += i & -i)
        c[i] += d;
}

int sum(int p) {
    p = N - p - 1;
    int s = 0;
    for (int i = p; i; i -= i & -i)
        s += c[i];
    return s;
}

int main() {
//FILE;
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--; y--;
        if (x > y)
            swap(x, y);
        st[x].insert(y);
        st[y].insert(x);
        cnt[x]++;
        cnt[y]++;
    }
    if (m == 0) {
        LL ans = (LL)n * (n - 1) / 2;
        cout << ans << endl;
        return 0;
    }
    for (int i = 0; i < n; i++)
        add(cnt[i], 1);

    LL ans = 0;
    for (int x = 0; x < n; x++) {
        if (cnt[x] >= m) {
            ans += n - 1;
            continue;
        }

        foreach(it, st[x]) {
            add(cnt[*it], -1);
            cnt[*it]--;
            add(cnt[*it], 1);
        }

        ans += sum(m - cnt[x]);
        if (cnt[x] + cnt[x] >= m)
            ans--;

        foreach(it, st[x]) {
            add(cnt[*it], -1);
            cnt[*it]++;
            add(cnt[*it], 1);
        }
    }
    cout << ans / 2 << endl;
    return 0;
}
