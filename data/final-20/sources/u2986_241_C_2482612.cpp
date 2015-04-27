#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

int hl, hr, n;
char T[100000] = {}, F[100000] = {};
int c[100] = {};

int solve(int hl, int hr, char* t, char* f) {
    int y2;
    int ans = 0;
    for(int k = 1; k <= 100; ++k) {
//cout << "k = " << k << endl;
        y2 = (k%2?100-hr:hr)+k*100;
        bool B[100] = {};
        int sum = 0;
        for(int i = 1; i <= k; ++i) {
            int y = i * 100;
            int x = 100000*(y-hl)/(y2-hl);
            char* p = (i%2?t:f);
//cout << "    x = " << x << endl;
//cout << "    p[x] = " << int(p[x]) << endl;
            if(p[x] == -1 || B[p[x]]) {
                sum = -1;
                break;
            }
            else {
                B[p[x]] = true;
                sum += c[p[x]];
            }
        }
//cout << "sum = " << sum << endl;
//for(int i = 0; i < n; ++i) cout << B[i];
//cout << endl;
        ans = max(sum, ans);
//system("pause");
    }
    return ans;
}

int main() {
    
    scanf("%d%d%d", &hl, &hr, &n);
    
    memset(T, -1, sizeof(T));
    memset(F, -1, sizeof(F));
    
    for(int i = 0; i < n; ++i) {
        char s[2];
        int a, b;
        scanf("%d%s%d%d", c+i, s, &a, &b);
        char* p = (*s=='T' ? T : F);
        for(int j = a; j < b; ++j) {
            p[j] = i;
        }
    }
    
    printf("%d\n", max(solve(hl, hr, T, F), solve(100-hl, 100-hr, F, T)));
//    system("pause");
    
}
