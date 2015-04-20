#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    freopen("sochi.in", "r", stdin);
    freopen("sochi.out", "w", stdout);
    int k = 0, i, d, n, s = 0, s1 = 0, x, m1 = 0, m2 = 0;
    cin>>n>>d;
    for(i = 0; i < n; i ++){
        cin>>x;
        s1 += x;
        if(x >= 3 * d){k ++;}
        else if(x >= 2 * d && x < 3 * d){
            if(x > m1){m2 = m1; m1 = x;}
            else if(x > m2)m2 = x;
        }
        else s += x;
        }
    s = s1 - s;
    if(m1)k ++;
    if(m2)k ++;
    cout<<s - 2 * d * (k - 1);
    return 0;
}
