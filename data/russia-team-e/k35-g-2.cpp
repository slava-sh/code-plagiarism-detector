#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int f(int n, int m) {
    int k,d;
    if(m >= 2) d = 0;
    else {
        d = 1;
        n-=3;
        if(n < 0) d = 0;
        d+=n/4;
    }
    k = 1;
    m-=3;
    if(m < 0) k = 0;
    k+=m/4;
    return k+d;
}
int main(){

    ifstream cin("prizes.in");
    ofstream cout("prizes.out");
    int n,m;
    cin >> n >> m;
    cout << min(f(n,m),f(m,n));
}
