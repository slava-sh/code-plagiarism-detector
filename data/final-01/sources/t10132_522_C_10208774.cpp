#include<cstdio>
#define NDEBUG
#include<assert.h>
#include<algorithm>
using namespace std;
const int MN = 200010;
int a[MN], b[MN], p[MN], q[MN];
char ans[MN];
int main(){
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int t, m, k;

    for(scanf("%d", &t); t--; ) {
        scanf("%d%d", &m, &k);
        int pos = 0, pos1;
        for(int i = 1; i <= k; i++) {
            scanf("%d", &a[i]);
        }

        bool flag = false;
        for(int i = 1; i < m; i++) {
            scanf("%d%d", &p[i], &q[i]);
            if(q[i] == 1 && !flag) {
                flag = true;
                for(int j = 1; j <= k; j++) {
                    b[j] = a[j];
                }
                pos1 = pos;
            }
            if(p[i] != 0) {
                a[ p[i] ]--;
            }
            else {
                pos++;
            }
        }
        int minA = MN;
        if(flag) {
            for(int i = 1; i <= k; i++) {
                //printf("%d %d\n", b[i], a[i]);
                if(a[i] == b[i]) {
                    minA = min(minA, a[i]);
                }
            }
            pos -= minA;
        }
        //printf("%d\n", pos);
        for(int i = 1; i <= k; i++) {
            if(flag && a[i] == b[i] && a[i] <= pos1) {
                printf("Y");
            }
            else {
                printf("%c", (a[i] > pos ? 'N' : 'Y'));
            }
        }
        printf("\n");
    }
    return 0;
}
