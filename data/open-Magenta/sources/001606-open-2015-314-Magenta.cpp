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
    return ceil(6000.0 / w);
}

int main()
{
    char in;
    int up = 1;
    for(int i = 1; i <= 6000; ++i)
    {
        auto res = geth(i);
        for(int j = 0; j < res; ++j)
        {
            if(up % 2 == 1)
                cout << "U" << endl;
            else
                cout << "D" << endl;
            up = (up + 1) % 2;
            cin >> in;
            if(in == 'Y')
                return 0;
            if(in == 'E')
                return 0;
        }
        cout << "R" << endl;
    }
    return 0;
}
