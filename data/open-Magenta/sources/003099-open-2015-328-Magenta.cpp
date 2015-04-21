#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    char r;
    cout << "D\n";
    while(cin >> r){
        if(r == 'Y' || r == 'E')
            return 0;
        int s = rand()%4;
        if(s == 1)
            cout << "R\n";
        if(s == 2)
            cout << "L\n";
        if(s == 3)
            cout << "U\n";
        if(s == 0)
            cout << "D\n";
        cout.flush();
    }
    return 0;
}
