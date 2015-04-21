#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <iomanip>

#define pb push_back
#define mp make_pair
#define F first
#define S second

#define foreach(i, q) for (typeof(q.begin()) i = q.begin(); i != q.end(); ++i)

#ifdef LOCAL
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif // LOCAL

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

const int INF = int(1e9);
const int MOD = INF + 7;

int BORDER;
int K = 0;

void check(char c) {
    char ans;
#ifdef LOCAL
    ans = 'N';
    K++;
#else
    cout << c << '\n';
    cout.flush();
    cin >> ans;
#endif
    if (ans == 'Y')
        exit(0);
}

set<pii> q;

void dfs(int x, int y) {
    q.insert(mp(x, y));
    if ((abs(x) + 1) * (abs(y - 1) + 1) <= BORDER && !q.count(mp(x, y - 1))) {
        check('L');
        dfs(x, y - 1);
        check('R');
    }
    if ((abs(x - 1) + 1) * (abs(y) + 1) <= BORDER && !q.count(mp(x - 1, y))) {
        check('U');
        dfs(x - 1, y);
        check('D');
    }
}

void f(int b) {
    q.clear();
    BORDER = b;
    dfs(0, 0);
}

int main() {
    f(10);
    f(100);
    f(300);
    f(500);
    f(700);
    f(900);
    f(1200);
    f(1500);
    f(1700);
    f(2000);
    f(2101);
//    f(6001);
    debug("%d\n", K);
    return 0;
}
