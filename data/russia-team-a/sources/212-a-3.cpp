#include <stdio.h>
#include <stdlib.h>

using namespace std;

int n;
const int MAXN = (int)1e3;
const int MOD = (int)1e9+7;

int mat[MAXN][MAXN];

int use[MAXN];

int d[MAXN];

void dfs(int v, int prev) {
    //printf("%d %d\n", v, prev);
    use[v] = 1;
    for (int i = 0; i < n; i++) {
        if (mat[v][i] == -1 || i == prev || use[i] == 2)
            continue;
        if (use[i] == 1) {
            int q = d[v] - d[i] + mat[v][i];
            if (q % 2 == 1) {
                printf("0\n");
                exit(0);
            }
            continue;
        }
        d[i] += mat[v][i];
        
        dfs(i, v);

    }


    use[v] = 2;
    return;
}


int main() {
    freopen("binary.in", "r", stdin);
    freopen("binary.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            mat[i][j] = -1;

    int z;
    scanf("%d", &z);
    for (int i = 1; i < n; i++) {
        scanf("%d", &z);
        if (i + z - 1 >= n) {
            printf("0\n");
            return 0;
        }
        if (z == -1)
            continue;
        for (int j = 0; j < z; j++) {
            mat[j][i + j] = 0;
            mat[i + j][j] = 0;
        }
        if (i + z < n) { 
            mat[z][i + z] = 1;
            mat[i + z][z] = 1;        
        }
    }

  /*  for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");   
    }
    */
        
    int k = 0;

    for (int i = 0; i < n; i++) {
        //printf("u %d\n", use[i]);
        if (use[i])
            continue;
        k++;
        dfs(i, -1);       
    }

    //printf("%d\n", k);
    
    int ans = 1;

    for (int i = 0; i < k; i++) {
        ans *= 2;
        ans %= MOD;
    }
    printf("%d\n", ans);

    return 0;
}

