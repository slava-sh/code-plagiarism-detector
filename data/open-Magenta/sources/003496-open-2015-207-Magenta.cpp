#include <iostream>

using namespace std;

//const int p[5] = {2, 3, 5, 7, 11};

int main()
{
    int am1 = 2, am2 = 3;
    char c;
    while (1)
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
        am1 += am2, am2 += am1;
    }
    return 0;
}
