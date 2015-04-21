#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <functional>
#include <cassert>
#include <sstream>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a,b,n,x,y,z,c[405];
int X[405][405], Y[405][405];

int ticks = 0;
void TL() {
    if(++ticks == 1000) {
        ticks = 0;
        if ((double)clock() >= 1.9 * CLOCKS_PER_SEC) { printf("Yes\n"); exit(0); }
    }
}

int main()
{
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    scanf("%d%d%d",&a,&b,&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&c[i]);
        for (int j = 0; j <= c[i]; ++j)
            scanf("%d%d",&X[i][j],&Y[i][j]);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ///TL();
            int pa = 0, pb = 0;
            int curx = a;
            bool a_higher = false, b_higher = false;
            for (; pa + 1 < c[i] || pb + 1 < c[j]; ) {
                ll A1 = Y[i][pa] - Y[i][pa+1];
                ll B1 = -X[i][pa] + X[i][pa+1];
                ll C1 = -A1 * X[i][pa] - B1* Y[i][pa];

                ll A2 = Y[j][pb] - Y[j][pb+1];
                ll B2 = -X[j][pb] + X[j][pb+1];
                ll C2 = -A2 * X[j][pb] - B2* Y[j][pb];

                ll XA1 = X[i][pa], XA2 = X[i][pa+1];
                ll YA1 = Y[i][pa], YA2 = Y[i][pa+1];

                ll XB1 = X[j][pb], XB2 = X[j][pb+1];
                ll YB1 = Y[j][pb], YB2 = Y[j][pb+1];

                if (XA1 >= XB1 && XA1 <= XB2) {
                    ld new_y = ld(-C2 - A2 * XA1) / ld(B2);
                    if (new_y > YA1) b_higher = true;
                    else if (new_y < YA1) a_higher = true;
                }

                if (XA2 >= XB1 && XA2 <= XB2) {
                    ld new_y = ld(-C2 - A2 * XA2) / ld(B2);
                    if (new_y > YA2) b_higher = true;
                    else if (new_y < YA2) a_higher = true;
                }

                if (XB1 >= XA1 && XB1 <= XA2) {
                    ld new_y = ld(-C1 - A1 * XB1) / ld(B1);
                    if (new_y > YB1) a_higher = true;
                    else if (new_y < YB1) b_higher = true;
                }

                if (XB2 >= XA1 && XB2 <= XA2) {
                    ld new_y = ld(-C1 - A1 * XB2) / ld(B1);
                    if (new_y > YB2) a_higher = true;
                    else if (new_y < YB2) b_higher = true;
                }

                if (a_higher && b_higher) break;

                if (pa + 2 == c[i] && pb + 2 == c[j]) break;
                if (pa + 2 == c[i]) ++pb;
                else if (pb + 2 == c[j]) ++pa;
                else {
                    if (X[i][pa + 1] > X[j][pb]) ++pb;
                    else ++pa;
                }
            }
            if (a_higher && b_higher) { printf("No\n%d %d",i+1,j+1); return 0; }
        }
    }
    printf("Yes");

    return 0;
}
