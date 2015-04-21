#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

vector <ll> del;
vector <ll> pdel, nrazl;
ll res = INFINITY;
void alldel(int t, ll td)
{
    if (t>=pdel.size())
    {
        del.push_back(td);
        return;
    }
    ll k = 1;
    for (int i=0; i<=nrazl[t]; i++)
    {
        alldel(t+1, td*k);
        k*=pdel[t];
    }
}

ll mires(ll t, ll was, int ld, int toget)
{
    if (toget == 1)
    {
         res = min(res, was * (t + 1) / 2);
    } else {
        long long res = INFINITY;
        for (int i = ld; i<del.size(); i++)
        {
            if (!(t % del[i]))
            {
                mires(t / del[i], was * ((del[i]+1)/2), i, toget - 1);
            }
        }
    }
}



int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ull a, b;
    cin >> a >> b;
    int q = 0;
    ull a1 = a;
    while (!(a1%2))
    {
        a1/=2;
        q++;
    }
    if (q>=b)
    {
        cout << a / pow(2, b);
        return 0;
    }
    a1 = a;
    int i = 2;
    while (i*i<=a1 && a1>=1)
    {

        if (!(a1%i))
        {
            pdel.push_back(i);
            nrazl.push_back(0);
            while (!(a1%i))
            {
                a1/=i;
                nrazl[nrazl.size()-1]++;
            }
        }
        i++;
    }
    if (a1>1)
    {
        pdel.push_back(a1);
        nrazl.push_back(1);
    }
    alldel(0, 1);
    mires(a, 1, 0, b);
    cout << res;

}
