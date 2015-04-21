#include <iostream>
#include <cstdio>
using namespace std;
char c;
int s;
int main() {
    ios_base::sync_with_stdio(0);

    for (int i=1;i<=44;i++) {
        int j=2000/i;
        for (int k=1;k<=j;k++) {
            for (int p=1;p<=i;i++) {
                cout << "D\n";
                cout.flush();
                cin >> c;
                if (c=='Y') return 0;
                if (c=='E') return 0;
            }
            cout << "R\n";
            cout.flush();
            cin >> c;
            if (c=='Y') return 0;
            if (c=='E') return 0;
        }
        for (int k=1;k<=j;k++) {
            for (int p=1;p<=i;i++) {
                cout << "R\n";
                cout.flush();
                cin >> c;
                if (c=='Y') return 0;
                if (c=='E') return 0;
            }
            cout << "U\n";
            cout.flush();
            cin >> c;
            if (c=='Y') return 0;
            if (c=='E') return 0;
        }

    }
    return 0;
}
