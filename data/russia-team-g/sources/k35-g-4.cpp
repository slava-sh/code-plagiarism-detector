#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int f(int n, int m) {
    int k,d;
    if(m >= 2) d = 0;
    else {
        d = 1;
        n-=2;
        if(n <= 0) d = 0;
        d+=(n-1)/4;
    }
    k = 1;
    m-=2;
    if(m <= 0) k = 0;
    k+=(m-1)/4;
    return k+d;
}
int main(){
   ifstream cin("prizes.in");
    ofstream cout("prizes.out");
    int n,m;
    cin >> n >> m;
    cout << min(f(n,m),f(m,n));
}
