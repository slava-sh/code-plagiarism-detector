/**
 * EASY.
**/

#include <iostream>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <array>
#include <memory.h>
#include <stack>
#include <queue>
#include <deque>
#include <assert.h>


using namespace std;

int geth(int w)
{
    return ceil(300.0 / w);
}

int main()
{
    char in;
    int up = 1;
    for(int i = 1; i <= 300; ++i)
    {
        auto res = geth(i);
        //cout << res << endl;
        for(int j = 0; j < res; ++j)
        {
            if(up % 2 == 1)
                cout << "U" << endl;
            else
                cout << "D" << endl;
            cout.flush();

            cin >> in;
            if(in == 'Y')
                return 0;
            if(in == 'E')
                return 0;
        }
        up = (up + 1) % 2;
        cout << "R" << endl;
        cout.flush();
        cin >> in;
        if(in == 'Y')
            return 0;
        if(in == 'E')
            return 0;
    }
    return 0;
}
