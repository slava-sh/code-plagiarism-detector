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
long long Amount;

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

    sort(Bad.rbegin(), Bad.rend());

    long long Curr = 1e18;
    int Ind = K - 1;

    while (Ind < N - 1)
    {
        Curr = 0;
        for (int i = 0; i < K and Ind < N - 1; ++i)
        {
            Curr += Bad[Ind] * (long long)D; ++Ind;
        }
        if (Curr > C)
        {
            Amount += C;
        }
        else
        {
            Amount += Curr;
        }
    }

    cout << Amount << endl;

    return 0;
}



