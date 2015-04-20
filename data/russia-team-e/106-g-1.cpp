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
    cout << min((n + 1) / 4, (m + 1) / 4) << endl;
    return 0;
}
