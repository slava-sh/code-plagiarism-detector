#include <iostream>
#include <cstdio>
using namespace std;
char c;
int s;
int main() {
    ios_base::sync_with_stdio(0);
    int x=1;
    for (;x<9;x++) {
        for (int i=1;i<=x;i++) {
            cout << "U\n";
            cout.flush();
            cin >> c;
            if (c=='Y') return 0;
            if (c=='E') return 0;
        }
        for (int i=1;i<=x;i++) {
            cout << "R\n";
            cout.flush();
            cin >> c;
            if (c=='Y') return 0;
            if (c=='E') return 0;
        }
        x++;
        for (int i=1;i<=x;i++) {
            cout << "D\n";
            cout.flush();
            cin >> c;
            if (c=='Y') return 0;
            if (c=='E') return 0;
        }
        for (int i=1;i<=x;i++) {
            cout << "L\n";
            cout.flush();
            cin >> c;
            if (c=='Y') return 0;
            if (c=='E') return 0;
        }
    }
    for (int i=1;i<=44;i++) {
        int j=2000/i;
        s+=2*j*i;
        for (int k=1;k<=i;k++) {
            for (int p=1;p<=j;p++) {
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
        for (int k=1;k<=i;k++) {
            for (int p=1;p<=j;p++) {
                cout << "R\n";
                cout.flush();
                cin >> c;
                if (c=='Y') return 0;
                if (c=='E') return 0;
            }
            cout << "D\n";
            cout.flush();
            cin >> c;
            if (c=='Y') return 0;
            if (c=='E') return 0;
        }

    }
    return 0;
}
