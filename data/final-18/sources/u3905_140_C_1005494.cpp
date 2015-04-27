#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

#include <cstdarg>

using namespace std;

#define DBG2 1

void dbg(const char * fmt, ...)
{
#ifdef DBG1
#if DBG2
    va_list args;
    va_start(args, fmt);
    vfprintf(stdout, fmt, args);
    va_end(args);

    fflush(stdout);
#endif
#endif
}

typedef pair<int,int> pii;

pii getMax(pii a, pii b)
{
    if (a.second > b.second || (a.second == b.second && a.first > b.first))
        return a;
    return b;
}

struct RangeTree {
    vector <pii> b;
    int kk;

    RangeTree(vector <pii> & v)
    {
        int n = int(v.size());
        kk = 1;
        while (kk < n)
            kk *= 2;
        kk *= 2;
        b = vector<pii>(2 * kk + 2);

        for (int i = 0; i < n; ++i)
            set(i, pii(i, v[i].second));
    }

    void set(int t, pii value)
    {
        t += kk;
        b[t] = value;
        while (t > 1)
        {
            t /= 2;
            update(t);
        }
    }

    void dec(int t)
    {
        pii val = b[t + kk];
        val.second += -1;
        set(t, val); 
    }

    void inv(int t)
    {
        pii val = b[t + kk];
        val.second *= -1;
        set(t, val); 
    }

    void update(int t)
    {
        b[t] = ::getMax(b[2 * t], b[2 * t + 1]);
    }

    pii getMax(int l, int r)
    {
        l += kk;
        r += kk;
        pii result(-1, -1);
        while (l <= r)
        {
            if (l % 2 == 1)
                result = ::getMax(result, b[l++]);
            if (r % 2 == 0)
                result = ::getMax(result, b[r--]);
            l /= 2;
            r /= 2;                
        }
        return result;
    }
}; 

int main()
{
#ifdef DBG1
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    vector <int> v(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &v[i]);
    std::sort(v.begin(), v.end());
    vector <pii> v2;
    v2.push_back(pii(v[0], 1));
    for (int i = 1; i < n; ++i)
        if (v[i] == v[i - 1])
            ++v2.back().second;
        else
            v2.push_back(pii(v[i], 1));

    RangeTree tree(v2);
    bool end = false;
    vector < vector<int> > res;
    while (n >= 3 && !end)
    {
        vector <int> x;
        for (int i = 0; i < 3; ++i)
        {
            pii best = tree.getMax(0, int(v2.size()) - 1);
            fflush(stdout);
            if (best.second <= 0)
            {
                end = true;
                break;
            }
            x.push_back(best.first);
            tree.inv(x.back());
        }
        if (end)
            break;

        res.push_back(x);
        for (int i = 0; i < 3; ++i)
        {
            tree.inv(x.back());
            tree.dec(x.back());
            x.pop_back();
        }
        n -= 3;
    }

    printf("%d\n", int(res.size()));
    for (int i = 0; i < int(res.size()); ++i)
    {
        vector <int> v;
        for (int j = 0; j < 3; ++j)
            v.push_back(v2[res[i][j]].first);
        sort(v.begin(), v.end(), greater<int>());
        for (int j = 0; j < 3; ++j)
            printf("%d ", v[j]);
        printf("\n");
    }

    return 0;
}