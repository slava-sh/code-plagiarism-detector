#include <iostream>

using namespace std;

int main()
{
    int L;
    cin >> L;
    string s;
    cin >> s;

    bool find2 = false;
    int ii;
     int jj;
     int lenlen;

    if (s.size() <= L)
    {
        cout << 1 << '\n';
        cout << s;
        return 0;
    }
    int n = s.size();

    for (int i = 1; i <= min(L, n - 1); ++i)
    {
        int j = i;
        while (j < n && s[j] == s[j % i])
        {
            j += 1;
        }
        if (j == n && j % i == 0)
        {
            cout << 1 << '\n';
            for (int k = 0; k < i; ++k)
            {
                cout << s[k];
            }
            return 0;
        }
        j -= j % i;
        for (int len = 1; j + len <= s.size() && len <= L; ++len)
        {
            int k = j + len;

            while (true)
            {
                int k1 = k;
                while (k < n && s[k] == s[(k - k1) % len + j])
                {
                    k += 1;
                }
                if (k == n && (k - k1) % len == 0)
                {
                    find2 = true;
                    ii = i;
                    jj = j;
                    lenlen = len;
                    break;
                }
                k -= (k - k1) % len;

                k1 = k;

                while (k < n && s[k] == s[(k - k1) % i])
                {
                    k += 1;
                }
                if (k == n && (k - k1) % i == 0)
                {
                    find2 = true;
                    ii = i;
                    jj = j;
                    lenlen = len;
                    break;
                }
                k -= (k - k1) % i;

                if (k1 == k) break;
            }

        }
    }

    if (find2)
    {
        cout << 2 << '\n';
        for (int i = 0; i < ii; ++i)
        {
            cout << s[i];
        }
        cout << '\n';
        for (int i = jj; i < jj + lenlen; ++i)
        {
            cout << s[i];
        }
        return 0;
    }

    cout << 3 << '\n';
    cout << 'a' << '\n' << 'b' << '\n' << 'c';
    return 0;
}
