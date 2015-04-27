#pragma comment(linker, "/STACK:64000000")
#include <algorithm>
#include <memory.h>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <cassert>
#include <map>
#include <set>
#include <vector>
#include <queue>

using namespace std;
#define prev privet1
#define next privet2
#define y1 privet3
#define rank privet4
#define left privet5
#define right privet6
#define y0 privet7

const double pi = 3.141592653589793238;

void ensureLimit(long long n, long long l, long long r)
{
    assert(l <= n && n <= r);
}

bool can[100333];
int n, m;
int a[100333], b[100333];
bool used[100333];

int main()
{
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    char q;
    for (int i = 1; i <= m; i++) {
        cin >> q >> a[i];
        if (q == '-') a[i] = -a[i];
    }
//  for (int i = 1; i <= n; i++) 
//      cout << a[i] << endl;
    memset(can, true, sizeof(can));
    int opened = 0;
    for (int i = 1; i <= m; i++) {
        if (!used[abs(a[i])] && a[i] < 0) opened++;
        used[abs(a[i])] = true;
    }
    bool was_plus = (opened > 0);
    memset(used, false, sizeof(used));
    for (int i = 1; i <= m; i++) {
        if (!used[abs(a[i])] && a[i] > 0 && was_plus) can[a[i]] = false;
        was_plus = was_plus | (a[i] > 0);
        if (opened > 1 && a[i] < 0) can[abs(a[i])] = false;
        if (opened > 0 && a[i] > 0) can[a[i]] = false;
        if (a[i] < 0 && i < m && a[i + 1] != -a[i]) can[-a[i]] = false;
        if (a[i] > 0) b[a[i]] = 1, opened++;
        else  b[-a[i]] = 0, opened--;
        used[abs(a[i])] = true;

    }
    int k = 0;
    for (int i = 1; i <= n; i++) 
        if (can[i]) k++;
    printf("%d\n", k);
    if (k == 0) return 0;
    for (int i = 1; i <= n; i++)
        if (can[i]) printf("%d ", i);
    printf("\n");
}
