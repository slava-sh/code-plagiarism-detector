#include <cstdio>
#include <queue>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <bitset>
using namespace std;

typedef long long ll;
#define INF 1234567890
#define eps 1e-7
#define mod 1000000007
/*
vector <pair <int, int> > v[2];

const bool sort_f(const pair <int, int> a, const pair <int, int> b)
{
    if(a.first != b.first)
        return a.first < b.first;
    return a.second > b.second;
}

int main()
{
    int n, x;
    scanf("%d %d", &n, &x);
    for(int i = 0; i < n; i++)
    {
        pair <int, int> candy;
        int t;
        scanf("%d %d %d", &t, &candy.first, &candy.second);
        v[t].push_back(candy);
    }
    sort(v[0].begin(), v[0].end(), sort_f);
    sort(v[1].begin(), v[1].end(), sort_f);
    int res = 0;

    for(int i = 0; i < 2; i++)
    {
        int cnt = 0;
        priority_queue <int> q[2];
        int curh = x;
        int cur[2] = {0, 0};
        for(int j = 0; j < 2; j++)
        {
            while(cur[j] < v[j].size() && v[j][cur[j]].first <= curh)
            {
                q[j].push(v[j][cur[j]].second);
                cur[j]++;
            }
        }
        while(!q[i].empty())
        {
            cnt++;
            curh += q[i].top(); q[i].pop();
            for(int j = 0; j < 2; j++)
            {
                while(cur[j] < v[j].size() && v[j][cur[j]].first <= curh)
                {
                    q[j].push(v[j][cur[j]].second);
                    cur[j]++;
                }
            }
            if(q[1-i].empty())
                break;
            cnt++;
            curh += q[1-i].top(); q[1-i].pop();
            for(int j = 0; j < 2; j++)
            {
                while(cur[j] < v[j].size() && v[j][cur[j]].first <= curh)
                {
                    q[j].push(v[j][cur[j]].second);
                    cur[j]++;
                }
            }
        }
        res = max(res, cnt);
    }
    printf("%d\n", res);
    return 0;
}
*/
/*
char a[2005][2005];

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < n; i++)
        scanf("%s", a[i]);
    for(int j = 0; j < m; j++)
    {
        int cnt = 0;
        for(int i = 1; i < n; i++)
        {
            if(j - i >= 0 && a[i][j-i] == 'R') cnt++;
            if(j + i < m && a[i][j+i] == 'L') cnt++;
            if(i + i < n && a[i+i][j] == 'U') cnt++;
        }
        if(j) putchar(' ');
        printf("%d", cnt);
    }
    puts("");
    return 0;
}
*/

int n, m, k, w;
bitset <1005> a[1005][105];
char s[1005][15][15];
vector <pair <int, int> > ans;

int main()
{
    scanf("%d %d %d %d", &n, &m, &k, &w);
    for(int i = 0; i < k; i++)
        for(int j = 0; j < n; j++)
            scanf("%s", s[i][j]);
    for(int i = 0; i < k; i++)
        for(int j = i + 1; j < k; j++)
        {
            int cnt = 0;
            for(int p = 0; p < n; p++)
                for(int q = 0; q < m; q++)
                    if(s[i][p][q] != s[j][p][q])
                        cnt++;
            a[i][cnt].set(j);
            a[j][cnt].set(i);
        }
    for(int i = 0; i < k; i++)
        for(int j = 1; j <= n * m; j++)
            a[i][j] |= a[i][j-1];

    int res = 0;
    for(int first = 0; first < 1; first++)
    {
        ans.push_back(make_pair(first, -1));
        bitset <1005> cur;
        cur.set(first);
        for(int _ = 1; _ < k; _++)
        {
            int minv = 123, mini = -1;
            for(int i = 0; i < k; i++)
            {
                if(cur.at(i)) continue;
                int L = 0, R = n * m;
                while(L < R)
                {
                    int C = (L + R) / 2;
                    if((cur & a[i][C]).any())
                        R = C;
                    else
                        L = C + 1;
                }
                if(R < minv)
                {
                    minv = R;
                    mini = i;
                }
            }
            if(minv * w < n * m)
            {
                res += minv * w;
                for(int i = 0; i < k; i++)
                    if(cur.at(i) && a[mini][minv].at(i))
                    {
                        ans.push_back(make_pair(mini, i));
                        break;
                    }
            }
            else
            {
                res += n * m;
                ans.push_back(make_pair(mini, -1));
            }
            cur.set(mini);
        }
    }
    printf("%d\n", res + n * m);
    for(int i = 0; i < ans.size(); i++)
        printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
    return 0;
}
