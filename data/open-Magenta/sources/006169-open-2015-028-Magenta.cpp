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
    cout << c << '\n';
    cout.flush();
    char ans;
    cin >> ans;
//    ans = 'N';
    K++;
    if (ans == 'Y')
        exit(0);
}

set<pii> q;

void dfs(int x, int y) {
//    cerr << x << " " << y << endl;
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
    f(20);
    f(121);
    f(601);
    f(1401);
    q.clear();
    int cur = 1;
    int i = 1;
    int dir = 0;
    char d[4] = {'U', 'R', 'D', 'L'};
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int x = 0, y = 0;
    q.insert(mp(0, 0));
    while (cur < 151) {
        for (int j = 0; j < cur; ++j)
            check(d[dir]), x += dx[dir], y += dy[dir], q.insert(mp(x, y));
        i++;
        dir = (dir + 1) % 4;
        if (i % 2)
            cur++;
    }
//    cerr << K << endl;
    for (int i = 0; i < 75; ++i)
        check('R');
    y = 0;
    BORDER = 3001;
    check('D');
    x++;
    dfs(x, y);
    return 0;
}
