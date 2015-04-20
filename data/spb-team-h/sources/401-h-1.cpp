#include <bits\stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef long long ll;

struct name
{
    string fam;
    string nam;
    string otch;

    name()
    {

    }

    name(string _f, string _n, string _o)
    {
        fam = _f;
        nam = _n;
        otch = _o;
    }
};

bool operator < (const name &left, const name &right)
{
    return left.fam < right.fam;
}

void solve(int n)
{
    map<string, int> cnt;

    vector<string> f(n), s(n), t(n);
    for (int i = 0; i < n; i++)
        cin >> f[i] >> s[i] >> t[i];

    for (int i = 0; i < n; i++)
    {
        cnt[f[i]]++;
        cnt[s[i]]++;
        cnt[t[i]]++;
    }

    vector<name> srt;

    for (int i = 0; i < n; i++)
    {
        if (cnt[f[i]] == 1)
            srt.pb(name(f[i], s[i],  t[i]));
        else
            srt.pb(name(t[i], f[i], s[i]));
    }

    sort(srt.begin(), srt.end());
    for (int i = 0; i < n; i++)
        cout << srt[i].fam << ' ' <<
        srt[i].nam << ' ' << srt[i].otch << endl;
}

int main()
{
   // freopen("input.txt", "rt", stdin);
   // freopen("output.txt", "w", stdout);
    freopen("names.in", "rt", stdin);
    freopen("names.out", "w", stdout);

    int n;
    while (cin >> n)
        solve(n);
}
