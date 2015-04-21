#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <map>
#include <stdlib.h>

using namespace std;

int main()
{
    while (true)
    {
        int num = rand() % 50;
        while (num != 0)
        {
            cout << "U\n";
            cout.flush();
            char c;
            cin >> c;
            if (c == 'Y' || c == 'E') return 0;
            cout << "R\n";
            cout.flush();
            cin >> c;
            if (c == 'Y' || c == 'E') return 0;
            num -= 1;
        }
        cout << "U\n";
        cout.flush();
        char c;
        cin >> c;
        if (c == 'Y' || c == 'E') return 0;
    }
    return 0;
}
