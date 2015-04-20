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
const int N = (int)5005 + 7;
const int INF = 2e9 + 5;

int main()
{
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);

    int n, m, a, k = INF;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        k = min(k, a);
    }

    cout << min(k, m / n) << endl;

    return 0;
}
