#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    freopen("prizes.in", "r", stdin);
    freopen("prizes.out", "w", stdout);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    if(n == 1 || m == 1)
        cout << (max(n, m) + 1) / 4 << endl;
    else
        cout << (min(n, m) + 1) / 4 << endl;

    return 0;
}
