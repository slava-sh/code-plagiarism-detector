/**
 * “¿Ÿ»Ã
**/

#include <iostream>
#include <stdio.h>
#include <sstream>
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

int a[100000];


using namespace std;

int n, m;

bool ok_left(int i)
{
    if(i == 0)
        return true;
    return a[i] == a[i - 1];
}

bool ok_right(int i)
{
    if(i == n - 1)
        return true;
    return a[i] == a[i + 1];
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    int ans = 1;
    for(int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        a[i]= t;
        if(i > 0 and a[i] != a[i - 1])
            ++ans;
    }
    //cout << ans << "!" << endl;
    cin >> m;
    for(int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        --x;
        bool pl = ok_left(x);
        bool pr = ok_right(x);
        //cout << a[x] << endl;
        a[x] = y;
        //cout << "NOW " << a[x] << endl;
        bool nl = ok_left(x);
        bool nr = ok_right(x);

        //cout << (pl ? 1 : 0) << " " << (pr ? 1 : 0) << " " << (nl ? 1 : 0) << " " << (nr ? 1 : 0) << endl;

        if(pl and not nl)
            ++ans;
        else if(not pl and nl)
            --ans;

        if(pr and not nr)
            ++ans;
        else if(not pr and nr)
            --ans;

        cout << ans << endl;
    }
    return 0;
}
