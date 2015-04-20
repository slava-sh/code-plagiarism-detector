#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(){
    freopen ("abcd.in", "r", stdin);
    freopen ("abcd.out", "w", stdout);
    int n, a, b, c, d;
    string s;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> s;
        a = s[0] - 'a';
        b = s[1] - 'a';
        c = s[2] - 'a';
        d = s[3] - 'a';
        if (((a * 10 + b) * (a * 10 + b) + (c * 10 + d) * (c * 10 + d)) % 7 == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
