#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>
#include <queue>

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long int64;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = acos(-1);

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

const int MAXN = 120 * 1000;

int num[MAXN], a[MAXN];
bool used_after[MAXN], ans[MAXN];

int main () {
//  ios_base::sync_with_stdio(0);
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);


    int tc;
    scanf ("%d", &tc);

    for (int ti = 0; ti < tc; ++ti) {
        int m, k;
        scanf ("%d%d", &m, &k);
        for (int i = 0; i < k; ++i) {
            scanf ("%d", &num[i]);
        }

        m--;
        int min_bad = -1, t;
        for (int i = 0; i < m; ++i) {
            scanf ("%d%d", &a[i], &t);
            a[i]--;
            if (t == 1 && min_bad == -1) {
                min_bad = i;
            }
        }

        if (min_bad == -1) {
            int pas_un = 0;
            for (int i = 0; i < m; ++i) {
                if (a[i] != -1) {
                    num[a[i]]--;
                } else {
                    pas_un++;
                }
            }

            for (int i = 0; i < k; ++i) {
                printf("%c", (num[i] > pas_un ? 'N' : 'Y'));
            }
            printf("\n");
        } else {
            for (int i = 0; i < k; ++i) {
                used_after[i] = false;
            }
            for (int i = min_bad; i < m; ++i) {
                if (a[i] != -1) {
                    used_after[a[i]] = true;
                }
            }

            int pas_un = 0;
            for (int i = 0; i < min_bad; ++i) {
                if (a[i] != -1) {
                    num[a[i]]--;
                } else {
                    pas_un++;
                }
            }

            for (int i = 0; i < k; ++i) {
                ans[i] = (!used_after[i] && (num[i] <= pas_un));
            }

            int rare_num = inf;
            for (int i = 0; i < k; ++i) {
                if (!used_after[i]) {
                    rare_num = min(num[i], rare_num);
                }
            }
            pas_un -= rare_num;
            for (int i = min_bad; i < m; ++i) {
                if (a[i] != -1) {
                    num[a[i]]--;
                } else {
                    pas_un++;
                }
            }

            for (int i = 0; i < k; ++i) {
                printf("%c", (ans[i] || num[i] <= pas_un ? 'Y' : 'N'));
            }
            printf("\n");
        }
    }

    return 0;
}
