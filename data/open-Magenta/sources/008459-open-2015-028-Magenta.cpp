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
    if (ans == 'Y' || ans == 'E')
        exit(0);
}

void dfs(int x, int y) {
    bool q = 0;
    for (int i = 0; i <= BORDER; ++i) {
        if (!q) {
            while ((x + 1) * (y + 2) <= BORDER)
                check('R'), y++;
        } else {
            while (y)
                check('L'), y--;
            check('D');
        }
        x++;
        q ^= 1;
    }
    for (int i = 0; i <= BORDER; ++i)
        check('U'), x--;
}

void f(int b) {
    BORDER = b;
    dfs(0, 0);
    debug("%d\n", K);
}

int main() {
    vi pts;
    int x;
    ifstream cin("input.txt");
    while (cin >> x)
        pts.pb(x);
    int cur = 0;
    f(pts[0]);
    ofstream db("debug.txt");
    for (int i = 10; i <= 6000; ++i) {
        while (i > pts[cur])
            cur++, f(pts[cur]);
        db << K << endl;
    }
//    f(10);
//    f(25);
//    f(40);
//    f(50);
//    f(100);
//    f(150);
//    f(300);
//    f(515);
//    f(1040);
//    f(2060);
//    f(4110);
//    f(6001);
    return 0;
}
