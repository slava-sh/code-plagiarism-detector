#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

string s;
int n;

bool OK(string s1, string s2, int pos)
{
    vector <bool> dp(n, false);
    int n1 = sz(s1), n2 = sz(s2);
    for (int i = pos; i < n; i++)
    {
        if (i - pos + 1 >= n1)
        {
            bool ok = true;
            for (int j = i; j > i - n1; j--)
                if (s[j] != s1[n1 - 1 + j - i]) {ok = false; break;}
            if (ok && (i - pos == n1 - 1 || dp[i - n1])) dp[i] = true;
        }
        if (i - pos + 1 >= n2)
        {
            bool ok = true;
            for (int j = i; j > i - n2; j--)
                if (s[j] != s2[n2 - 1 + j - i]) {ok = false; break;}
            if (ok && (i  - pos == n2 - 1 || dp[i - n2])) dp[i] = true;
        }
    }
    return dp.back();
}

int main()
{

    int l;
    cin >> l;

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
            for (int i = len; i < n; i++)
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
            for (int i = len; i < n; i++)
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
        string s1 = "";
        for (len = 1; len <= l; len++)
        {
            s1 += s[len - 1];
            if (clock() / CLOCKS_PER_SEC > 0.5) break;
            for (int pos = len; pos < n; pos += len)
            {
                if (clock() / CLOCKS_PER_SEC > 0.5) break;
                string s2 = "";
                bool ok = true;
                for (int j = pos - len; j < pos; j++)
                    if (s[j] != s[j % len]) ok = false;
                if (!ok) break;
                for (int len2 = 1; len2 <= l && pos + len2 <= n; len2++)
                {
                    if (clock() / CLOCKS_PER_SEC > 0.5) break;
                    s2 += s[pos + len2 - 1];
                    if (OK(s1, s2, pos)) {cout << "2\n" << s1 << "\n" << s2 << "\n"; return 0;}
                }
            }
        }
        cout << "3\n";
        if (m[0]) cout << "a\n";
        if (m[1]) cout << "b\n";
        if (m[2]) cout << "c\n";
        return 0;
    }

}


