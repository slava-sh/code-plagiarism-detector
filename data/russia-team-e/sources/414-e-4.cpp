#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

map <string, int> res, bad;


int main()
{
    freopen("numbers.in", "r", stdin);
    freopen("numbers.out", "w", stdout);
    string st, s, now, cur, ans;
    int len;
    int n, i, j, k, m, z, p, sz;
    bool f1, f2, f;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        f1 = 0;
        cin >> s >> len;
        if(s[0] == '0')
            f1 = 1;
        for(j = 0; j < len; j++)
        {
            f2 = 0;
            cin >> st;
            if(st[0] == '0')
                f2 = 1;
            st = s + st;
            if(!f1 && !f2)
                res[st] = (int)s.length();
        }
    }
    string s1 = "";
    cin >> m;
    for(i = 0; i < m; i++)
    {
        f = 0;
        p = 0;
        s1 = "";
        cin >> cur;
        for(j = 4; j <= 8; j++)
        {
            now = cur.substr(0, j);
            if(res[now])
            {
                f = 1;
                p = j;
                s1 += '+';
                z = res[now];
                for(k = 0; k < z; k++)
                   s1 += cur[k];
                s1 += '(';
                for(k = z; k < (int)now.size(); k++)
                   s1 += cur[k];
                s1 += ')';
            }
        if(!f)
            continue;
        f2 = 0;
        now = cur.substr(p, (int)cur.size());
        sz = (int)now.size();
        if(now[0] == '0')
        {
            s1 = "";
            continue;
        }
        if(sz == 3)
            s1 += now, f2 = 1;
        if(sz == 4)
        {
            for(k = 0; k < 2; k++)
                s1 += now[k];
            s1 += '-';
            for(k = 2; k < sz; k++)
                s1 += now[k];
            f2 = 1;
        }
       if(sz == 5)
        {
            for(k = 0; k < 3; k++)
                s1 += now[k];
            s1 += '-';
            for(k = 3; k < sz; k++)
                s1 += now[k];
            f2 = 1;
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
            f2 = 1;
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
            f2 = 1;
        }
        if(s1 != "")
            break;
    }
        if(s1 == "")
            cout << "Incorrect\n";
        else
        cout << s1 << endl;

    }



    return 0;
}
