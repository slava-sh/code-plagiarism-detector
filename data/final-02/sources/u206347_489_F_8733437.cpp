#include <bits/stdtr1c++.h>

#define MAX 505
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl

using namespace std;

int n, m, MOD = 100000007;

char str[MAX];
long long dp[MAX][MAX];
bool visited[MAX][MAX], ar[MAX][MAX];

long long F(int i, int z, int o){
    if (i == n) return (z == 0 && o == 0);
    if (visited[i][z]) return dp[i][z];

    long long x, res = 0;
    if (z > 1){
        x = (z * (z - 1)) >> 1;
        res = res + (x * F(i + 1, z - 2, o + 2));
    }
    if (o > 1){
        x = (o * (o - 1)) >> 1;
        res = res + (x * F(i + 1, z, o - 2));
    }
    if (z && o){
        x = (o * z);
        res = res + (x * F(i + 1, z - 1, o));
    }

    visited[i][z] = true;
    return (dp[i][z] = (res % MOD));
}

int main(){
    int i, j;

    while (scanf("%d %d %d", &n, &m, &MOD) != EOF){
        clr(ar);

        for (i = 0; i < m; i++){
            scanf("%s", str);
            for (j = 0; str[j] != 0; j++){
                ar[i][j] = str[j] - 48;
            }
        }

        int z = 0, o = 0;
        for (j = 0; j < n; j++){
            int counter = 0;
            for (i = 0; i < n; i++){
                if (ar[i][j]) counter++;
            }

            if (counter == 0) z++;
            if (counter == 1) o++;
        }

        clr(visited);
        long long res = F(m, z, o);
        printf("%I64d\n", res);
    }
    return 0;
}
