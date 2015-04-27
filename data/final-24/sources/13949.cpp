#include <bits/stdc++.h>

using namespace std;

const long long INF = 2e14;
long long n, k, ans = INF;

int l;
string s1, s2, s;


int main()
{
    cin >> l >> s;
    for (int i = 0; i < s.length(); i++)
    {
        s1 += s[i];
        bool t = true;
        int j = 0;
        for (; j <= s.length() - s1.length(); j += s1.length())
        {
            //cout << s1 << ' ' << s.substr(j, s1.length()) << endl;
            if (s1 != s.substr(j, s1.length()))
            {
                t = false;
                break;
            }
        }
        if (j == s.length() && t && s1.length() <= l)
        {
            cout <<  1 << endl << s1;
            return 0;
        }
    }
    cout << 2 << endl << 'a' << endl << 'b';
    return 0;
}
