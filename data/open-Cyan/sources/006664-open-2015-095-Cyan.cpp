#include <stdio.h>

#define abs(a) ((a) > 0 ? (a) : (-(a)))

#define ll long long

int x[409][409];
int y[409][409];
int L[409];

bool Check(int i, int j)
{
    int p = 0;
    for (int t = 0; t < L[i]; t++) {
        while (x[j][p] < x[i][t]) p++;
        while (x[j][p] <= x[i][t+1]) {

            if ( (x[j][p]-x[i][t])*(y[i][t+1]-y[j][p]) - (y[j][p]-y[i][t])*(x[i][t+1]-y[j][p]) < 0)
                return false;

            p++;
        }
    }

    return true;
}

int main()
{
    int A, B; scanf("%d %d", &A, &B);

    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        scanf("%d", &L[i]);

        for (int j = 0; j <= L[i]; j++) {
            scanf("%d %d", &x[i][j], &y[i][j]);
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i+1; j <= N; j++) {
            if (!Check(i, j) && !Check(j, i)) {
                printf("No\n");
                printf("%d %d", i, j);
                return 0;
            }
        }
    }

    printf("Yes\n");
}
