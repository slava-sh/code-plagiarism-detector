#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    freopen("prizes.in", "rt", stdin);
freopen("prizes.out", "w", stdout);

    int n = 2, m = 2, c = 0;

    int temp;

    cin >> n >> m;
    //while(m < (int)1e9)
    //{
        if (m == 1)
    {
        cout << ((n + 1) / 4) << endl;
        return 0;
        //c = ((n + 1) / 4);
        //m++;
        //continue;
    }

    if (n == 1)
    {
        cout << ((m + 1) / 4) << endl;
        return 0;
       //c = ((m + 1) / 4);
       //m++;
       //continue;
    }

    if (n >= 3 && m >= 3)
    {
        cout << 1 << endl;
        return 0;
    }
    else
    {
        cout << 0 << endl;

    }
    //}

    return 0;
}
