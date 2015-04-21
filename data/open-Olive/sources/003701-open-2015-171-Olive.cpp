#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;



int main()
{
    srand(time(NULL));
    int i, j, s;
    char c;
    vector<char> p1, p2;
    for (i = 0; i < 5; i++)
    {
            p1.push_back((i % 2 == 0 ? 'L' : 'U'));
    }
    for (i = 0; i < 1; i++)
    {
        p2.push_back('R');
    }
    i = p1.size();
    while (true)
    {
        if (i == p1.size())
            {
                if (rand()%2 == 0) swap(p1, p2);
                i = 0;
            }
        cout << p1[i] << endl;
        i++;
        cout.flush();
        cin >> c;
        if (c != 'N') return 0;
    }
    return 0;
}
