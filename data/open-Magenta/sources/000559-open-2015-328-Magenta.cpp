#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    char r;
    bool fl = true;
    cout << 'R';
    while(cin >> r){
        if(r == 'Y' || r == 'E')
            return 0;
        if(!fl)
            cout << 'R';
        else
            cout << 'U';
        fl ^= true;
        cout.flush();
    }
    return 0;
}
