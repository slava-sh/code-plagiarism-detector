#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cstdlib>

#define mp make_pair
#define ll long long
#define ld long double
#define pii pair <int, int>

using namespace std;

const int N = (int)5e5 + 7;
const ll INF = (ll)1e9 + 7;
const ld EPS = 1e-9;


int main()
{
    char c;
    int n = 6000;
    for (int ii = 1; ii <= n; ii++){
        int t = n / ii;
        for (int i = 0; i < t; i++){
            cout << "R\n";
            fflush(stdout);
            cin >> c;
            if (c == 'Y')
                return 0;
        }
        cout << "U\n";
        fflush(stdout);
        cin >> c;
        if (c == 'Y')
            return 0;
    }
    return 0;
}
