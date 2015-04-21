/**
 * EASY.
**/

#include <iostream>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <array>
#include <memory.h>
#include <stack>
#include <queue>
#include <deque>
#include <assert.h>


using namespace std;

long double GROUP = 100;

int geth(int w)
{
    return ceil(GROUP / w);
}

bool rev = false;

inline void read()
{
    char c;
    cin >> c;
    if(c != 'N')
        exit(0);
}

inline void go(char d)
{
    if(rev)
    {
        switch(d)
        {
        case 'U':
            cout << 'D' << endl; break;
        case 'D':
            cout << "U" << endl; break;
        default:
            cout << d << endl;
        }
    }
    else
        cout << d << endl;
    cout.flush();
    read();
}

void f(vector<pair<int, pair<int, int>>> v)
{
    int x = 0, y = 0;

    for(int i = 0; i < GROUP / 2; ++i)
    {
        go('U');
        ++y;
    }
    for(int i = 0; i + 1 < v.size(); ++i)
    {
        int st = 1;
        bool right = true;
        if(st < (v[i].second.second - v[i].second.first + 1))
        {
            if(x >= v[i].second.second)
                right = false;
        }
        if(right)
        {
            while(x < v[i + 1].second.second)
            {
                go('R');
                ++x;
            }
        }
        else
        {
            while(x > v[i + 1].second.first)
            {
                go('L');
                --x;
            }
        }
        go('D');
        --y;
    }
    if(x == v.back().second.first)
    {
        while(x < v.back().second.second)
        {
            ++x;
            go('R');
        }
        while(x > 0)
        {
            --x;
            go('L');
        }
    }
    else
    {
        while(x > v.back().second.first)
        {
            --x;
            go('L');
        }
        while(x < 0)
        {
            ++x;
            go('R');
        }
    }
}

int main()
{
    vector<int> GRVAL = {150, 250, 350, 550, 750, 1050, 1550, 2050};
    for(int T = 0; T < GRVAL.size(); ++T)
    {
        GROUP = GRVAL[T];
        vector<pair<int, pair<int, int>>> v;
        auto prev = GROUP / 2;
        //cout << "segment y, x[] = " << prev << " " << 0 << " " << 0 << endl;
        v.push_back({prev, {0, 0}});

        for(int i = 2; i <= GROUP; ++i)
        {
            auto res = geth(i) / 2;
            //cout << "segment y, x[] = " << res << " " << - i / 2 << " " << i / 2 << endl;
            //cout << res << " ? " << prev << endl;
            if(res == prev)
            {
                //cout << i << "cont" << endl;
                continue;
            }

            for(int d = v.back().first - 1; d > res; --d)
            {
                v.push_back({d, v.back().second});
            }

            v.push_back({res, {-i / 2, i / 2}});
            prev = res;
            //cout << "w, h = " << i << " " << res << endl;
        }
        /*for(auto i : v)
        {
            cout << i.first << " [" << i.second.first << "; " << i.second.second << "]" << endl;
        }*/

        f(v);
        rev = true;
        f(v);
    }

    return 0;
}
