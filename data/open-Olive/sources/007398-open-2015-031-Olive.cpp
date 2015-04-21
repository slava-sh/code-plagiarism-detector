#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <map>
#include <stdlib.h>

using namespace std;

int a[1000010];
int b[1000010];

int f(int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << b[i] << ' ';
    }
    int answ = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            if (b[j] == i)
            {
                for (int k = j; k > i; --k)
                {
                    b[k] = b[k - 1];
                    answ += 1;
                }
                b[i] = i;
                break;
            }
        }
    }
    cout << answ << '\n';
    return answ;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        a[i] -= 1;
        b[i] = a[i];
    }

    int num = f(n);

    int answi = -2;
    int answj = -2;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                b[k] = a[k];
            }
            swap(b[i], b[j]);
            int num1 = f(n);
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


