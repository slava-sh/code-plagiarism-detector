#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int a[1000000];
    int n, m;

int Bi(int x){
    int l2 = -1;
    int r2 = n;
    while (l2 < r2 - 1){
        int m1 = (l2 + r2) / 2;
        if (a[m1] < x){
            l2 = m1;
        } else {
            r2 = m1;
        }
    }
    return r2;
}

int main()
{
    freopen ("game.in", "r", stdin);
    freopen ("game.out", "w", stdout);
    cin >> n >> m;
    int l, r;
    int l1, r1;
    cin >> l >> r;
    cin >> l1 >> r1;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int z = Bi(l);
    sort(a, a + n);
    int y = Bi(r);
    int ans1 = y - z + 1;

    int q = Bi(l1);
    int w = Bi(r1);
    int ans2 = w - q + 1;

    l = max(l,l1);
    r = min(r,r1);
    int ans3 = Bi(r)-Bi(l)+1;

    int i = (ans3+1)/2 + ans1 - ans3;
    int j = (ans3)/2 + ans2-ans3;
    i = min(i,(m+1)/2);
    j = min(j,m / 2);
    if (i>j) {cout<<"Petya"<<endl;}
    if (i==j) {cout<<"Draw"<<endl;}
    if (i<j) {cout<<"Vasya"<<endl;}
    return 0;
}
