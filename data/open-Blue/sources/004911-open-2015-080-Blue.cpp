#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
const int N = 1e5;
const ull MOD = 1e9 + 7;
using namespace std;
string s;
int mal;
ull hsh[N];
ull st[N];


void mkhsh()
{
    ull th = 0, tst = 1;
    for (int i=0; i<s.size(); i++)
    {
        th = (th * 3 + s[i] - 'a') % MOD;
        hsh[i] = th;
        st[i] = tst;
        tst = (tst * 3) % MOD;
    }

}

ull gh(int from, int to)
{
    if (from == 0) return hsh[to];
    return (hsh[to] - (hsh[from - 1] * st[to - from + 1]) % MOD + MOD) % MOD;
}

string re, re1;

int try1()
{
    for (int i = 1; i <= min(mal, (int)s.size()); i++)
    if (!(s.length() % i))
    {
        int f = 1;
        for (int t = 0; f && t<s.size(); t+=i)
        {
            if (!(gh(t, t + i - 1) == gh(0, i-1))) {f = 0;}
        }
        if (f)
        {
            re = s.substr(0, i);
            return 1;
        }
    }
    return 0;
}

int try2()
{
    for (int i=1; i<=min(mal, (int)s.size()); i++)
        for (int ss = i; (gh(0, i-1) == gh(ss - i, ss-1)) && ss<s.size(); ss+=i)
        for (int j=1; j<=min(mal, (int)s.size() - ss
                             ); j++)
            {
           //     cout << i << "  " << ss << " " << j << " " << s.substr(0, i) << " " << s.substr(ss, j) << "\n";
                int dyn[N] = {};
                dyn[i - 1] = 1;
                dyn[ss + j - 1] = 1;
                for (int q = 0; q < s.size(); q++)
                {
                    if (q-i >= 0)dyn[q] = dyn[q] || ((gh(0, i-1) == gh(q - i + 1, q)) && dyn[q-i]);
                    if (q-j >= 0)dyn[q] = dyn[q] || ((gh(ss, ss+j-1) == gh(q - j + 1, q)) && dyn[q-j]);
             //       cout << "    " << q << " " << dyn[q] << "\n";
                }
                if (dyn[s.size()-1])
                {
                    re = s.substr(0, i);
                    re1 = s.substr(ss, j);
                    return 1;
                }
            }

    return 0;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);


    cin >> mal;
    cin >> s;
    mkhsh();
  //  cout << gh(28, 28);
    if (try1())
    {
        cout << "1\n";
        cout << re;
        return 0;
    }
    if (try2())
    {
        cout << "2\n";
        cout << re << "\n" << re1;
        return 0;
    }
    cout << "3\na\nb\nc";


}
