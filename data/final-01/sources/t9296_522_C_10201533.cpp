#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <memory.h>
#include <ctime>

using namespace std;

#pragma comment(linker, "/STACK:128000000")

typedef pair<int, int> pii;
typedef long long int64;
typedef pair<int64, int64> pii64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef pair<int,pii> piii;
typedef pair<pii,pii> piiii;

#define y1 dsjfksdj_fks
#define y2 alksaad_sa

const int maxn = 100005;

int nt;
int n, m;
int a[maxn];
pii b[maxn];
int ans[maxn];
int last[maxn];

inline void init()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        ans[i] = 0;
        last[i] = -1;
        scanf("%d", &a[i]);
    }
    --n;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &b[i].first, &b[i].second);
        --b[i].first;
        if (b[i].first != -1)
            last[b[i].first] = i;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    scanf("%d", &nt);
    for (;nt--;)
    {
        init();
        
        int pos = -1;
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (b[i].second)
            {
                pos = i;
                break;
            }
            if (b[i].first == -1)
                ++cnt;
            else
                --a[b[i].first];
        }
        if (pos == -1)
        {
            for (int i = 0; i < m; ++i)
            {
                if (a[i] <= cnt)
                    ans[i] = 1;
            }
        } else {
            int minval = cnt;
            for (int i = 0; i < m; ++i)
            {
                if (last[i] < pos && a[i] <= cnt)
                {
                    ans[i] = 1;
                    minval = min(minval, a[i]);
                }
            }
            for (int i = pos; i < n; ++i)
            {
                if (b[i].first != -1)
                    --a[b[i].first];
                else
                    ++cnt;
            }
            for (int i = 0; i < m; ++i)
            {
                if (a[i] <= cnt - minval)
                    ans[i] = 1;
            }
        }
        for (int i = 0; i < m; ++i)
            if (ans[i])
                printf("Y");
            else
                printf("N");
        printf("\n");
    }
    
    return 0;
}