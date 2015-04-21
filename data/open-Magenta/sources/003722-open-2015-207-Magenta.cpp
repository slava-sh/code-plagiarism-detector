#include <iostream>
#include <cmath>
#define s S[H]

using namespace std;

const int S[4] = {20, 300, 2000, 6000};

int main()
{
    int am1, am2, am;
    char c;
    for (int H = 0; H < 4; ++H)
    {
        am = s, am1 = sqrt(s), am2 = 1;
        for (int i = 0; i < am; ++i)
        {
            for (int i = 0; i < am1; ++i)
            {
                cout << "U\n";
                if ((cin >> c), c != 'N')
                    return 0;
            }
            for (int i = 0; i < am2; ++i)
            {
                cout << "R\n";
                if ((cin >> c), c != 'N')
                    return 0;
            }
        }
        swap(am1, am2);
        for (int i = 0; i < am; ++i)
        {
            for (int i = 0; i < am1; ++i)
            {
                cout << "U\n";
                if ((cin >> c), c != 'N')
                    return 0;
            }
            for (int i = 0; i < am2; ++i)
            {
                cout << "R\n";
                if ((cin >> c), c != 'N')
                    return 0;
            }
        }
    }
    return 0;
}
