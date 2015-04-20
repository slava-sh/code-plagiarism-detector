#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    //freopen("prizes.in", "r", stdin);
    //freopen("prizes.out", "w", stdout);
    int n, m, k;
    cin>>n>>m;
    if(n == 2 || m == 2){cout<<0;return 0;}
    if(n == 1 && m == 1){cout<<0;return 0;}
    if(n == 1 || n > m){
            k = m / 4;
            if(m == 4 * k + 3)cout<<k + 1;
            else cout<<k;
            return 0;
    }
    if(m == 1 || n <= m){
        k = n / 4;
        if(n == 4 * k + 3)cout<<k + 1;
        else cout<<k;
        return 0;
    }
    return 0;
}
