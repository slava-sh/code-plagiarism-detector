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
    int last_c = 6000;
    int tmp_c = 1;
    char c;
    while (!is_good)
    {
        cout << 'D' << endl;
        cout.flush();
        last_c--;
        if (last_c == 0)
        {
            tmp_c++;
            last_c = 6000 / tmp_c;
            cin >> c;
            if (c == 'E' || c == 'Y')
            {
                return 0;
            }
            cout << 'R' << endl;
            cout.flush();
        }
        cin >> c;
        if (c == 'E' || c == 'Y')
        {
            return 0;
        }
    }
}
