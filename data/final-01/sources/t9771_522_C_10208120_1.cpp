#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>
#include<cassert>
#include<functional>

using namespace std;

const int NA = 1e5 + 50;

int kolvo[NA];
bool ispo[NA];

void solve()
{
    int m, k;  cin >> m >> k;   kolvo[0] = 0;
    for (int i = 1; i <= k; ++i)  {      cin >> kolvo[i];       ispo[i] = false;   }
    bool ue = false;
    int a;
    int b;
    int k1 = 0;
    int k2;
    for (int i = 1; i < m; ++i) {
        cin >> a >> b;
        if (b
        &&
        !ue)
            ue = true, k1 = kolvo[0];
        if (ue)
            ispo[a] = true;
        kolvo[a]--;
    }
    int k3
    = NA;
    if (ue)
    {
        for (int i = 1; i <= k; ++i) if (!ispo[i]) k3 = min(k3, kolvo[i]);
        k2 = kolvo[0] + k3;
    }
    else k2 = kolvo[0];
    for (int i = 1; i <= k; ++i)
    {
        bool s = false;
        if (!ispo[i] && kolvo[i] + k1 <= 0) s = true;
        if (kolvo[i] + k2 <= 0)s = true;
        putc(s ? 'Y' : 'N', stdout);
    }
    putc('\n', stdout);
}

int main() {
    int n;cin >> n;
    for (int i = 0; i < n; ++i)solve();
}




