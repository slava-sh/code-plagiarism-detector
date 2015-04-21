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
    int tmp_c = 0;
    char c;
    vector<int> v;
    v.push_back(6000);
    for (int i = 2; i <= 6000; i++)
    {
        if (6000 / i != v[v.size() - 1])
        {
            v.push_back(6000 / i);
        }
    }
    tmp_c = v.size() - 1;
    while (true)
    {
        for (int i = 0; i < 6000 / v[tmp_c]; i++)
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
        tmp_c--;
        cin >> c;
        if (c == 'E' || c == 'Y')
        {
            return 0;
        }
    }
}
