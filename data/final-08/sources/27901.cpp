#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cassert>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;
#define DB(x) { cerr << #x << ": " << x << " "; }
#define forn(i, n)  for (int i = 0; i < (int)(n); ++i)
#define sqr(x) ((x)*(x))
typedef long double ld;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int,int> pii;
const ld PI = acos(-1.0);

const int N = 111;
int n;
double a[N];
int pos[N];

int main() {
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);
  //ios_base::sync_with_stdio(0);

    cin >> n;
    forn(i, n + 1) cin >> a[i];

    double res = 0;
    if (n % 2 == 0) res = a[n/2];


    for (int i = 0; 2 * i < n; i++) {
        for (int j = n; 2 * j > n; j--) {
            int got = n - 2 * i;
            int need = 2 * j - n;
            double val1 = a[i], val2 = a[j];
            res = max(res, (val1 * need + val2 * got) / (got + need));
        }
    }
    cout << fixed << setprecision(12) << res << endl;

  return 0;
}

