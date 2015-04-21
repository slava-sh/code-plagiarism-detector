#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
const int N = 3e5;
using namespace std;
int n, m, d;
vector <int> reb[N], temp[N], os[N];
vector <int> pos[N];

int zapr(int a, int b)
{
    queue <int> t, nst, te, ost;
    for (int i=0; i<reb[a].size(); i++)
    {
        t.push(reb[a][i]);
        nst.push(1);
        te.push(temp[a][i]);
        ost.push(os[a][i]);
    }
    while (t.size() && (t.front()!=b))
    {
        int _t = t.front(), _nst = nst.front(), _temp = te.front(), _ost = ost.front();
        t.pop();
        nst.pop();
        te.pop();
        ost.pop();
     //   cerr << _t + 1 << " " << _nst << " " << _temp << " " << _ost << "\n";
        for (int i = _ost; i>=0 && !pos[_t][i] && _temp - temp[_t][i] <= d; i--)
        {
            t.push(reb[_t][i]);
            nst.push(_nst + 1);
            te.push(temp[_t][i]);
            ost.push(os[_t][i]);
            pos[_t][i] = 1;
        }
        for (int i = _ost + 1; i<reb[_t].size() && !pos[_t][i] && (temp[_t][i] - _temp <= d); i++)

        {
            t.push(reb[_t][i]);
            nst.push(_nst + 1);
            te.push(temp[_t][i]);
            ost.push(os[_t][i]);
            pos[_t][i] = 1;
        }
    }

    if (t.size()==0) return -1; else
        return nst.front();
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m >> d;

    for (int i=0; i<m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        reb[a-1].push_back(b-1);
        reb[b-1].push_back(a-1);
        temp[a-1].pb(c);
        temp[b-1].pb(c);
        os[a-1].pb((int)reb[b-1].size()-1);
        os[b-1].pb((int)reb[a-1].size()-1);
        pos[a-1].push_back(0);
        pos[b-1].push_back(0);
    }

    int q;
    cin >> q;

    for (int i=0; i<q; i++)
    {
        int h, j;
        cin >> h >> j;
        for (int l=0; l<n; l++)
            for (int k=0; k<pos[l].size(); k++)
                pos[l][k] = 0;
        cout << zapr(h-1, j-1) << "\n";
    }

    return 0;
}
