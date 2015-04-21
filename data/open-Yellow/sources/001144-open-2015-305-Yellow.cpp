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


    int n;
    cin >> n;

    static int a[MAXN];
    int res = 1;
    fori (n) {
        cin >> a[i];
        if (i && a[i] != a[i - 1]) {
            ++res;
        }
    }

    int q;
    cin >> q;

    fori (q) {
        int x, y;
        cin >> x >> y;

        --x;

        if (y == a[x]) {
            cout << res << endl;
            continue;
        }


       /* cerr << x << " " << y << " " << a[x - 1] << " " << a[x] << " " << a[x + 1] << endl;
        forj (n) {
            cerr << a[j] << " ";
        }
        cerr << endl;*/

        if (x == 0) {
            if (a[1] == a[0]) {
                ++res;
            } else if (y == a[1]) {
                --res;
            }
        } else if (x == n - 1) {
            if (a[n - 2] == a[n - 1]) {
                ++res;
            } else if (y == a[n - 2]) {
                --res;
            }
        } else {
            if (a[x - 1] == a[x + 1]) {
                if (a[x] == a[x - 1]) {
                    res += 2;
                } else {
                    if (y == a[x - 1]) {
                        res -= 2;
                    }
                }

            } else if (a[x - 1] == a[x] || a[x + 1] == a[x]){
                if (y != a[x + 1] && y != a[x - 1]) {
                    res += 2;
                }
            } else {
                if (y == a[x - 1] || y == a[x + 1]) {
                    --res;
                }
            }
        }

        a[x] = y;

        cout << res << endl;
    }
}

