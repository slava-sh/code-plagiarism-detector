#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(_x) (int) (_x).size()
#define bend(_x) (_x).begin(), (_x).end()
#define mapa make_pair
#define puba push_back

using namespace std;
typedef pair <int, int> pii;
typedef long long LL;

string chs = "URDL";

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    int dir = 0;
    char ch;
    for (int i = 1;; ++i) {
        for (int j = 0; j < i; ++j) {
            cout << chs[dir] << endl;
            cin >> ch;
            if (ch == 'Y' || ch == 'E') {
                return 0;
            }
        }
        dir = (dir + 1) % 4;
        for (int j = 0; j < i; ++j) {
            cout << chs[dir] << endl;
            cin >> ch;
            if (ch == 'Y' || ch == 'E') {
                return 0;
            }
        }
        dir = (dir + 1) % 4;
    }

    return 0;
}