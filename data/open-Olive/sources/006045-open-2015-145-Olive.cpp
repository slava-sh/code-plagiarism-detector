#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

const int nmax = 5500;

int lessleft[nmax][nmax];
int p[nmax];
int n;



void read()
{
    fin >> n;
    for (int i = 0; i < n; i++)
        fin >> p[i];
}


void solve()
{
    for (int i = 0; i < n; i++)
    {
        int kol = 0;
        for (int j = 0; j <= i; j++)
        {
            if (p[j] < p[i])
                kol++;
            lessleft[i][j] = kol;
        }
    }
    int maxx = -1;
    int l = -1;
    int r = -1;
    for (int i = 0; i < n; i++)
    {
        int kolmore = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (p[i] > p[j])
            {
                int cur = j - i - kolmore - (lessleft[j][j] - lessleft[j][i]);
                if (cur > maxx)
                {
                    maxx = cur;
                    l = i + 1;
                    r = j + 1;
                }
            }
            if (p[j] > p[i])
                kolmore++;
        }
    }
    fout << l << ' ' << r << endl;
}


int main()
{
    read();
    solve();
    return 0;
}
