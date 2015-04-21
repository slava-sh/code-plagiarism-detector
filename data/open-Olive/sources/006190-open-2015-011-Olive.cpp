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
vector<vector<int> > Count;

int main()
{
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d", &N);

    Nums.resize(N);
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &Nums[i]);
    }

    Count.resize(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
    {
        int Amount = 0;
        for (int j = 0; j < N; ++j)
        {
            if (Nums[j] < Nums[i])
            {
                ++Amount;
            }
            Count[i][j] = Amount;
        }
    }

    int Min = 0, Best_L = -1, Best_R = -1, Curr;
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            Curr = Count[i][i] + Count[j][j] - Count[i][j] - Count[j][i];
            if (Curr < Min)
            {
                Min = Curr;
                Best_L = i + 1;
                Best_R = j + 1;
            }
        }
    }

    printf("%d %d\n", Best_L, Best_R);
}




