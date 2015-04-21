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

vector<pair<int, int>> v[400];

pair<int, int> vect(pair<int, int> a, pair<int, int> b)
{
    return {b.first - a.first, b.second - a.second};
}

int prod(pair<long long, long long> a, pair<long long, long long> b)
{
    long long opr = a.first * b.second - a.second * b.first;
    if(opr < 0)
        return -1;
    if(opr > 0)
        return 1;
    return 0;
}

bool inter(int i, int j, int ip, int jp)
{
    pair<int, int> a = v[i][ip],
                    b = v[i][ip + 1],
                    c = v[j][jp],
                    d = v[j][jp + 1];
    pair<int, int> ab = vect(a, b),
                    ac = vect(a, c),
                    ad = vect(a, d),
                    ca = vect(c, a),
                    cb = vect(c, b),
                    cd = vect(c, d);

    int s1 = prod(ac, ab), s2 = prod(ad, ab);
    if(s1 == 0 and s2 == 0)
        return true;
    if(s1 == 0 or s2 == 0)
        return false;
    if(s1 == s2)
        return false;

    int s3 = prod(ca, cd), s4 = prod(cb, cd);

    if(s1 != s2 and s3 != s4)
        return true;

    return false;

}

int main()
{
    freopen("input.txt", "r", stdin);
    int a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int l;
        cin >> l;
        for(int j = 0; j < l + 1; ++j)
        {
            int x, y;
            cin >> x >> y;
            v[i].push_back({x, y});
        }
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(i == j)
                continue;
            int ip = 0, jp = 0;
            while(ip + 1 < v[i].size() and jp + 1 < v[j].size())
            {
                if(inter(i, j, ip, jp))
                {
                    cout << "No" << endl;
                    cout << i + 1 << " " << j + 1 << endl;
                    return 0;
                }
                if(v[i][ip + 1].first < v[j][jp + 1].first)
                    ++ip;
                else
                    ++jp;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
