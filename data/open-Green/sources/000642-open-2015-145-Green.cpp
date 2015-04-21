#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

const int oo = 1e9;
const int nmax = 1100000;
const int kmax = 11;

int d[nmax][kmax];
vector<int> v;
int n, k, m;


void read()
{
    fin >> n >> k;
}


void gener_div()
{
    v.push_back(0);
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0)
        {
            v.push_back(i);
            if (i * i != n)
                v.push_back(n / i);
        }
    sort(v.begin(), v.end());
    m = v.size() - 1;
    /*for (int i = 0; i <= m; i++)
        fout << v[i] << ' ';
    fout << endl;*/
}


int okrvverh(int x)
{
    return x - x / 2;
}


void solve()
{
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= k; j++)
            d[i][j] = oo;
    for (int i = 1; i <= m; i++)
        d[i][1] = v[i] - v[i] / 2;
    for (int i = 0; i <= k; i++)
        d[1][i] = 1;
    for (int j = 2; j <= k; j++)
        for (int i = 2; i <= m; i++)
            for (int t = 1; t <= i; t++)
                if (v[i] % v[t] == 0)
                {
                    d[i][j] = min(d[i][j], d[t][j - 1] * okrvverh(v[i] / v[t]));
                    //fout << "d[" << i << "][" << j << "] min= d[" << t << "][" << j - 1 << "] * okrvverh(v[" << i << "] / v[" << t << "])" << endl;
                }
    //assert(d[n][k] <= n);
    fout << d[m][k] << endl;
}


int main()
{
    read();
    gener_div();
    solve();
    return 0;
}
