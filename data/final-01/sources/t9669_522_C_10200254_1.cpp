#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <cstdio>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <cctype>
#include <set>
#include <map>

using namespace std;

const int MK = 1e5;
const int oo = 1e9;

int XX[MK];
bool res[MK];
int YY[MK];
int posl[MK];

int main(int argc, char* argv[]) {
    int t; cin >> t;
    while (t--)
    {
        int mm;
        int car;
        int countx = 0;
        int county = 0;
        int fb = -1;
        cin >> mm >> car;
        for (int i = 0; i < car; i++)
        {
            cin >> XX[i];  YY[i] = 0; posl[i] = -1; res[i] = 0;
        }
        for (int i = 0; i < mm - 1; i++) {
            int t;
            int r;
            cin >> t >> r;  t--;
            if (t == -1) countx++;
            else { posl[t] = i;      YY[t]++;       }
            if (r == 1
            &&
            fb == -1)
                fb = i;
            if (t == -1
            &&
            fb == -1)  county++;
        }
        if (fb == -1)
            for (int i = 0; i < car; i++)if (XX[i] - YY[i] <= countx)res[i] = 1;
        else {
            int mn = oo;
            for (int i = 0; i < car; i++)
                if (posl[i] < fb && XX[i] - YY[i] <= county) {res[i] = 1;mn = min(XX[i] - YY[i], mn);}
            for (int i = 0; i < car; i++)if (!res[i] && XX[i] - YY[i] <= countx - mn)res[i] = 1;
        }
        for (int i = 0; i < car; i++)cout << (res[i] ? "Y" : "N");
        cout << endl;
    }
}
