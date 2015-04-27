/*
 * Template for code jam - different includes and templates
 * Real task code is in the end
 * Mikhail Dektyarow <mihail.dektyarow@gmail.com>, 2009
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <sstream>
#include <numeric>
#include <stack>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;

/*
 * DEFINES
 */
#define FOR(i, a, b) for (int i(a), _b(b); i <= _b; ++i)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define REP(i, n) for (int i(0), _n(n); i < _n; ++i)
#define REPD(i, n) for (int i((n)-1); i >= 0; --i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(X) ((int)(X.size()))
#define LENGTH(X) ((int)(X.length()))

/*
 * Types
 */
typedef pair<int,int> ipair;
typedef long long int int64;
typedef unsigned long long uint64;

/*
 * Different useful templates
 */
template<typename T> void remin(T& a, const T& b) { if (b < a) a = b; }
template<typename T> void remax(T& a, const T& b) { if (b > a) a = b; }
template<class T1, class T2>inline istream& operator>> (istream& s, pair<T1, T2> &p) {	return s >> p.first >> p.second;}
template<class T1, class T2>inline ostream& operator<< (ostream& s, const pair<T1, T2>p) {	return s << "(" << p.first << " " << p.second << ")";}
template<class T1>inline ostream& operator<< (ostream& s, const vector<T1> container) {
	for (typename vector<T1>::const_iterator i = container.begin(); i != container.end(); i++) s << *i << " ";
	return s;
}
template<class T1>inline istream& operator>> (istream&s, vector<T1> &container) {
	for (typename vector<T1>::iterator i = container.begin(); i != container.end(); i++) s >> *i;
	return s;
}

/*
 * Real code
 */

typedef vector<vector<char>> Level;

int diff(const Level &a, const Level &b) {
    int r = 0;
    REP(i, a.size()) {
        REP(j, a[i].size()) {
            r += (a[i][j] != b[i][j]);
        }
    }
    return r;
}

int main(void) {
    int n, m, k, w;
    cin >> n >> m >> k >> w;
    vector<Level> levels(k, Level(n, vector<char>(m)));
    cin >> levels;
    vector<vector<int>> diffs(k, vector<int>(k));
    REP(i, k) {
        FOR(j, i + 1, k - 1) {
            diffs[i][j] = diffs[j][i] = diff(levels[i], levels[j]);
        }
    }
    vector<pair<int, int>> best_answer;
    int cost = 0;

    best_answer.emplace_back(0, 0);
    cost += n*m;
    vector<bool> take(k, false);
    take[0] = true;
    while (best_answer.size() < k) {
        int best_price = n*m;
        int best_target = 0;
        int best_start = 0;
        for (const auto &start : best_answer) {
            REP(target, k) {
                if (!take[target]) {
                    int price = diffs[start.first][target] * w;
                    if (price < best_price) {
                        best_price = price;
                        best_target = target;
                        best_start = start.first;
                    }
                }
            }
        }
        if (best_price < n*m) {
            cost += best_price;
            best_answer.emplace_back(best_target, best_start + 1);
            take[best_target] = true;
        }
        else {
            cost += n*m;
            REP(i, k) {
                if (!take[i]) {
                    take[i] = true;
                    best_answer.emplace_back(i, 0);
                    break;
                }
            }
        }
    }
    /*vector<int> perm;
    REP(i, k) {
        perm.push_back(i);
    }
    do {
        int cost = 0;
        vector<pair<int, int>> answer;
        for (auto i : perm) {
            int ccost = n*m;
            int take = 0;
            for (const auto &prev : answer) {
                int dd = diffs[i][prev.first] * w;
                if (dd < ccost) {
                    ccost = dd;
                    take = prev.first + 1;
                }
            }
            answer.emplace_back(i, take);
            cost += ccost;
        }
        if (cost < best_cost) {
            best_cost = cost;
            best_answer = answer;
        }
    } while (next_permutation(perm.begin(), perm.end()));*/
    cout << cost << '\n';
    for (const auto &i : best_answer) {
        cout << (i.first + 1) << ' ' << i.second << '\n';
    }
    return 0;
}
