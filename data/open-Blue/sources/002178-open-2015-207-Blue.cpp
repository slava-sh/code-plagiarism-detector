#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

vector<int> LockeD;
vector<int> z_func(string s)
{
    vector<int> &z = LockeD;
    z.resize(s.size());
    int l = 0, r = 1;
    for (int i = 1; i < s.size(); ++i)
    {
        z[i] = max(0, min(r - i, z[i - l]));
        while (z[i] + i < s.size() && s[z[i] + i] == s[z[i]]) z[i]++;
        if (z[i] + i > r)
            r = z[i] + i, l = i;
    }
    return z;
}

string s;
vector<int> z, z1;

bool f = 0; string a1, a2;
void apply(int l1, int l2, int sp1, int sp)
{
    if (f)
        return;
    int rp = sp1;
    while (rp < s.size())
        if (z[rp] >= l1)
            rp += l1;
        else if (z1[rp - sp] >= l2)
            rp += l2;
        else
            return;
    f = 1;
    a1 = s.substr(0, l1);
    a2 = s.substr(sp, l2);
}

int a[255];
int main()
{
    int ans, l;
    cin >> l;
    cin >> s;
    if (s.size() <= l)
    {
        cout << 1 << '\n' << s;
        exit(0);
    }
    z = z_func(s);
    for (int r = 1; r <= l; ++r)
    {
        int e = r;
        while (e != s.size() && z[e] >= r)
            e += r;
        if (e == s.size())
            (cout << "1\n" << s.substr(0, r)), exit(0);
        z1 = z_func(s.substr(e, s.size()));
        for (int l2 = z[e] + 1; l2 < s.size() && l2 <= l; ++l2)
        {
            if (z[e + l2] >= r)
                apply(r, l2, e + l2 + r, e);
            if (z1[l2] >= l2)
                apply(r, l2, e + l2 + l2, e);
        }
    }
    if (f)
    {
        cout << "2\n" << a1 << '\n' << a2;
    }
    else
        cout << "3\na\nb\nc";
    return 0;
}
