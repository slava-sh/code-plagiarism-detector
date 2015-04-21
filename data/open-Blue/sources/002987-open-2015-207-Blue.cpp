#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

void z_func(int *Z, char *s, int size)
{
    int l = 0, r = 1;
    for (int i = 1; i < size; ++i)
    {
        Z[i] = max(0, min(r - i, Z[i - l]));
        while (Z[i] + i < size && s[Z[i] + i] == s[Z[i]]) Z[i]++;
        if (Z[i] + i > r)
            r = Z[i] + i, l = i;
    }
}

int n;
char s[30000];
int z[30000], z1[30000];

bool f = 0; string a1, a2;
void apply(int l1, int l2, int sp1, int sp)
{
    if (f)
        return;
    int rp = sp1;
    if (z[n - l1] != l1 && z1[n - sp - l2] != l2)
        return;
    if (n % __gcd(l1, l2) != 0)
        return;
    while (rp < n)
        if (z[rp] >= l1)
            rp += l1;
        else if (z1[rp - sp] >= l2)
            rp += l2;
        else
            return;
    f = 1;
    for (int i = 0; i < l1; ++i)
        a1.push_back(s[i]);
    for (int i = sp; i < l2; ++i)
        a2 += s[i];
}

int a[255];
int main()
{
    int ans, l = 10000;
    cin >> l;
    string s1 = "a", s2 = "bc", s;
    cin >> s;
//    for (int i = 0; i < 19; ++i)
//        swap(s1 += s2, s2);
//    s = s2 + 'c';
//    cout << (n = s.size()) << '\n';
//    if (s.size() <= l)
//    {
//        cout << 1 << '\n' << s;
//        exit(0);
//    }
    n = s.size();
    for (int i = 0; i < n; ++i)
        ::s[i] = s[i];
    z_func(z, ::s, n);
    for (int r = 1; r <= l; ++r)
    {
        int e = r;
        while (e != n && z[e] >= r)
            e += r;
        if (e == n)
            (cout << "1\n" << s.substr(0, r)), exit(0);
        z_func(z1, ::s + e, n - e);
        for (int l2 = z[e] + 1; l2 < n - e && l2 <= l; ++l2)
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
