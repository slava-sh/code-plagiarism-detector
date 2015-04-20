#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(){
    ifstream cin("prizes.in");
    ofstream cout("prizes.out");
    int n,m,k,d;
    cin >> n >> m;
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
    cout << k + d;
}
