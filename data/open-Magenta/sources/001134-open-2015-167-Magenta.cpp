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

void f(int n){
    char c;
    for (int ii = 1; ii <= n; ii++){
        int t = n / ii;
        for (int i = 1; i < t; i++){
            cout << "R\n";
            fflush(stdout);
            cin >> c;
            if (c == 'Y')
                exit(0);
        }
        cout << "U\n";
        fflush(stdout);
        cin >> c;
        if (c == 'Y')
            exit(0);
    }
}

int main(){
    for (int i = 50; i <= 1000; i += 100)
        f(i);
    f(1000);
    f(2000);
    f(3000);
    f(6000);
    return 0;
}
