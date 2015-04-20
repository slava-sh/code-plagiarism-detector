#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define ll long long
#define pb push_back
#define in(s) freopen(s, "r", stdin)
#define out(s) freopen(s, "w", stdout)

vector <int> v[110];
pair<int, int> a[110];
string s; int n, fp, sp, tp;

int toInt(int l, int r) {
    int k = 0;
    for(; l < r; l++)
        k = k * 10 + s[l] - 48;
    return k;
}

void print() {
    int i, d = 11;
    cout << '+';
    for(i = 0; i < fp; i++)
        cout << s[i];
    cout << '(';
    for(i = fp; i < fp + sp; i++)
        cout << s[i];
    cout << ')';
    i = fp + sp;
    while(d > fp + sp) {
        if((d - fp - sp) % 2 == 1)
            cout << s[i] << s[i + 1] << s[i + 2], i += 3;
        else
            cout << s[i] << s[i + 1], i += 2;
        d -= (2 + (d - fp - sp) % 2);
        if(d > fp + sp)
            cout << '-';
    }
    cout << "\n";
}

bool solve1(int pr, int i, int x) {
    if(s[x] == '0')
        return 0;
    int l = 0, r = v[i].size() - 1, m;
    while(l < r) {
        m = (l + r) >> 1;
        if(v[i][m] < pr)
            l = m + 1;
        else
            r = m;
    }

    if(v[i][l] == pr) {
        print();
        return 1;
    }
    return 0;
}

bool solve(int pr, int i) {
    fp = i;
    if(s[i] == '0')
        return 0;
    int l = 1, r = n, m;
    while(l < r) {
        m = (l + r) >> 1;
        if(a[m].fi < pr)
            l = m + 1;
        else
            r = m;
    }
    if(a[l].fi != pr)
        return 0;
    sp = 3;
    if(solve1(toInt(i, i + 3), a[l].se, i + 3))
        return true;
    sp = 4;
    if(solve1(toInt(i, i + 4), a[l].se, i + 4))
        return true;
    sp = 5;
    if(solve1(toInt(i, i + 5), a[l].se, i + 5))
        return true;
    return false;
}


int main() {
    in("numbers.in");
    out("numbers.out");

    int m, i, j, c, k, x;
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> a[i].fi >> k;
        a[i].se = i;
        for(; k > 0 && cin >> x; k--)
            v[i].pb(x);
        sort(v[i].begin(), v[i].end());
    }
    sort(a + 1, a + 1 + n);
    cin >> m;
    for(; m > 0; m--) {
        cin >> s;
        if(s[0] == '0')
            cout << "Incorrect\n";
        else if(solve(toInt(0, 1), 1));
        else if(solve(toInt(0, 2), 2));
        else if(solve(toInt(0, 3), 3));
        else
            cout << "Incorrect\n";
    }

}
