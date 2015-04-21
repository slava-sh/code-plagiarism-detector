#include <bits/stdc++.h>

using namespace std;

#define lol long long
#define fi first
#define se second
#define pb push_back
#define sz(s) (int)s.size()
#define must ios_base::sync_with_stdio(0)

#define inp(s) freopen(s, "r", stdin)
#define out(s) freopen(s, "w", stdout)

int fib[100];

int main() {
    must;
    int a, b, i, j, kol;
    char x;
    fib[0] = fib[1] = 1;
    for(i = 2; i <= 20; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    a = 1, b = 0;
    i = 1; kol = fib[1];
    do {
        if(a == 1) {
            cout << "R\n";
            kol--;
        } else {
            cout << "D\n";
            kol--;
        }
        if(kol == 0) {
            if(a == 1)
                a = 0, b = 1;
            else
                a = 1, b = 0;
            i++, kol = fib[i];
        }
        fflush(stdout);
    } while(cin >> x && x == 'N');

}
