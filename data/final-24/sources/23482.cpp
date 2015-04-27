#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

bool d[10000];
string s;

bool eq(string t, int l, int r)
{
    for (int i = l; i <= r; i++)
        if (t[i - l] != s[i])
            return false;
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    cin >> s;
    int qa = 0, qb = 0, qc = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'a')
            qa = 1;
        else if (s[i] == 'b')
            qb = 1;
        else if (s[i] == 'c')
            qc = 1;

    for (int i = 1; i <= min(n, (int)s.size()); i++)
        {
            fill(d, d + s.size() + 1, false);
            string t1, t2;
            d[0] = true;
            for (int k = 0; k < i; k++)
                t1 += s[k];
            //cout << t1 << " " << t2 << endl;
            for (int k = 1; k <= s.size(); k++)
                if (k >= t1.size() && d[k - (int)t1.size()] && eq(t1, k - t1.size(), k - 1))
                    d[k] = true;
            if (d[s.size()])
            {
                cout << 1 << endl;
                cout << t1;
                return 0;
            }
        }

    //cout << 2 << endl << "a" << endl << "b" << endl;
    //return 0;
    if (qa + qb + qc == 2) {
        cout << 2 << endl;
        if (qa)
            cout << "a" << endl;
        if (qb)
            cout << "b" << endl;
        if (qc)
            cout << "c" <<endl;
        return 0;
    }

    for (int i = 1; i <= min(n, (int)s.size()); i++)
        for (int j = 1; j <= min(n, (int)s.size()); j++)
        for (int fs = 0; fs < s.size(); fs += i)
        {
            if (j + i + fs > s.size())
                continue;
            fill(d, d + s.size() + 1, false);
            string t1, t2;
            d[0] = true;
            for (int k = 0; k < i; k++)
                t1 += s[k];
            for (int k = 0; k < j; k++)
                t2 += s[k + i + fs];
            //cout << t1 << " " << t2 << endl;
            for (int k = 1; k <= s.size(); k++)
                if (k >= t1.size() && d[k - (int)t1.size()] && eq(t1, k - t1.size(), k - 1))
                    d[k] = true;
                else if (k >= t2.size() && d[k - (int)t2.size()] && eq(t2, k - t2.size(), k - 1))
                    d[k] = true;
            if (d[s.size()])
            {
                if (t1 == t2)
                {
                    cout << 1 << endl << t1;
                    return 0;
                }
                cout << 2 << endl;
                cout << t1 << endl << t2;
                return 0;
            }
        }
    cout << 3 << endl << "a" << endl << "b" << endl << "c";
}
