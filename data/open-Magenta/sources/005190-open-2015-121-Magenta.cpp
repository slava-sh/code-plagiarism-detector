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
    while (true)
    {
        for (int i = 0; i < 6000 / tmp_c; i++)
        {
            cout << 'R' << endl;
            cout.flush();
            cin >> c;
            if (c == 'E' || c == 'Y')
            {
                return 0;
            }
        }
        cout << 'D' << endl;
        tmp_c++;
        cin >> c;
        if (c == 'E' || c == 'Y')
        {
            return 0;
        }
    }
}
