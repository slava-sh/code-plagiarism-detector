#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <map>
#include <stdlib.h>

using namespace std;

const int inf = 1E9 + 100;

int t[100100];

int main()
{
    int N;
    cin >> N;
    int num = 0;
    t[0] = -inf;
    t[N + 1] = -inf - 10;
    for (int i = 1; i <= N; ++i)
    {
        cin >> t[i];
        if (t[i] != t[i - 1]) num += 1;
    }
    int Q;
    cin >> Q;
    for (int iii = 0; iii < Q; ++iii)
    {
        int pos, nw;
        cin >> pos >> nw;
        if (t[pos] == nw)
        {
            cout << num << '\n';
            continue;
        }
        if (t[pos - 1] == t[pos + 1])
        {
            if (t[pos] == t[pos + 1])
            {
                num += 2;
            }
            else
            {
                if (nw == t[pos + 1])
                {
                    num -= 2;
                }
            }
        }
        else
        {
            if (t[pos] == t[pos + 1])
            {
                if (nw != t[pos - 1])
                {
                    num += 1;
                }
            }
            else
            {
                if (t[pos] == t[pos - 1])
                {
                    if (nw != t[pos + 1])
                    {
                        num += 1;
                    }
                }
                else
                {
                    if (nw == t[pos - 1] || nw == t[pos + 1])
                    {
                        num -= 1;
                    }
                }
            }
        }

        t[pos] = nw;
        cout << num << '\n';
    }
    return 0;
}

