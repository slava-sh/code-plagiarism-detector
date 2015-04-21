#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <map>
#include <stdlib.h>

using namespace std;

int a[1000010];
int more[1000010];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        a[i] -= 1;
    }
    for (int i = 0; i < n; ++i)
    {
        more[i] = 0;
        for (int j = 0; j < i; ++j)
        {
            if (a[j] > a[i])
            {
                more[i] += 1;
            }
        }
    }
    int answi = -2;
    int answj = -2;
    int num = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (a[i] < a[j]) continue;
            int num1 = -1;
            for (int k = i + 1; k < j; ++k)
            {
                if (a[k] > a[i]) num1 += 1;
                if (a[k] > a[j]) num1 -= 1;
            }
            if (num1 < num)
            {
                num = num1;
                answi = i;
                answj = j;
            }
        }
    }

    cout << answi + 1 << ' ' << answj + 1;

    return 0;
}


