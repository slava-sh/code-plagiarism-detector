#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct node {
    int x, y;
};

node a[1010];
int p[1010];

bool cmp (node x, node y){
    return x.y < y.y;
}

int pay (int k, int l){
    if (k > 0) {
        int i;
        i = (a[k - 1].x - p[k - 2] - l + 2) / 2;
        if (i < 0) {
            i = 0;
        }
        return pay(k - 1,i + l) + i * a[k - 1].y;
    }
    return 0;
}

int main()
{
    freopen ("conquest.in", "r", stdin);
    freopen ("conquest.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i].x >> a[i].y;
    }
    sort(a, a + n, cmp);
    p[0] = a[0].x;
    for (int i = 1; i < n; i++){
        p[i] = p[i - 1] + a[i].x;
    }
    cout << pay(n, 0) << endl;
    return 0;
}
