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
    char now_c = 'D';
    int last_c = 1;
    int tmp_c = 0;
    int ep = 0;
    while (!is_good)
    {
        cout << now_c << endl;
        cout.flush();
        last_c--;
        if (last_c == 0)
        {
            if (ep == 0)
            {
                tmp_c++;
                now_c = 'R';
                last_c = tmp_c;
            }
            else if (ep == 1)
            {
                now_c = 'D';
                last_c = 1;
            }
            else if (ep == 2)
            {
                now_c = 'L';
                last_c = tmp_c;
            }
            else
            {
                now_c = 'D';
                last_c = 1;
            }
            ep = (ep + 1) % 4;
        }
        char c;
        cin >> c;
        if (c == 'E' || c == 'Y')
        {
            is_good = true;
        }
    }
}
