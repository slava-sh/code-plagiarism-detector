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
    K++;
    if (K > 200000) {
        int a = 0;
        cout << 1 / a;
    }
    cout << c << '\n';
    cout.flush();
    char ans;
    cin >> ans;
    if (ans == 'E') {
        int a = 0;
        cout << 1 / a;
    }
    if (ans == 'Y')
        exit(0);
}

set<pii> q;

void dfs(int x, int y) {
    q.insert(mp(x, y));
    if ((abs(x - 1) + 1) * (abs(y) + 1) <= BORDER && !q.count(mp(x - 1, y))) {
        check('U');
        dfs(x - 1, y);
        check('D');
    }
    if ((abs(x) + 1) * (abs(y + 1) + 1) <= BORDER && !q.count(mp(x, y + 1))) {
        check('R');
        dfs(x, y + 1);
        check('L');
    }
    if ((abs(x + 1) + 1) * (abs(y) + 1) <= BORDER && !q.count(mp(x + 1, y))) {
        check('D');
        dfs(x + 1, y);
        check('U');
    }
    if ((abs(x) + 1) * (abs(y - 1) + 1) <= BORDER && !q.count(mp(x, y - 1))) {
        check('L');
        dfs(x, y - 1);
        check('R');
    }
}

int main() {
    q.clear();
    BORDER = 301;
    dfs(0, 0);
    q.clear();
    BORDER = 2001;
    dfs(0, 0);
    q.clear();
    BORDER = 6001;
    dfs(0, 0);
    int a = 0;
    cout << 1 / a;
    return 0;
}
