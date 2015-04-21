#include <iostream>
#include <cstdio>
using namespace std;
char c;
int main() {
    ios_base::sync_with_stdio(0);
    for (int j=1;j<=301;j++) {
        for (int i=1;i<=301;i++) {
            cout << "D\n";
            cout.flush();
            cin >> c;
            if (c=='Y') return 0;
        }
        cout << "R\n";
    }
    return 0;
}
