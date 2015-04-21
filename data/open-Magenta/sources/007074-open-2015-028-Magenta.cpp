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
    q.clear();
    BORDER = b;
    dfs(0, 0);
}

int main() {
    f(10);
    f(30);
    f(70);
    f(100);
    f(120);
    f(150);
    f(250);
    f(450);
    f(650);
    f(1050);
    f(1550);
    f(2050);
    f(3500);
    f(4500);
    f(6050);
    debug("%d\n", K);
    return 0;
}
