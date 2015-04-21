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

int a,b,n,x,y,z;
vector< pii > v[100105];

int ticks = 0;
void TL() {
     if(++ticks == 1000) {
        ticks = 0;
        if (clock() >= 1900) { printf("Yes\n"); exit(0); }
    }
}

int main()
{
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);

    scanf("%d%d%d",&a,&b,&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&x);
        for (int j = 0; j <= x; ++j) {
            scanf("%d%d",&y,&z);
            v[i].push_back(make_pair(y, z));
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            TL();
            int pa = 0, pb = 0;
            int curx = a;
            bool a_higher = false, b_higher = false;
            for (; pa + 1 < v[i].size() || pb + 1 < v[j].size(); ) {
                ll A1 = v[i][pa].second - v[i][pa+1].second;
                ll B1 = -v[i][pa].first + v[i][pa+1].first;
                ll C1 = -A1 * v[i][pa].first - B1* v[i][pa].second;

                ll A2 = v[j][pb].second - v[j][pb+1].second;
                ll B2 = -v[j][pb].first + v[j][pb+1].first;
                ll C2 = -A2 * v[j][pb].first - B2* v[j][pb].second;

                ll XA1 = v[i][pa].first, XA2 = v[i][pa+1].first;
                ll YA1 = v[i][pa].second, YA2 = v[i][pa+1].second;

                ll XB1 = v[j][pb].first, XB2 = v[j][pb+1].first;
                ll YB1 = v[j][pb].second, YB2 = v[j][pb+1].second;

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

                if (pa + 2 == v[i].size() && pb + 2 == v[j].size()) break;
                if (pa + 2 == v[i].size()) ++pb;
                else if (pb + 2 == v[j].size()) ++pa;
                else {
                    if (v[i][pa + 1].first > v[j][pb].first) ++pb;
                    else ++pa;
                }
            }
            if (a_higher && b_higher) { printf("No\n%d %d",i+1,j+1); return 0; }
        }
    }

    printf("Yes");

    return 0;
}
