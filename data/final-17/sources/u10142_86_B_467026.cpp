#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
#include <string>
#include <utility>
using namespace std;

#define pb push_back
#define sz(v) ((int)v.size())
#define mp make_pair

typedef long long ll;
typedef double lf;

char Area[1000+10][1000+10];
int C[1000+10][1000+10];
int N,M;

bool Check(int i, int j, char c) {
    if (Area[i][j] == 'c')
        return false;
    if (Area[i][j] != '.')
        return true;
    Area[i][j] = '-';
    bool r = true;
    if (Area[i+1][j] == c || Area[i-1][j] == c || Area[i][j-1] == c || Area[i][j+1] == c)
        return false;
    if (C[i+1][j] == C[i][j]) {
        r &= Check(i+1,j,c);
    }
    if (C[i-1][j] == C[i][j]) {
        r &= Check(i-1,j,c);
    }
    if (C[i][j+1] == C[i][j]) {
        r &= Check(i,j+1,c);
    }
    if (C[i][j-1] == C[i][j]) {
        r &= Check(i,j-1,c);
    }
    return r;
}

void reset(int i, int j, char c1,char c2) {
    if (Area[i][j] != c1)
        return;
    Area[i][j] = c2;
    if (C[i+1][j] == C[i][j]) {
        reset(i+1,j,c1,c2);
    }
    if (C[i-1][j] == C[i][j]) {
        reset(i-1,j,c1,c2);
    }
    if (C[i][j+1] == C[i][j]) {
        reset(i,j+1,c1,c2);
    }
    if (C[i][j-1] == C[i][j]) {
        reset(i,j-1,c1,c2);
    }
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ios::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        scanf("%s",Area[i] + 1);
    for (int i = 0; i <= N+1; ++i)
        C[i][0] = C[i][M+1] = -1;
    for (int j = 0; j <= M+1; ++j)
        C[0][j] = C[N+1][j] = -1;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            if (Area[i][j] == '#')
                C[i][j] = -1;

    int c = 1;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j) {
            if (C[i][j] != 0)
                continue;
            if (C[i-1][j] + C[i+1][j] + C[i][j-1] + C[i][j+1] == -4) {
                cout << -1;
                return 0;
            }

            if (C[i][j+1] == 0) {
                C[i][j] = C[i][j+1] = c;
                ++c;
            }
            else if (C[i+1][j] == 0) {
                C[i][j] = C[i+1][j] = c;
                ++c;
            }
            else {
                if (C[i][j+1] != -1) {
                    C[i][j] = C[i][j+1];
                    ++c;
                }
                else if (C[i+1][j] != -1) {
                    C[i][j] = C[i+1][j];
                    ++c;
                }
                else if (C[i-1][j] != -1) {
                    C[i][j] = C[i-1][j];
                    ++c;
                }
                else if(C[i][j-1] != -1) {
                    C[i][j] = C[i][j-1];
                    ++c;
                }
            }
        }
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j) {
            if (Area[i][j] != '.')
                continue;
            for (c = '0'; c <= '9'; ++c) {
                if (Check(i,j,c)) {
                    reset(i,j,'-',c);
                    break;
                }
                reset(i,j,'-','.');
            }
        }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j)
            cout << Area[i][j];
        cout << "\n";
    }




    

    return 0;
}
