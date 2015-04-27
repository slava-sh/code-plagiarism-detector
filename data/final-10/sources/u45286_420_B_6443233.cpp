#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <cmath>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define pii pair <int, int>
#define mp make_pair

struct cc
{
    int m;
    char c;
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<cc> cv(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> cv[i].c >> cv[i].m;
        cv[i].m--;
    }
    vector<int> sv(n, 2);
    int count = 0;
    for (int i = m - 1; i >= 0; --i)
    {
        if (cv[i].c == '-')
        {
            sv[cv[i].m] = 1;
            count++;
        }
        else
        {
            if (sv[cv[i].m] == 1)
                count--;
            sv[cv[i].m] = 0;
        }
    }
    set<int> neg;
    vector<bool> bv(n, true);
    for (int i = 0; i < n; ++i)
    {
        if (sv[i] == 0)
            neg.insert(i);
    }
    for (int i = 0; i < m; ++i)
    {
        if (count != 0)
        {
            for (auto it = neg.begin(); it != neg.end(); ++it)
            {
                bv[*it] = false;
            }
            neg.clear();
        }
        if (cv[i].c == '-')
        {
            count--;
            if (bv[cv[i].m])
                neg.insert(cv[i].m);
        }
        else
        {
            neg.erase(cv[i].m);
            count++;
        }
    }
    if (count != 0)
    {
        for (auto it = neg.begin(); it != neg.end(); ++it)
        {
            bv[*it] = false;
        }
        neg.clear();
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i)
    {
        if (bv[i])
            ans.push_back(i + 1);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";
    return 0;
}
