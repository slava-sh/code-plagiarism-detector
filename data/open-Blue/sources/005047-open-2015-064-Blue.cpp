#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

template<class T> T nextInt() {
    T x = 0, p = 1;
    char c;
    do {
        c = getchar();
    } while (c <= 32);
    if (c == '-') {
        p = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * p;
}

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<int> z_foo(string s) {
    vector<int> z(s.size());
    z[0] = (int)s.size();
    int l = 0, r = 0;
    for (int i = 1; i < (int)s.size(); i++) {
        if (i <= r)
            z[i] = min(z[i - l], r - i + 1);
        while (i + z[i] < (int)s.size() && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) {
            l = i, r = i + z[i] - 1;
        }
    }
    return z;
}

int L;
string s;

void check1() {
    vector<int> z = z_foo(s);
    if ((int)s.size() <= L) {
        cout << "1\n" << s << "\n";
        exit(0);
    }
    for (int i = 1; i <= L; i++)
        if (((int)s.size() % i == 0) && i + z[i] == (int)s.size()) {
            cout << "1\n" << s.substr(0, i);
            exit(0);
        }
}

const int maxn = 20005;
bool can[maxn];

void check2() {
    for (char c = 'a'; c <= 'c'; c++) {
        if (s.find(c) == string::npos) {
            cout << "2\n";
            for (char cc = 'a'; cc <= 'c'; cc++)
                if (cc != c) cout << cc << "\n";
            exit(0);
        }
    }
    int n = s.size();
    vector<int> z = z_foo(s);
    for (int pref = 1; pref <= L; pref++) {
        int xx = -1;
        for (int x = 1; x <= pref; x++)
            if (pref % x == 0 && z[x] + x >= pref) {
                xx = x;
                break;
            }
        vector<int> z2 = z_foo(s.substr(pref, n - pref));
        for (int y = 1; y <= L && pref + y <= n; y++) {
            for (int i = pref + y; i <= n; i++)
                can[i] = false;
            can[pref + y] = true;
            for (int i = pref + y; i < n; i++) {
                if (can[i]) {
                    if (z[i] >= xx) {
                        can[i + xx] = true;
                    }
                    if (z2[i - pref] >= y) {
                        can[i + y] = true;
                    }
                }
            }
            if (can[n]) {
                cout << "2\n" << s.substr(0, xx) << " " << s.substr(pref, y) << "\n";
                exit(0);
            }
        }
    }
}

void check3() {
    cout << "3\na\nb\nc\n";
}

int main()
{
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);

    cin >> L >> s;

    check1();
    check2();
    check3();

    return 0;
}
