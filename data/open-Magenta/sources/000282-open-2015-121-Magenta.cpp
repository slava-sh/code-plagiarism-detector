#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    bool is_good = false;
    char now_c = 'U';
    int last_c = 1;
    int tmp_c = 1;
    while (!is_good)
    {
        cout << now_c << endl;
        cout.flush();
        last_c--;
        if (last_c == 0)
        {
            if (now_c == 'R' || now_c == 'L') tmp_c++;
            last_c = tmp_c;
            if (now_c == 'U')
            {
                now_c = 'R';
            }
            else if (now_c == 'R')
            {
                now_c = 'D';
            }
            else if (now_c == 'D')
            {
                now_c = 'L';
            }
            else
            {
                now_c = 'U';
            }
        }
        char c;
        cin >> c;
        if (c == 'E' || c == 'Y')
        {
            is_good = true;
        }
    }
}
