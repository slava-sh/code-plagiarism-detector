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


int log(int i) {
    int k = 0;
    while(i > 1)
        i /= 2, k++;
    return k;
}

int main() {
    must;
    int i, j; char x;
    for(i = 2000 * 2000;; i++) {
        for(j = 1; j <= log(i); j++) {
            cout << "R\n";
            fflush(stdout);
            cin >> x;
            if(x != 'N') {
                return 0;
            }
        }
        cout << "D\n";
        fflush(stdout);
        cin >> x;
        if(x != 'N') {
            return 0;
        }
    }
}
