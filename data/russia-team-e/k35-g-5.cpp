#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(){
   ifstream cin("prizes.in");
    ofstream cout("prizes.out");
    int n,m;
    cin >> n >> m;
    if(n == 1 || m == 1) {
        if(n > m) swap(n,m);
        m-=2;
        if(m <= 0) cout << 0;
        else cout << (m-1)/4+1;
    }
    else if(n == 2 || m == 2)
        cout << 0;
    else
        cout << 1;
}
