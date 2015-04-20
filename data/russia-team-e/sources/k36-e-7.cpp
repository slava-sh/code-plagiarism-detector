#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>
#include <time.h>
#include <cassert>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

#define FORN(i, n) for(int i=0; i<n; i++)
#define FORI(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a-1; i>=b; i--)
#define fi first
#define se second
#define mp make_pair

int n;
string mas[105];
vector < string > m[105];

void out(string s) {
    if ( s.size()%2 == 1 ) {
        cout << s.substr(0, 3);
        s.replace(0, 3, "");
    }
    while (s.size()) {
        cout << "-" << s.substr(0, 2);
        s.replace(0, 2, "");
    }
    cout << endl;
}

bool check(string s) {
    string tmp;
    FORN(i, n) {
        tmp = s;
        if ( mas[i][0] == '0' ) continue;
        if ( tmp.size() >= mas[i].size() && tmp.substr(0, mas[i].size()) == mas[i] ) {
            tmp.replace(0, mas[i].size(), "");
            if ( tmp[0] == '0' )
                return 0;
            FORN(j, m[i].size()) {
                if ( tmp.size() >= m[i][j].size() && tmp.substr(0, m[i][j].size()) == m[i][j]) {
                    tmp.replace(0, m[i][j].size(), "");
                    if ( tmp[0] == '0' )
                        return 0;
                    else {
                        cout << "+" << mas[i] << "(" << m[i][j] << ")";
                        out(tmp);
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int main () {
    freopen ("numbers.in", "r", stdin);
    freopen ("numbers.out", "w", stdout);

    cin >> n;

    int c;
    string tmp;
    FORN(i, n) {
        cin >> mas[i] >> c;
        FORN(j, c) {
            cin >> tmp;
            if ( tmp[0] != '0' )
                m[i].push_back(tmp);
        }
    }

    int y;
    cin >> y;
    FORN(i, y) {
        cin >> tmp;
        if ( !check(tmp) )
            cout << "Incorect" << endl;
    }

    return 0;
}
/*
1
996 8
770
550
700
7777
7
77
77777
77777
8
99677002345
99655012345
99670012345
99677771234
99677777123
99677123456
99671234567


2
7 3
981
3517
812
351 3
34712
1234
963
8
79818266456
35196328463
78122472557
01234567890
73517960326
35134712239
35112342013
78120203040

*/
