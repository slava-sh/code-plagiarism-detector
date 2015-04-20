#include <bits/stdc++.h>

#define ll long long
#define fn "numbers"

using namespace std;

const int MXN = 1e5 + 9;
const int INF = 1e9 + 9;

map<ll, ll> mp;
ll NF, n, c, k, x, m;

pair<ll, ll> v[MXN];

ll len(ll q)
{
    ll p = 10;
    while (q > 10)
    {
        q /= 10;
        p *= 10;
    }
    return p;
}

int main()
{
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> c >> k;
        for (int j = 1; j <= k; j++)
        {
            cin >> x;
            NF++;
            v[NF] = make_pair(c, x);
            mp[c * len(x) + x] = NF;
        }
    }

    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        ll sum = 0,
           ind = 0,
           boo = -1;

        string t;
        cin >> t;

        if (t[0] == '0')
        {
            cout << "Incorrect\n";
            continue;
        }
        for (int i = 0; i < 8; i++)
        {
            sum = sum * 10 + t[i] - 48;

            ll tmp = mp[sum];
            if (tmp && t[i + 1] > '0')
            {
                boo = tmp;
                ind = i;
                break;
            }
        }
        if (boo > 0)
        {
            cout << '+' << v[boo].first << '(' << v[boo].second << ')';
            int sz = 10 - ind;
            if (sz == 3)
            {
                for (int i = ind + 1; i < 11; i++)
                    cout << t[i];
            }
            else if (sz == 4)
            {
                for (int i = ind + 1; i <= ind + 2; i++)
                    cout << t[i];

                cout << '-';
                for (int i = ind + 3; i <= ind + 4; i++)
                    cout << t[i];
            }
            else if (sz == 5)
            {
                for (int i = ind + 1; i <= ind + 3; i++)
                    cout << t[i];

                cout << '-';
                for (int i = ind + 4; i <= ind + 5; i++)
                    cout << t[i];
            }
            else if (sz == 6)
            {
                for (int i = ind + 1; i <= ind + 2; i++)
                    cout << t[i];

                cout << '-';
                for (int i = ind + 3; i <= ind + 4; i++)
                    cout << t[i];

                cout << '-';
                for (int i = ind + 5; i <= ind + 6; i++)
                    cout << t[i];
            }
            else
            {
                for (int i = ind + 1; i <= ind + 3; i++)
                    cout << t[i];

                cout << '-';
                for (int i = ind + 4; i <= ind + 5; i++)
                    cout << t[i];

                cout << '-';
                for (int i = ind + 6; i <= ind + 7; i++)
                    cout << t[i];
            }
            cout << endl;
        }
        else printf("Incorrect\n");
    }

    return 0;
}
