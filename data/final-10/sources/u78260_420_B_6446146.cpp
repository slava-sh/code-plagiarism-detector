#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int,int>   pii;
typedef __int64 ll;
const int N = 300000+5;

int ins[N];
bool no[N];
char op[N][3];
int x[N], pre[N], f[N];
ll sum[N];
int n, m;

int main() {
    memset(no, false, sizeof(no));
    scanf("%d%d", &n, &m);
    int cur = 0;
    for(int i = 2;i <= m+1; i++) {
        scanf("%s%d", op[i], &x[i]);
    }
    for(int i = 2;i <= m+1; i++) {
        if(op[i][0] == '+') {
            sum[i]++;
            f[i] = pre[x[i]];
            pre[x[i]] = i;
        }
        else {
            if(!pre[x[i]])  sum[1]++;
            sum[i]--;
            pre[x[i]] = i;
        }
    }
    for(int i = 1;i <= m+1; i++)  sum[i] += sum[i-1];
    for(int i = 1;i <= m+1; i++)    sum[i] += sum[i-1];
    for(int i = 2;i <= m+1; i++) {
        if(op[i][0] == '+') {
            if(f[i] == 0) {
                if(sum[i-1]-sum[0] > 0)   no[x[i]] = true;
            }
            else {
                if(sum[i-1]-sum[f[i]-1] > 0)  no[x[i]] = true;
            }
        }
        else {
            if(i+1 <= m+1) {
                if(x[i+1] != x[i])  no[x[i]] = true;
            }
            if(sum[i]-sum[i-1] > 0) no[x[i]] = true;
        }
    }
    int ans = 0;
    for(int i = 1;i <= n; i++) if(!no[i])
        ans++;
    printf("%d\n", ans);
    for(int i = 1;i <= n; i++) if(!no[i])
        printf("%d ", i);
    puts("");
    return 0;
}
