#pragma comment(linker, "/STACK:100000000")
#include <stdio.h>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
using namespace std;

#define N 200005

struct pt {
    int x;
    int y;
};
pt a[N], b[N];

typedef long long ll;

int i, j, k, n, m;
int x, y, z, t;

int pr(pt a, pt b) {
    return a.x < b.x;
}

void dfs(int bg, int en) {
    if (bg == en) {
        b[m++] = a[bg];
        return;
    }
    if (bg > en) {
        return;
    }
    int i, c;
    set<int> s;
    c = (bg + en) / 2;
    for (i = bg; i <= en; i ++) {
        s.insert(a[i].y);
    }
    for (set<int>::iterator it = s.begin(); it != s.end() ;it ++) {
        b[m].x = a[c].x;
        b[m].y = *it;
        m ++;
    }
    for (i = c; i <= en; i ++) {
        if (a[i].x != a[c].x) {
            break;
        }
    }
    dfs(i, en);
    for (i = c; i >= bg; i --) {
        if (a[i].x != a[c].x) {
            break;
        }
    }
    dfs(bg, i);
}


int main() {
    cin >> n;
    for (i = 0; i < n; i ++) {
        cin >> a[i].x;
        cin >> a[i].y;
    }
    sort(a, a + n, pr);

    dfs(0, n - 1);
    cout << m << endl;
    for (i = 0; i < m; i ++) {
        cout << b[i].x << ' ' << b[i].y << endl;
    }
    return 0;
}
