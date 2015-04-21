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

void check() {
    cout.flush();
    char ans;
    cin >> ans;
    if (ans == 'Y' || ans == 'E')
        exit(0);
}

int main() {
    cout << "R\n";
    check();
    cout << "L\n";
    check();
    int cur = 1;
    int i = 1;
    int dir = 0;
    char d[4] = {'U', 'R', 'D', 'L'};
    while (1) {
        for (int j = 0; j < cur; ++j)
            cout << d[dir] << '\n', check();
        i++;
        dir = (dir + 1) % 4;
        if (i % 2)
            cur++;
    }
    return 0;
}
