#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

const long long M = 4242424243;
const long long p = 31;

int main()
{
    string txt;
    int n;
    cin >> n;
    cin >> txt;
    int l = txt.size();
    n = min(l, n);
    long long h[l + 1];
    h[0] = 0;
    long long p1[l + 1];
    p1[0] = 31;
    for (int i = 1; i < l; i++)
        p1[i] = (p1[i - 1] * p) % M;
    for (int i = 1; i <= l; i++)
        h[i] = (h[i - 1] * p + txt[i - 1] - 'a' + 1) % M;
    for (int wl = n; wl > 0; wl--)
    {
        if (l % wl == 0)
        {
            bool a = true;
            for (int i = wl; i <= l; i += wl)
                a = a && (h[wl] == (h[i] - (h[i - wl] * p1[wl - 1]) % M + M) % M);
            if (a)
            {
                cout << 1 << endl;
                for (int i = 0; i < wl; i++)
                    cout << txt[i];
                cout << endl;
                return 0;
            }
        }
    }
    cout << "2\na\nb";
    return 0;
}
