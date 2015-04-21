#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>

using namespace std;

long long N, K;

long long Count(long long Num, long long Curr, int Left)
{
    if (Left == 1)
    {
        return (Num + 1) / 2;
    }
    else if (Num == 1)
    {
        return 1;
    }

    //printf("%d %d\n", Num, Curr);
    long long Border = (long long)(sqrt(Num));
    long long Rez = (Num + 1) / 2;
    while (Curr <= Border)
    {
        if (Num % Curr == 0)
        {
            Rez = min(Rez, (((Num / Curr) + 1) / 2) * Count(Curr, Curr, Left - 1));
            Rez = min(Rez, ((Curr + 1) / 2) * Count((Num / Curr), Curr, Left - 1));
        }
        ++Curr;
    }
    return Rez;
}

int main()
{
    scanf("%d%d", &N, &K);
/*
    int Good = 0;
    long long Curr = N;
    while (Curr % 2 == 0)
    {
        ++Good;
        Curr /= 2;
    }

    if (Good >= K)
    {
        Curr = N;
        for (int i = 0; i < K; ++i)
        {
            Curr /= 2;
        }
        cout << Curr << endl;
        return 0;
    }
    else
    {
        Curr = N;
        for (int i = 0; i < Good; ++i)
        {
            Curr /= 2;
        }
        cout << Count(Curr, 2, K - Good) << endl;
        return 0;
    }*/

    cout << Count(N, 2, K) << endl;
}
