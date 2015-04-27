#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

#define forn(i, n) for (int i = 0; i < (n); ++i)

typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

const int N = 111;
const ll H = 100;
const ll W = 100 * 1000;
const ld EPS = 1e-7;
ll n, h1, h2;
ll score[N], a[N], b[N], type[N];

ll solve(int runid) {
  ll res = 0;

  forn(floor, n + 1) {
    ll cur = 0;
    ll start = h1, end = (floor & 1) ? H - h2 : h2;
    end += floor * H;

    vector<bool> used(n, 0);

    forn(i, floor) {
      ld h = ((i + 1) * H - start);
      ld x = 1.0 * W / (end - start) * h;

      bool done = 0;
      forn(j, n) {
        if (used[j])
          continue;

        if (a[j] > x + EPS || b[j] < x - EPS)
          continue;

        if ((i & 1) == type[j])
          continue;

        used[j] = 1;
        done = 1;
        cur += score[j];
      }

      if (!done)
        cur -= 1e15;

      // cerr << i << " " << h << " " << x << " cur " << cur << endl;
    }

    // cerr << endl << runid << " " << floor << " " << cur << endl << "--------------------------" << endl;
    res = max(res, cur);
  }

  return res;
}

int main() {
  // freopen("in", "r", stdin);
  ios_base::sync_with_stdio(0);

  cin >> h1 >> h2 >> n;
  forn(i, n) {
    cin >> score[i];
    char ch;
    cin >> ch;
    type[i] = (ch == 'T');
    cin >> a[i] >> b[i];
  }

  if (h1 > h2) {
    h1 = H - h1;
    h2 = H - h2;
    forn(i, n) {
      type[i] ^= 1;
    }
  }

  ll res1 = solve(0);

  ll res2 = 0;

  h1 = H - h1;
  h2 = H - h2;
  forn(i, n) {
    type[i] ^= 1;
  }

  res2 = solve(1);
  
  cout << max(res1, res2) << endl;
}
