#include <iostream>
using namespace std;
     
const int N = 2000001;   
int b[N], a[N];
int        m, lvl, x, l, r, n, i;

void modify(int x, int y)
{
        a[x] = y;
        x = x / 2;
        while (x != 0) {
                a[x] = a[2 * x] + a[2 * x + 1];
                x = x / 2;
        }
}

void update(int x, int y)
{
        b[x] = y;
        x = x / 2;
        while (x != 0) {
                b[x] = b[2 * x] + b[2 * x + 1];
                x = x / 2;
        }
}

int FindAns(int l, int r, int a1, int b, int t)
{
        if ((l > b) || (r < a1)) {
                return 0;
        }
        if ((l >= a1) && (r <= b)) {
                        return a[t];
        }
        return FindAns(l, (l + r) / 2, a1, b, 2 * t) + FindAns((l + r) / 2 + 1, r, a1, b, 2 * t + 1);
}

int FindAns1(int l, int r, int a1, int b1, int t)
{
        if ((l > b1) || (r < a1)) {
                return 0;           
        }
        if ((l >= a1) && (r <= b1)) {
                        return b[t];
        }
        return FindAns1(l, (l + r) / 2, a1, b1, 2 * t) + FindAns1((l + r) / 2 + 1, r, a1, b1, 2 * t + 1);
}

int main()
{
        cin >> (n);
        lvl = 1;
        while (lvl < n) lvl = lvl + lvl;
        for (int i = 1; i <= n; i++) {
                cin >> (x);
                if (i % 2 == 0) 
                        modify(lvl + i - 1, x);
                else
                        update(lvl + i - 1, x);
        }
        cin >> (m);
        for (int i = 1; i <= m; i++) {
                cin >> x >> l >> r;
                if (x == 0) {
                        if (l % 2 == 0) 
                            modify(lvl + l - 1, r);
                        else
                            update(lvl + l - 1, r);
                }
                else {
                        if (l % 2 == 1) 
                                cout << (FindAns1(lvl,lvl+lvl-1,lvl+l-1,lvl+r-1,1) - FindAns(lvl,lvl+lvl-1,lvl+l-1,lvl+r-1,1)) << endl;
                        else
                                cout << (FindAns(lvl,lvl+lvl-1,lvl+l-1,lvl+r-1,1) - FindAns1(lvl,lvl+lvl-1,lvl+l-1,lvl+r-1,1)) << endl;
                }                        
        }
}
