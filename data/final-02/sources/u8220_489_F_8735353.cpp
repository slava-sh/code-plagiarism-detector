#pragma comment(linker, "/STACK:256000000")

#include <iostream>
#include <iomanip>

#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <string>


#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

#include <sstream>

using namespace std;

#define sqr(x) ((x)*(x))

int n, m;
long long mod;

int Cnt[3];
int Count[507];

map<int, long long> dp[507][507];

long long dfs(int a, int b, int c)
{
    if (dp[a][b].count(c)) return dp[a][b][c];

    long long val = 0;
    if (a >= 2) val += dfs(a - 2, b, c + 1) * (a * (a - 1)) >> 1;
    if (a >= 1 && b >= 1) val += dfs(a, b - 1, c + 1) * (a * b);
    if (b >= 2) val += dfs(a + 2, b - 2, c + 1) * (b * (b - 1)) >> 1;

    return dp[a][b][c] = (val % mod);
}

int main()
{
    #ifdef CRABEN
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else 
    #define FILE_NAME "interconnect"
    //freopen(FILE_NAME".in", "rt", stdin);
    //freopen(FILE_NAME".out", "wt", stdout);
    #endif 

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> mod;
    for (int i = 0; i < m; i++)
    {
        string s; cin >> s;
        for (int j = 0; j < n; j++)
            Count[j] += s[j] - '0';
    }

    for (int i = 0; i < n; i++)
        Cnt[Count[i]]++;

    dp[0][0][n] = 1;

    cout << dfs(Cnt[1], Cnt[0], m);
    return 0;
}