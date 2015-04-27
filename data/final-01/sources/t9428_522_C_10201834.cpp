#include <string>
#include <vector>
#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define all(v) (v).begin(), (v).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpi;
typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;

struct Solver
{
    void readInput() {
        cin >> m >> k;
        a.resize(k);
        for (int i = 0; i < k; ++i) {
            cin >> a[i];
        }
        t.resize(m - 1);
        r.resize(m - 1);
        for (int i = 0; i < m - 1; ++i) {
            cin >> t[i] >> r[i];
        }
    }

    string solve() {
        string answer;

        int firstUnhappy = -1;
        int unsure = 0;
        int unsureOnFirstUnhappy = -1;

        set<int> canBeFirstZero;

        for (int i = 0; i < m - 1; ++i) {
            if (r[i] == 1) {
                firstUnhappy = i;
                unsureOnFirstUnhappy = unsure;
                for (int i = 0; i < k; ++i) {
                    if (a[i] <= unsure) {
                        canBeFirstZero.insert(i);
                    }
                }
                break;
            } else {
                if (t[i] != 0) {
                    --a[t[i] - 1];
                } else {
                    ++unsure;
                }
            }
        }

        if (firstUnhappy == -1) {
            // No unhappy
            for (int i = 0; i < k; ++i) {
                if (a[i] <= unsure) {
                    answer += 'Y';
                } else {
                    answer += 'N';
                }
            }
            return answer;
        } else {
            for (int i = firstUnhappy; i < m - 1; ++i) {
                if (t[i] != 0) {
                    int dish = t[i] - 1;
                    canBeFirstZero.erase(dish);
                    --a[dish];
                } else {
                   ++unsure;
                }
            }
        }

        assert(!canBeFirstZero.empty());

        int minA = 1e9;
        int minDish = -1;
        for (int dish : canBeFirstZero) {
            if (a[dish] < minA) {
                minA = a[dish];
                minDish = dish;
            }
        }

        assert(unsure >= minA);
        unsure -= minA;
        a[minDish] -= minA;

        for (int i = 0; i < k; ++i) {
            if ((a[i] <= unsure) || (canBeFirstZero.find(i) != canBeFirstZero.end())) {
                answer += 'Y';
            } else {
                answer += 'N';
            }
        }

        return answer;
    }

    int m, k;
    vector<int> a;
    vector<int> t;
    vector<int> r;
};

int main()
{
    ios::sync_with_stdio(false);
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        Solver solver;
        solver.readInput();
        auto answer = solver.solve();
        cout << answer << endl;
    }
    return 0;
}

