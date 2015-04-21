#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>

using namespace std;

int N;
vector<int> Nums;
vector<int> Count;

int main()
{
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d", &N);

    Nums.resize(N);
    Count.resize(N);
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &Nums[i]);
        Count[i] = max(0, i + 1 - Nums[i]);
        //printf("%d ", Count[i]);
    }
    //printf("\n");

    int Min = 0, Best_L = -1, Best_R = -1, Delta;
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            Delta = max(0, j + 1 - Nums[i]) + max(0, i + 1 - Nums[j]) - (Count[i] + Count[j]);
            //printf("%d %d %d\n", i, j, Delta);
            if (Delta < Min)
            {
                Min = Delta;
                Best_L = i + 1;
                Best_R = j + 1;
            }
        }
    }

    printf("%d %d\n", Best_L, Best_R);
}




