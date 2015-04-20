#include <iostream>
#include <cstdio>
#include <set>
#include <map>

using namespace std;

map <string, int> mp;
set <string> st[110];

int sz = 0;

void print(string s)
{
    if ((int)s.size() == 3)
    {
        cout << s;
    }
    else if ((int)s.size() == 4)
    {
        cout << s[0] << s[1] << '-' << s[2] << s[3];
    }
    else if ((int)s.size() == 5)
    {
        cout << s[0] << s[1] << s[2] << '-' << s[3] << s[4];
    }
    else if ((int)s.size() == 6)
    {
        cout << s[0] << s[1] << '-' << s[2] << s[3] << '-' << s[4] << s[5];
    }
    else if ((int)s.size() == 7)
    {
        cout << s[0] << s[1] << s[2] << '-' << s[3] << s[4] << '-' << s[5] << s[6];
    }
}

int main()
{
    freopen("numbers.in", "r", stdin);
    freopen("numbers.out", "w", stdout);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string c;
        cin >> c;
        int k;
        cin >> k;
        mp[c] = sz;
        for (int j = 0; j < k; j++)
        {
            cin >> c;
            st[sz].insert(c);
        }
        sz++;
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        int ok = 0;

        for (int j = 1; j <= 3; j++)
        {
            for (int k = 1; k <= 5; k++)
            {
                string c1, c2, c3;
                int p = 0;
                for (int t = 0; t < j; t++)
                {
                    c1 += s[p];
                    p++;
                }
                for (int t = 0; t < k; t++)
                {
                    c2 += s[p];
                    p++;
                }
                while (p < (int)s.size())
                {
                    c3 += s[p];
                    p++;
                }
                if (c1[0] == '0' || c2[0] == '0' || c3[0] == '0')
                {
                    break;
                }
                if (mp.find(c1) != mp.end())
                {
                    int num = mp[c1];
                    if (st[num].find(c2) != st[num].end())
                    {
                        ok = 1;
                        cout << '+';
                        cout << c1;
                        cout << '(' << c2 << ')';
                        print(c3);
                        cout << endl;
                    }
                }
                if (ok)
                {
                    break;
                }
            }
            if (ok)
            {
                break;
            }
        }

        if (!ok)
        {
            cout << "Incorrect" << endl;
        }

    }

    return 0;
}

/*
2
7 3
981
3517
812
351 3
34712
1234
963
8
79818266456
35196328463
78122472557
01234567890
73517960326
35134712239
35112342013
78120203040
*/
