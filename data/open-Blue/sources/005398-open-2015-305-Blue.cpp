#define _USE_MATH_DEFINES

#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef int INT;
//#define int ll

typedef pair <int, int> pii;
#define one first
#define two second

#define qfor(i, a, b) for (int i = a; i < int (b); ++i)
#define fori(n) qfor (i, 0, n)
#define forj(n) qfor (j, 0, n)

#define cont(v) v.begin(), v.end()

template <class T>
const T & sqr (const T & x) {
    return x * x;
}

const int INF = 1e9 + 7;
///=============================================

#define MAXN int (1.1e5)

INT main () {
    ios_base::sync_with_stdio(0);
    cin.tie (0);
    cout << fixed << setprecision (15);

    int f;
    cin >> f;

    string s;
    cin >> s;
    int n = s.size();

    if (f >= n) {
        cout << 1 << endl << s;
        return 0;
    }

    qfor (i, 1, f + 1) {
        if (n % i != 0) {
            continue;
        }

        forj (n) {
            if (s[j] != s[j % i]) {
                goto next;
            }
        }

        cout << 1 << endl << s.substr (0, i);
        return 0;

        next:
        {}
    }

    cout << "2\na\nb";
}

