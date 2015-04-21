#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    char r;
    bool fl = true;
    cout << 'R' << '\n';
    while(cin >> r){
        if(r == 'Y' || r == 'E')
            break;
        if(rand() & 1)
            cout << "R\n";
        else
            cout << "U\n";
    }
    return 0;
}
