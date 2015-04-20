#include <iostream>
#include <map>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    freopen("names.in","r",stdin);
    freopen("names.out","w",stdout);
    int n;
    cin >> n;
    map <string, int> a;
    string f[n], fn[n], sn[n];
    for (int i = 0; i < n; i++)
    {
        cin >> f[i] >> fn[i] >> sn[i];
        a[f[i]]++;
        a[fn[i]]++;
        a[sn[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[f[i]] > 1)
        {
            string fc = sn[i], fnc = f[i], snc = fn[i];
            f[i] = fc; fn[i] = fnc; sn[i] = snc;
        }
    }
    string s[n];
    for (int i = 0; i < n; i++)
    {
        s[i] = f[i] + " " + fn[i] + " " + sn[i];
    }
    sort (s, s + n);
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << endl;
    }
    return 0;
}
