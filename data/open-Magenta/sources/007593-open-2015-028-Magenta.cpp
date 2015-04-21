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
    f(64);
    f(96);
    f(144);
    f(216);
    f(324);
    f(486);
    f(729);
    f(1094);
    f(1640);
    f(2460);
    f(3700);
    f(5540);
    return 0;
}
