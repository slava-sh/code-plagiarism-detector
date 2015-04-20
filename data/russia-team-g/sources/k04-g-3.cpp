#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    freopen("prizes.in", "r", stdin);
    freopen("prizes.out", "w", stdout);
    int n, m, k;
    cin>>n>>m;
    if(n > m)swap(n, m);
    if(n == 1)swap(n, m);
    if(n == 2)swap(n, m);
    k = n / 4;
    if(n == 4 * k + 3)cout<<k + 1;
    else if(n == 4 * k + 2)cout<<k;
    else if(n == 4 * k + 1)cout<<k;
    else if(n == 4 * k)cout<<k;
    return 0;
}
