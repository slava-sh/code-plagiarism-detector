#include <bits/stdc++.h>

#define ll long long
#define fn "numbers"

using namespace std;

const int MXN = 1e5 + 9;
const int INF = 1e9 + 9;

int n, m, k, NF;

map<string, int> mp;
pair<string, string> num[MXN];

int main()
{
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        string a, b;
        cin >> a;
        scanf("%d", &k);
        for (int j = 1; j <= k; j++)
        {
            cin >> b;
            NF++;
            mp[a + b] = NF;
            num[NF] = make_pair(a, b);
        }
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int boo = -1, ind;
        string t, q = "";
        cin >> t;
        for (int i = 0; i < 8; i++)
        {
            q += t[i];

            int tmp = mp[q];
            if (tmp && t[i + 1] != '0')
            {
                boo = tmp;
                ind = i + 1;
                break;
            }
        }
        if (boo == -1)
        {
            cout << "Incorrect\n";
        }
        else
        {
            cout << '+' << num[boo].first << '(' << num[boo].second << ')';
            int sz = 11 - ind;
            if (sz == 3)
            {
                for (int i = ind; i <= ind + 2; i++)
                    cout << t[i];
            }
            else if (sz == 4)
            {
                for (int i = ind; i <= ind + 1; i++)
                    cout << t[i];

                cout << '-';
                for (int i = ind + 2; i <= ind + 3; i++)
                    cout << t[i];
            }
            else if (sz == 5)
            {
                for (int i = ind; i <= ind + 2; i++)
                    cout << t[i];

                cout << '-';
                for (int i = ind + 3; i <= ind + 4; i++)
                    cout << t[i];
            }
            else if (sz == 6)
            {
                for (int i = ind; i <= ind + 1; i++)
                    cout << t[i];

                cout << '-';
                for (int i = ind + 2; i <= ind + 3; i++)
                    cout << t[i];

                cout << '-';
                for (int i = ind + 4; i <= ind + 5; i++)
                    cout << t[i];
            }
            else
            {
                for (int i = ind; i <= ind + 2; i++)
                    cout << t[i];

                cout << '-';
                for (int i = ind + 3; i <= ind + 4; i++)
                    cout << t[i];

                cout << '-';
                for (int i = ind + 5; i <= ind + 6; i++)
                    cout << t[i];
            }
            cout << endl;
        }
    }
    return 0;
}
