#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int main()
{

    int l, n;
    cin >> l;

    string s;
    cin >> s;

    n = sz(s);

    int m[3] = {0, 0, 0};
    for (int i = 0; i < n; i++)
        m[s[i] - 'a'] = 1;

    if (m[0] + m[1] + m[2] == 1)
    {
        cout << "1\n";
        if (m[0]) cout << "a\n";
        if (m[1]) cout << "b\n";
        if (m[2]) cout << "c\n";
        return 0;
    }

    if (m[0] + m[1] + m[2] == 2)
    {
        int len;
        for (len = 1; len <= l; len++)
            if (n % len == 0)
        {
            bool ok = true;
            for (int i = l; i < n; i++)
                if (s[i] != s[i % len]) {ok = false; break;}
            if (ok) break;
        }
        if (len <= l)
        {
            cout << "1\n";
            for (int i = 0; i < len; i++)
                cout << s[i];
            cout << "\n";
            return 0;
        }
        else
        {
            cout << "2\n";
            if (m[0]) cout << "a\n";
            if (m[1]) cout << "b\n";
            if (m[2]) cout << "c\n";
            return 0;
        }
    }

    if (m[0] + m[1] + m[2] == 3)
    {
        int len;
        for (len = 1; len <= l; len++)
            if (n % len == 0)
        {
            bool ok = true;
            for (int i = l; i < n; i++)
                if (s[i] != s[i % len]) {ok = false; break;}
            if (ok) break;
        }
        if (len <= l)
        {
            cout << "1\n";
            for (int i = 0; i < len; i++)
                cout << s[i];
            cout << "\n";
            return 0;
        }
        else
        {
            cout << "3\n";
            if (m[0]) cout << "a\n";
            if (m[1]) cout << "b\n";
            if (m[2]) cout << "c\n";
            return 0;
        }
    }

}


