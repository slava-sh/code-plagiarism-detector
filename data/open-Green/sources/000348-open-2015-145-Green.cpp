#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

const int oo = 1e9;
const int nmax = 1100000;
const int kmax = 11;

int d[nmax][kmax];
int n, k;


void read()
{
    fin >> n >> k;
}


int okrvverh(int x)
{
    return x - x / 2;
}


void solve()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
            d[i][j] = oo;
    for (int i = 1; i <= n; i++)
        d[i][1] = i - i / 2;
    for (int i = 0; i < k; i++)
        d[1][i] = 1;
    for (int j = 2; j <= k; j++)
        for (int i = 2; i <= n; i++)
            for (int t = 1; t <= i; t++)
                if (i % t == 0)
                    d[i][j] = min(d[i][j], d[t][j - 1] * okrvverh(i / t));
    fout << d[n][k] << endl;
}


int main()
{
    read();
    solve();
    return 0;
}
