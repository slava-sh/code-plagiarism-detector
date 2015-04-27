#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int X = 1e5 + 100, INF = 1e9;

int cnt[X];
pair <int, int> pr[X];
bool live[X];

int main()
{
    int t;
    cin >> t;
    for (int test = 0; test < t; test++)
    {
        int m, k;
        cin >> m >> k;
        for (int i = 1; i <= k; i++)
        {
            cin >> cnt[i];
            //new_cnt[i] = cnt[i];
            live[i] = false;
        }
        for (int i = 0; i < m - 1; i++)
        {
            cin >> pr[i].first >> pr[i].second;
        }
        int first = -1;
        for (int i = 0; i < m - 1; i++)
        {
            if(pr[i].second == 1)
            {
                first = i;
                break;
            }
        }
        int open = 0;
        if (first != -1)
        {
            for (int i = first; i < m - 1; i++)
            {
                live[pr[i].first] = true;
            }
            for (int i = 0; i < first; i++)
            {
                if(pr[i].first)
                    cnt[pr[i].first]--;
                else
                    open++;
            }
            int mn = INF, z;
            for (int i = 1; i <= k; i++)
            {
                if(!live[i] && mn > cnt[i])
                {
                    mn = cnt[i];
                    z = i;
                }
                if(!live[i] && open >= cnt[i])
                {
                    cnt[i] = 0;
                }
            }
            cnt[z] = 0;
            open -= mn;
        }
        else
            first = 0;
        for (int i = first; i < m - 1; i++)
        {
            if(pr[i].first)
                cnt[pr[i].first]--;
            else
                open++;
        }
        for (int i = 1; i <= k; i++)
        {
            if(open >= cnt[i]) cout << "Y";
            else cout << "N";
        }
        cout << '\n';
    }
    return 0;
}
