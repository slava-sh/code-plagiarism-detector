#include <iostream>
#include <cstdio>

using namespace std;

int cl[300001];
int cr[300001];
int ct[300001];
const int INF = 1e-9 + 7;

void refresh(int i){
    cl[i] = cl[2 * i];
    cr[i] = cr[2 * i + 1];
    bool b = cr[2 * i] == cl[2 * i + 1];
    ct[i] = ct[2 * i] + ct[2 * i + 1] - b;
}

void add(int p, int x, int l, int r, int i){
    if (l == r - 1){
        cl[i] = cr[i] = x;
        ct[i] = 1;
        return;
    }
    int m = (l + r) / 2;
    if (p >= m){
        add(p, x, m, r, 2 * i + 1);
    }
    else{
        add(p, x, l, m, 2 * i);
    }
    refresh(i);
}

int main()
{
    #ifdef DEBUG
    freopen("input.txt", "r", stdin);
    #endif // DEBUG
    for (int i = 0; i <= 300000; i++){
        cr[i] = cl[i] = -INF;
        ct[i] = 1;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int c;
        cin >> c;
        add(i, c, 0, n, 1);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++){
        int p, x;
        cin >> p >> x;
        add(p - 1, x, 0, n, 1);
        cout << ct[1] << endl;
    }
    return 0;
}
