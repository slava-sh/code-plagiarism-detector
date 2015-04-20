#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    freopen("sochi.in", "r", stdin);
    freopen("sochi.out", "w", stdout);
    int m = 0, k = 0, i, d, n, s = 0, m1 = 0, m2 = 0, x;
    cin>>n>>d;
    for(i = 0; i < n; i ++){
        cin>>x;
        if(x >= 3 * d){s += x; k ++;}
        if(x < 3 * d && x >= 2 * d){
            if(m1 < x){m2 = m1; m1 = x;}
            else if(m2 < x)m2 = x;
        }
    }
    s += m1 + m2;
    if(m1)k++;
    if(m2)k++;
    cout<<s - 2 * d * (k - 1);
    return 0;
}
