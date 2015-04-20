#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define sc scanf
#define pr printf
#define fi first
#define se second
#define mk make_pair
#define pb push_back

int a[1002][100002], used[1002], p[102];

int cmp (int a, int b)
{
    return a > b;
}
int main()
{
    //freopen ("in.txt", "r", stdin);freopen ("out.txt", "w", stdout);
    freopen ("numbers.in", "r", stdin);freopen ("numbers.out", "w", stdout);
    int i, j, c, k, l, m, n, x, q;
    string s;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> c >> k;
        used[c] = k;
        for (j = 1; j <= k; j++)
            cin >> a[c][j];
    }
    cin >> q;
    for (i = 1; i <= q; i++)
    {
        cin >> s;
        string c = "+";
        k = 0;
        if (s[0] == '0')
        {
            cout << "Incorrect";
            continue;
        }
        for (j = 0; j < s.length(); j++)
        {
            k = k * 10 + s[j] - '0';
            c += s[j];
            if (used[k])
                break;
            if (k > 999)
                break;
        }
        j++;
        if (k > 999 || s[j] == '0')
        {
            cout << "Incorrect\n";
            continue;
        }
        c += "(";
        l = 0;
        for (j = j; j < s.length(); j++)
        {
            l = l * 10 + s[j] - '0';
            c += s[j];
            if (l > 99999)
                break;
            for (x = 1; x <= used[k]; x++)
                if (l == a[k][x])
                    break;
            if (x != used[k] + 1)
                break;
        }
        j++;
        if (l > 99999 || s[j] == '0')
        {
            cout << "Incorrect\n";
            continue;
        }
        c += ")";
        l = s.length() - j;
        m = j;
        if (l == 3)
            for (j = j; j < s.length(); j++)
                c += s[j];
        if (l == 4)
            for (j = j; j < s.length(); j++)
            {
                c += s[j];
                if (j == m + 1)
                    c += "-";
            }
        if (l == 5)
            for (j = j; j < s.length(); j++)
            {
                c += s[j];
                if (j == m + 2)
                    c += "-";
            }
        if (l == 6)
            for (j = j; j < s.length(); j++)
            {
                c += s[j];
                if (j == m + 1)
                    c += "-";
                if (j == m + 3)
                    c += "-";
            }
        if (l == 7)
            for (j = j; j < s.length(); j++)
            {
                c += s[j];
                if (j == m + 2)
                    c += "-";
                if (j == m + 4)
                    c += "-";
            }
        cout << c << endl;
    }
}
