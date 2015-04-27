#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define forn(i, n) for(int i = 0; i < (n); ++i)
#define mp make_pair
#define pb push_back
#define debug(x) cerr << "DEBUG: " << #x << " = " << x << endl

template<typename T> inline void mx(T& x, const T& y) { if (x < y) x = y; }
template<typename T> inline void mn(T& x, const T& y) { if (y < x) x = y; }
template<typename T> inline int sz(const T& x) { return (int) x.size(); }


int main() {
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t-- > 0) {
        int m, k;
        cin >> m >> k;
        vector<int> a(k);
        forn (i, k) {
            cin >> a[i];
        }        

        vector<vector<int> > whenEat(k);
        vector<int> eatSomething(m, 0);
        int firstEnded = - 1;
        forn (i, m - 1) {
            int t, r;
            cin >> t >> r;
            if (t == 0) {
                eatSomething[i + 1]++;
                if (r == 1 && firstEnded == -1) {
                    firstEnded = i;
                }
            } else {
                t--;
                if (r == 1 && firstEnded == -1) {
                    firstEnded = i;
                }
                whenEat[t].pb(i);
            }
        }

        for (int i = 1; i < m; ++i) {
            eatSomething[i] += eatSomething[i - 1];
        }
        string ans;
        forn (i, k) {
            ans += 'N';
        }
        int fixed;
        if (firstEnded != - 1) {
            fixed = m - 1;
            forn (i, k) {
                if (whenEat[i].empty() || whenEat[i].back() < firstEnded) {
                    int l = (whenEat[i].empty() ? 0 : whenEat[i].back() + 1);
                    int r = firstEnded - 1;
                    int unknown = eatSomething[r + 1]; // - eatSomething[l];
                    if (sz(whenEat[i]) + unknown >= a[i]) {
                        ans[i] = 'Y';
                        mn(fixed, a[i] - sz(whenEat[i]));
                    }
                }
            }
        } else {
            fixed = 0;
        }
        forn (i, k) {
            if (a[i] - sz(whenEat[i]) <= eatSomething.back() - fixed) {
                ans[i] = 'Y';
            }
        }
        cout << ans << endl;
    }
    return 0;
}
