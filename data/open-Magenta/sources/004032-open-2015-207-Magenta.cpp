#include <iostream>
#include <cmath>
#define s S[H]

using namespace std;

const int S[5] = {20, 300, 2000, 6000, 12000};

int main()
{
    int am1, am2, am;
    char c;
    for (int H = 0; H < 5; ++H)
    {
        am = s, am1 = sqrt(s) + 1, am2 = 1;
        for (int i = 0; i < am; ++i)
        {
            for (int i = 0; i < am1; ++i)
            {
                cout << "U\n";
                if ((cin >> c), c == 'Y')
                    return 0;
                if (c == 'E')
                    return -1;
            }
            for (int i = 0; i < am2; ++i)
            {
                cout << "R\n";
                if ((cin >> c), c == 'Y')
                    return 0;
                if (c == 'E')
                    return -1;
            }
        }
        swap(am1, am2);
        for (int i = 0; i < am; ++i)
        {
            for (int i = 0; i < am1; ++i)
            {
                cout << "U\n";
                if ((cin >> c), c == 'Y')
                    return 0;
                if (c == 'E')
                    return -1;
            }
            for (int i = 0; i < am2; ++i)
            {
                cout << "R\n";
                if ((cin >> c), c == 'Y')
                    return 0;
                if (c == 'E')
                    return -1;
            }
        }
//        am2++;
//        for (int i = 0; i < am; ++i)
//        {
//            for (int i = 0; i < am1; ++i)
//            {
//                cout << "U\n";
//                if ((cin >> c), c != 'N')
//                    return 0;
//            }
//            for (int i = 0; i < am2; ++i)
//            {
//                cout << "R\n";
//                if ((cin >> c), c != 'N')
//                    return 0;
//            }
//        }
//        swap(am1, am2);
//        for (int i = 0; i < am; ++i)
//        {
//            for (int i = 0; i < am1; ++i)
//            {
//                cout << "U\n";
//                if ((cin >> c), c != 'N')
//                    return 0;
//            }
//            for (int i = 0; i < am2; ++i)
//            {
//                cout << "R\n";
//                if ((cin >> c), c != 'N')
//                    return 0;
//            }
//        }
    }
    return 0;
}
