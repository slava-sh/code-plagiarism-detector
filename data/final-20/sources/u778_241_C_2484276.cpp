#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MOD = 1000000009;

vector<pair<pair<int, int>, int> > top, bottom;

int getAns(int k, vector<pair<pair<int, int>, int> > &top, vector<pair<pair<int, int>, int> > &bottom, int h1, int h2)
{
    int n = bottom.size();
    int m = top.size();
    int i, j;
    vector<bool> uB(n), uT(m);
    int H;
    long long A, B, C, y, xp, xq;
    H = k * 100 + (k % 2 == 0 ? h2 : 100 - h2);
    int curAns = 0;
    for(i = 0; i < k; i++)
    {
        y = 100 * (i + 1);
        xp = 100000 * (y - h1);
        xq = H - h1;
        vector<pair<pair<int, int>, int> > &cur = (i % 2 == 0 ? top : bottom);
        vector<bool> &u = (i % 2 == 0 ? uT : uB);
        bool good = false;
        for(j = 0; j < cur.size(); j++)
            if (cur[j].first.first * xq <= xp && cur[j].first.second * xq >= xp)
            {
                if (u[j])
                    break;
                u[j] = true;
                curAns += cur[j].second;
                good = true;
                break;
            }
        if (!good)
            return 0;
    }
    return curAns;
}

int main()
{
    int n, i, j, k, m, t, h1, h2;

    cin >> h1 >> h2 >> n;
    
    while(n--)
    {
        string s;
        cin >> k >> s >> i >> j;
        if (s == "F")
            bottom.push_back(make_pair(make_pair(i, j), k));
        else
            top.push_back(make_pair(make_pair(i, j), k));
    }
    sort(bottom.begin(), bottom.end());
    sort(top.begin(), top.end());
    n = bottom.size();
    m = top.size();

    int ans = 0;
    for(k = 1; k <= 100; k++)
    {
        ans = max(ans, getAns(k, top, bottom, h1, h2));
        ans = max(ans, getAns(k, bottom, top, 100 - h1, 100 - h2));
    }

    cout << ans << endl;
    
    return 0;
}
