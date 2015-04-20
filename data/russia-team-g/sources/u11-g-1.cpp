#include <iostream>
#include <stdio.h>
using namespace std;
int max(int a,  int b){return a > b ? a : b;}
int main()
{
	 freopen("prizes.in","r",stdin);
    freopen("prizes.out","w",stdout);
    int n ,  m ; 
    cin >> n >> m;
    if(n == 2 || m == 2)
    cout << "0";
    else 
    if(n == 1 || m == 1){
    cout << (max(n,m)+1)/4;
    }
    else cout << "1";

    getchar();getchar();
}


