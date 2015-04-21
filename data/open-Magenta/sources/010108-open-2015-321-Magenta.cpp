#include <iostream>
#include <cstdio>
using namespace std;
char c;
int s;
int main() {
    ios_base::sync_with_stdio(0);
    for (int h=1;h<=30;h++) {
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
    for (int i=1;i<=44;i++) {
        int j=(2000/i);
        cout << "R\n";
        cout.flush();
        cin >> c;
        if (c=='Y') return 0;
        if (c=='E') return 0;
        cout << "D\n";
        cout.flush();
        cin >> c;
        if (c=='Y') return 0;
        if (c=='E') return 0;
        for (int p=1;p<=j;p++) {
            cout << "R\n";
            cout.flush();
            cin >> c;
            if (c=='Y') return 0;
            if (c=='E') return 0;
        }
        for (int p=1;p<=j;p++) {
            cout << "U\n";
            cout.flush();
            cin >> c;
            if (c=='Y') return 0;
            if (c=='E') return 0;
        }
        for (int p=1;p<=j;p++) {
            cout << "D\n";
            cout.flush();
            cin >> c;
            if (c=='Y') return 0;
            if (c=='E') return 0;
        }
    }
    return 0;
}
