#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <queue>
typedef long long ll;
typedef long double ld;
using namespace std;
int main()
{
    ll n, a = 0, b = 0;
    cin >> n;
    string s;
    cin >> s;
    for ( int i = 0; i < s.size(); i++)
        if ( s[i] == 'a' )
            a++;
        else
            if ( s[i] == 'b')
            b++;
    if (a > 0 && b > 0 )
    {

        cout << 2 << endl << "a" << endl << "b";
        return 0;
    }

        if ( a > 0 && b == 0)
        {

            cout << 1 << endl << "a";
            return 0;
        }
            if ( a == 0 &&  b > 0)
            {

                cout << 1 << endl << "b";
                return 0;
            }
            cout << 0;
    return 0;
}
