#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

const int nmax = 110000;

int t[nmax], pos[nmax], nt[nmax];
int n, m, kol;


void read()
{
    fin >> n;
    for (int i = 0; i < n; i++)
        fin >> t[i];
    fin >> m;
    for (int i = 0; i < m; i++)
    {
        fin >> pos[i] >> nt[i];
        pos[i]--;
    }
}


void answer(int pos, int nt)
{
    int was = 0;
    if ((pos > 0) && (t[pos] != t[pos - 1]))
        was++;
    if ((pos < n - 1) && (t[pos] != t[pos + 1]))
        was++;
    t[pos] = nt;
    int now = 0;
    if ((pos > 0) && (t[pos] != t[pos - 1]))
        now++;
    if ((pos < n - 1) && (t[pos] != t[pos + 1]))
        now++;
    kol += now - was;
    fout << kol << endl;
}


void solve()
{
    kol = 1;
    for (int i = 1; i < n; i++)
        if (t[i] != t[i - 1])
            kol++;
    for (int i = 0; i < m; i++)
        answer(pos[i], nt[i]);
}


int main()
{
    read();
    solve();
    return 0;
}
