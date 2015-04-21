#include <iostream>
#include <cstdio>
using namespace std;
char c;
int s;
int main() {
    ios_base::sync_with_stdio(0);
    for (int h=1;h<=77;h++) {
        if (h%2==1) {
            cout << "R\n";
            cout.flush();
            cin >> c;
            if (c=='Y') return 0;
            if (c=='E') return 0;
            for (int j=1;j<=h;j++) {
                cout << "D\n";
                cout.flush();
                cin >> c;
                if (c=='Y') return 0;
                if (c=='E') return 0;
            }
            for (int j=1;j<=h;j++) {
                cout << "L\n";
                cout.flush();
                cin >> c;
                if (c=='Y') return 0;
                if (c=='E') return 0;
            }
        }
        else {
            cout << "D\n";
            cout.flush();
            cin >> c;
            if (c=='Y') return 0;
            if (c=='E') return 0;
            for (int j=1;j<=h;j++) {
                cout << "R\n";
                cout.flush();
                cin >> c;
                if (c=='Y') return 0;
                if (c=='E') return 0;
            }
            for (int j=1;j<=h;j++) {
                cout << "U\n";
                cout.flush();
                cin >> c;
                if (c=='Y') return 0;
                if (c=='E') return 0;
            }
        }
    }
    for (int i=1;i<=77;i--) {
        int j=6000/i;
        s+=2*j*i;
        for (int k=1;k<=j-1;k++) {
            for (int p=1;p<=i-1;p++) {
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
        for (int k=1;k<=j-1;k++) {
            for (int p=1;p<=i-1;p++) {
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
