#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>

using namespace std;

int N, K;

int Count(int Num, int Curr, int Left)
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
    int Border = int(sqrt(Num));
    int Rez = (Num + 1) / 2;
    while (Curr <= Border)
    {
        int Curr_Num = Num, Pow = 1;
        while (Curr_Num % Curr == 0)
        {
            Curr_Num /= Curr;
            Pow *= Curr;
            Rez = min(Rez, ((Pow + 1) / 2) * Count(Curr_Num, Curr + 1, Left - 1));
        }
        ++Curr;
    }
    return Rez;
}

int main()
{
    scanf("%d%d", &N, &K);

    int Good = 0, Curr = N;
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
        printf("%d\n", Curr);
        return 0;
    }
    else
    {
        Curr = N;
        for (int i = 0; i < Good; ++i)
        {
            Curr /= 2;
        }
        printf("%d\n", Count(Curr, 3, K - Good));
        return 0;
    }
}
