#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>

using namespace std;

int N, K, C, D;
vector<int> Bad;
vector<vector<long long> > Dyn;
long long Amount;

long long Lazy(int P, int A)
{
    if (P == 0)
    {
        return ((long long)A / (long long)K) * (long long)C;
    }
    else if (Dyn[P][A] != -1)
    {
        return Dyn[P][A];
    }
    else
    {
        long long rez = min(Lazy(P - 1, A + 1), Lazy(P - 1, A) + (long long)Bad[P - 1] * D);
        //cerr << P << " " << A << " " << Bad[P - 1] << endl;
        Dyn[P][A] = rez;
        return rez;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d%d%d%d", &N, &K, &C, &D);
    Bad.resize(N - 1);
    int Start;
    scanf("%d", &Start);
    Amount = 0;
    int l, r;
    for (int i = 0; i < N - 1; ++i)
    {
        scanf("%d%d", &l, &r);
        Amount += (l - Start) * (long long)D;
        Start = r;
        Bad[i] = r - l;
    }
    scanf("%d", &l);
    Amount += (l - Start) * (long long)D;
    //cout << Amount << endl;

    Dyn.resize(N, vector<long long>(N, -1));
/*
    long long Min = 1e18;
    for (int i = 0; i < N; ++i)
    {
        Min = min(Min, Lazy(N - 1, i));
    }
*/

    cout << Amount + Lazy(N - 1, 0) << endl;
/*
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            printf("%lld ", Dyn[i][j]);
        }
        printf("\n");
    }
    printf("\n");
*/
    return 0;
}



