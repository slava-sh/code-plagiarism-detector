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
inline T sqr (const T & x) {
    return x * x;
}

const ld EPS = 1e-9L;
const int INF = 1e9L + 7;
const ll BIGINF = 2e18L;

inline bool equal (ld a, ld b) {
    return abs (a - b) < EPS;
}
///=============================================

const int MAXN = int (1e5);


INT main () {
    ios_base::sync_with_stdio(0);

    char next_c[300];
    next_c[int ('U')] = 'R';
    next_c[int ('R')] = 'D';
    next_c[int ('D')] = 'L';
    next_c[int ('L')] = 'U';

    char ans = 'N';

    int cur_len = 1;
    int more = 1;
    char cur_c = 'U';

    int cnt = 0;

    do {
        ++cnt;
        if (cnt == int (2e5 - 1)) {
            return 2;
        }

        if (ans == 'Y' || ans == 'E') {
            return 0;
        }

        cout << cur_c << endl;

        --more;

        if (!more) {
            if (cur_c == 'R' || cur_c == 'L') {
                ++cur_len;
            }
            cur_c = next_c[int (cur_c)];
            more = cur_len;
        }


    } while (cin >> ans);

}

