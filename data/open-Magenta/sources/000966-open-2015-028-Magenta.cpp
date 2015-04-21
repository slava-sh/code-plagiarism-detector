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

void check(char c) {
    cout << c << endl;
    char ans;
    cin >> ans;
    if (ans == 'Y' || ans == 'E')
        exit(0);
}

void dfs(int x, int y) {
    if (abs(x * y) > BORDER)
        return;
    check('U');
    dfs(x - 1, y);
    check('D');
    check('R');
    dfs(x, y + 1);
    check('L');
    check('D');
    dfs(x + 1, y);
    check('U');
    check('L');
    dfs(x, y - 1);
    check('R');
}

int main() {
    BORDER = 300;
    dfs(0, 0);
    BORDER = 2000;
    dfs(0, 0);
    BORDER = 6000;
    dfs(0, 0);
    return 0;
}
