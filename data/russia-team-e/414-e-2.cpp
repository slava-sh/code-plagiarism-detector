#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

const int N = (int)1e5 + 10;

int len;

map <string, int> res, bad;
string st, s, now, cur;

int main()
{
    freopen("numbers.in", "r", stdin);
    freopen("numbers.out", "w", stdout);
    int n, i, j, k, m;
    bool f1;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        f1 = 0;
        cin >> s >> len;
        if(s[0] == '0')
            f1 = 1;
        for(j = 0; j < len; j++)
        {
            cin >> st;
            if(st[0] == '0')
                f1 = 1;
            st = s + st;
            if(!f1)
                res[st] = (int)s.length();
        }
    }
    string s1 = "";
    cin >> m;
    for(i = 0; i < m; i++)
    {
        bool f = 0;
        int p = 0;
        s1 = "";
        cin >> cur;
        for(j = 4; j <= 10; j++)
        {
            now = cur.substr(0, j);
            if(res[now])
            {
                f = 1;
                p = j;
                s1 += '+';
                for(k = 0; k < res[now]; k++)
                   s1 += cur[k];
                s1 += '(';
                for(k = res[now]; k < (int)now.length(); k++)
                   s1 += cur[k];
                s1 += ')';
            }
            if(f)
                break;
        }
        if(!f)
        {
            cout << "Incorrect\n";
            continue;
        }
        now = cur.substr(p, (int)cur.length());
        int sz = (int)now.size();
        if(now[0] == '0')
        {
            cout << "Incorrect\n";
            continue;
        }
        if(sz == 3)
            s1 += now, f = 1;
        if(sz == 4)
        {
            for(k = 0; k < 2; k++)
                s1 += now[k];
            s1 += '-';
            for(k = 2; k < sz; k++)
                s1 += now[k];
            f = 1;
        }
       if(sz == 5)
        {
            for(k = 0; k < 3; k++)
                s1 += now[k];
            s1 += '-';
            for(k = 3; k < sz; k++)
                s1 += now[k];
            f = 1;
        }
        if(sz == 6)
        {
            for(k = 0; k < 2; k++)
                s1 += now[k];
            s1 += '-';
            for(k = 2; k < 4; k++)
                s1 += now[k];
            s1 += '-';
            for(k = 4; k < sz; k++)
                s1 += now[k];
            f = 1;
        }
        if(sz == 7)
        {
            for(k = 0; k < 3; k++)
                s1 += now[k];
            s1 += '-';
            for(k = 3; k < 5; k++)
                s1 += now[k];
            s1 += '-';
            for(k = 5; k < sz; k++)
                s1 += now[k];
            f = 1;
        }
        if(!f)
            cout << "Incorrect\n";
        else
            cout << s1 << endl;

    }



    return 0;
}
