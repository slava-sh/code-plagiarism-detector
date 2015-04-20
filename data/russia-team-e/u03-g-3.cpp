#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <algorithm>
using namespace std;
int max(long a, long b)
{
    if (a < b) return a;
       else return b;
    
    }
 
int main(){
   freopen("prizes.in","r",stdin);
    freopen("prizes.out","w",stdout);
    int n ,m;
    cin >> n >> m;
   if(n>m){int c = n; n = m; m = c;}
    if(n <= 2 && m <= 2){cout << 0; return 0;}
    if(n == 1 || m ==1) {m = max(m, n); cout << (m-3)/4 +1; return 0; }
        
    cout << 1;
    return 0;
}
