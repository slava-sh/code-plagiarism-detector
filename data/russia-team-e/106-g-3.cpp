#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <queue>

#define x first
#define y second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int N = (int)(5e2) + 7;


int main()
{
    freopen("prizes.in", "r", stdin);
    freopen("prizes.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    if (n == 1)
    {
        cout << (m + 1) / 4 << endl;
        return 0;
    }
    if (m == 1)
    {
        cout << (n + 1) / 4 <<endl;
        return 0;
    }
    if (n >= 3 && m >= 3)
        return cout << 1 << endl, 0;
    cout << min((n + 1) / 4, (m + 1) / 4) << endl;
    return 0;
}
