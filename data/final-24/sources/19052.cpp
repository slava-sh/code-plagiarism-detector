#include <iostream>
#include <cstdio>
#include <map>

using namespace std;
const long long mod = 1e6 + 7, osn = 13, maxn = 1000000;
long long f[maxn], st[maxn], h[maxn];
map <long long, int> d;
int main()
{
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int l0;
    cin >> l0;
    string s;
    cin >> s;
    st[0] = 1;
    int n = s.length();
    for (int i = 1; i <= n; i++)
    {
        st[i] = (st[i - 1] * osn) % mod;
    }
    for (int i = 0; i < n; i++)
    {
        h[i + 1] = (st[i] * (s[i] - 'a' + 1)) % mod;
        h[i + 1] = (h[i] + h[i + 1]) % mod;
    }
    for (int i = 1; i <= l0; i++)
    {
        int fl = 0, fl2 = 0, fl4 = 1;
        long long first = 0;
        for (int j = 1; j <= n; j++) f[j] = 0;
        for (int j = i; j <= n; )
        {
            long long h1 = (h[j] - h[j - i] + mod) % mod;
            h1 = (h1 * st[n - j + i]) % mod;
            d[h1]++;
            if (d[h1] == 1)
            {
                if (fl == 0)
                {
                    first = h1;
                    fl = 1;
                }
                else
                {
                    fl2 = 1;
                    j++;
                    continue;
                }
            }
            if (j == n)
            {
                fl4 = 0;
            }
            f[j] = 1;
            j += i;
        }
        fl2 |= fl4;
        if (fl2 == 0)
        {
            for (int i = 1; i <= n; i++)
                {
                    if (!f[i]) continue;
                }
            cout << "1\n";
            for (int j = 0; j < i; j++)
            {
                cout << s[j];
            }
            return 0;
        }
        d.clear();
    }
    for (int i = 1; i <= l0; i++)
    {
        d.clear();
        int fl = 0, fl2 = 0, fl4 =1;
        long long first = 0;
        for (int j = 1; j <= n; j++) f[j] = 0;
        for (int j = i; j <= n; )
        {
            long long h1 = (h[j] - h[j - i] + mod) % mod;
            h1 = (h1 * st[n - j + i]) % mod;
            d[h1]++;
            if (d[h1] == 1)
            {
                if (fl == 0)
                {
                    first = h1;
                    fl = 1;
                }
                else
                {
                    fl2 = 1;
                    j++;
                    continue;
                }
                if (j == n)
                {
                    fl4 = 0;
                }
            }
            f[j] = 1;
            j += i;
        }

            int l = 0, r = 0;
            for (int j = i; j <= n; j += i)
            {
                if (f[j] == 0)
                {
                    l  = j - i + 1;
                    break;
                }
            }
            for (int j = l; j <= n; j++)
            {
                if (f[j] == 1)
                {
                    r = j - i;
                    break;
                }
                if (j == n)
                {
                    r = j;
                    break;
                }
            }
            long long h2 = (h[r] - h[l - 1] + mod) % mod;
            h2 = (h2 * st[n - l + 1]) % mod;
            int len = r - l + 1, fl3 = 0;
            if (len > l0) continue;
            int j;
            for (j = 0; j < n; )
            {
                long long h1 = (h[j + i] - h[j] + mod) % mod;
                h1 = (h1 * st[n - j]) % mod;
                if (h1 != first)
                {
                    h1 = (h[j + len] - h[j] + mod) % mod;
                    h1 = (h1 * st[n - j]) % mod;
                    if (h1 != h2)
                    {
                        fl3 = 1;
                        break;
                    }
                }
                if (h1 == first)
                {
                    j += i;
                }
                else
                {
                    j += len;
                }
            }
            if (!fl3 && j == n)
            {
                for (int i = 1; i <= n; i++)
                {
                    if (!f[i]) continue;
                }
                cout << "2\n";
                for (int j = l - 1; j < r; j++)
                {
                    cout << s[j];
                }
                cout << endl;
                 for (int j = 0; j < i; j++)
                {
                    cout << s[j];
                }

                return 0;
            }

        d.clear();

    }
    cout << "3\na\nb\nc\n";
    return 0;
}
