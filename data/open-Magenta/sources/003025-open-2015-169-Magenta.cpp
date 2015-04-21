#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;

void next_dir(char &dir, int &sz)
{
    if(dir == 'R')
        dir = 'D';
    else if(dir == 'D')
    {
        dir = 'L';
        sz++;
    }
    else if(dir == 'L')
        dir = 'U';
    else if(dir == 'U')
    {
        dir = 'R';
        sz++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int sz = 1, cnt = 0;
    char dir = 'R';

    while(1)
    {
        cout << dir << endl;
        cnt++;
        if(cnt == sz)
        {
            next_dir(dir, sz);
            cnt = 0;
        }
        char verdict;
        cin >> verdict;
        if(verdict == 'Y' || verdict == 'E')
            break;
    }
    return 0;
}
