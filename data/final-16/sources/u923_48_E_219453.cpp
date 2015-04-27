#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

struct pos
{
    int h, t, c;
    explicit pos(int h, int t, int c) : h(h), t(t), c(c) { }
};

int H[201][2];
int T[201][2];

bool w[201][201];
bool cw[201][201];
vector <pos> a;

int h, t, R, n, m;

bool try_kill()
{
    a.clear();
    memset(w, 0, sizeof(w));
    a.push_back(pos(h, t, 0));
    w[h][t] = 1;
    int k = 0;
    int hn, tn;
    while (k < a.size())
    {
        int h = a[k].h, t = a[k].t;
        for (int i = 1; i <= min(h, n); ++i)
        {
            hn = h - i + H[i][0];
            tn = t + H[i][1];
            if (hn + tn == 0)
            {
                printf("Ivan\n%d\n", a[k].c + 1);
                return true;
            }
            if (hn + tn <= R && !w[hn][tn])
            {
                w[hn][tn] = 1;
                a.push_back(pos(hn, tn, a[k].c + 1));
            }
        }
        for (int i = 1; i <= min(t, m); ++i)
        {
            hn = h + T[i][0];
            tn = t - i + T[i][1];
            if (hn + tn == 0)
            {
                printf("Ivan\n%d\n", a[k].c + 1);
                return true;
            }
            if (hn + tn <= R && !w[hn][tn])
            {
                w[hn][tn] = 1;
                a.push_back(pos(hn, tn, a[k].c + 1));
            }
        }
        ++k;
    }
    return false;
}

int hn, tn;

bool avoid(int h, int t)
{
    cw[h][t] = 1;
    w[h][t] = 1;
    for (int i = 1; i <= min(h, n); ++i)
    {
        hn = h - i + H[i][0];
        tn = t + H[i][1];
        if (hn + tn <= R)
        {
            if (cw[hn][tn])
            {
                printf("Draw\n");
                return true;
            }
            if (!w[hn][tn] && avoid(hn, tn))
                return true;
        }
    }
    for (int i = 1; i <= min(t, m); ++i)
    {
        hn = h + T[i][0];
        tn = t - i + T[i][1];
        if (hn + tn <= R)
        {
            if (cw[hn][tn])
            {
                printf("Draw\n");
                return true;
            }
            if (!w[hn][tn] && avoid(hn, tn))
                return true;
        }
    }
    cw[h][t] = 0;
    return false;
}

bool try_avoid()
{
    memset(w, 0, sizeof(w));
    memset(cw, 0, sizeof(cw));
    return avoid(h, t);
}

int dead[201][201];

int longest_death(int h, int t)
{
    dead[h][t] = 1;
    for (int i = 1; i <= min(h, n); ++i)
    {
        hn = h - i + H[i][0];
        tn = t + H[i][1];
        if (hn <= R && tn <= R)
        {
            if (dead[hn][tn] != -1)
                dead[h][t] = max(dead[h][t], dead[hn][tn] + 1);
            else
                dead[h][t] = max(dead[h][t], longest_death(hn, tn) + 1);
        }
    }
    for (int i = 1; i <= min(t, m); ++i)
    {
        hn = h + T[i][0];
        tn = t - i + T[i][1];
        if (hn <= R && tn <= R)
        {
            if (dead[hn][tn] != -1)
                dead[h][t] = max(dead[h][t], dead[hn][tn] + 1);
            else
                dead[h][t] = max(dead[h][t], longest_death(hn, tn) + 1);
        }
    }
    return dead[h][t];
}

void try_die()
{
    memset(dead, -1, sizeof(dead));
    for (int i = 0; i <= R; ++i)
        for (int j = 0; j <= R; ++j)
            if (i + j > R)
                dead[i][j] = 0;
    printf("Zmey\n%d\n", longest_death(h, t));
}

int main()
{
    scanf("%d%d%d%d", &h, &t, &R, &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &H[i][0], &H[i][1]);
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d%d", &T[i][0], &T[i][1]);
    if (!try_kill())
    {
        if (!try_avoid())
            try_die();
    }
    return 0;
}
