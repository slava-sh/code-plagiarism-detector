#include <iostream>
#include <string>

using namespace std;

string s;

int main()
{
    int l;
    cin >> l;
    cin >> s;
    int n = s.length();
    for (int i = 1; i <= l; i++)
    {
        if (n % i == 0)
        {
            bool c = true;
            for (int j = i; j < n; j++)
            {
                if (s[j] != s[j - i])
                    c=false;
            }
            if (c)
            {
                string t;
                for (int j = 0; j < i; j++)
                {
                    t += s[j];
                }
                cout << 1 << endl << t;
                return 0;
            }
        }
    }
    for (int i = 1; i <= l; i++)
    {
        for (int j = 1; j <= l; j++)
        {
            string t1, t2;
            t1 = s.substr(0, i);
            int t2e1 = i;
            while (s[t2e1] == s[t2e1 - i])
            {
                t2e1++;
            }
            t2e1 = t2e1/i*i;
            t2 = s.substr(t2e1, j);
            bool cf[n + 1];
            for (int k = 0; k < t2e1 + 1; k++)
            {
                if (k % i == 0)
                    cf[k] = true;
                else
                    cf[k] = false;
            }
            for (int k = t2e1 + 1; k < t2e1 + j; k++)
            {
                cf[k] = false;
            }
            cf[t2e1 + j] = true;
            for (int k = t2e1+j+1; k <= n;k++)
            {
                cf[k] = (s.substr(k - i, i) == t1&&cf[k - i])||(s.substr(k - j, j) == t2&&cf[k - j]);
            }
            if (cf[n])
            {
                cout << 2 << endl << t1 << endl << t2;
                return 0;
            }
        }
    }
    cout << "3\na\nb\nc";
    return 0;
}
