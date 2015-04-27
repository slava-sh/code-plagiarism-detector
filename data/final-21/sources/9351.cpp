#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int N = 100010*2, P = 31;

int len, n, m;
long long pref[N], suf[N], p[N];
string ss;

int Solution(string);

void Input()
{
    ifstream in("inventory.in");
    ofstream out("inventory.out");

    in >> m;
    for (int i = 0; i < m; i++) {
        in >> ss;
        ss += ss;
        out << Solution(ss) << "\n";
    }
    in.close();
    out.close();
}

int Solution(string s)
{
    n = s.length() / 2;
    len = s.length();
    suf[0] = s[len - 1] - 'a' + 1;
    pref[0] = s[0] - 'a' + 1;

    //cout << s << "\n";

    for (int i = 1; i < len; i++) {
        pref[i] = pref[i - 1] * P + (s[i] - 'a' + 1);
    }

    for (int i = 1; i < len; i++) {
        suf[i] = suf[i - 1] * P + (s[len - i - 1] - 'a' + 1);
    }

    for (int i = 0; i < n; i++) {
        int l = i, r = i + n - 1;
        long long h1;
        long long h2;
        if (i != 0) h1 = pref[r] - pref[l - 1] * p[n];
        else        h1 = pref[r];

        h2 = suf[len - l - 1] - suf[len - n - i - 1] * p[n];
        //cout << h1 << " " << h2 << "\n";
        //cout << r << " " << l-1 << " " << len -l - 1 << " " << len - n - i - 1 << "\n";
        if (h1 == h2) return i;
    }
    return -1;
}

void Init()
{
    p[0] = 1;
    for (int i = 1; i <= 200000; i++)
        p[i] = p[i - 1] * P;
}

void Output()
{
    ofstream out("inventory.out");

    out.close();
}

int main()
{
    Init();
    Input();
    //Solution();
    //Output();
    return 0;
}

