#include <stdio.h>

int fwt[5009];

void fwt_add(int i, int d) {
    while (i <= 5000) {
        fwt[i] += d;
        i += i&(-i);
    }
}

int fwt_get(int i) {
    int s = 0;
    while (i) {
        s += fwt[i];
        i -= i&(-i);
    }
    return s;
}

int P[5009][5009];

int a[5009];

int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (int j = n; j; j--) {
        fwt_add(a[j], 1);
        for (int i = j-1; i; i--) {
            P[i][j] = P[i+1][j] + fwt_get(a[i]);
            fwt_add(a[i], 1);
        }
        for (int i = j; i; i--)
            fwt_add(a[i], -1);
    }

    /*
    for (int i = 1; i <= n; i++, printf("\n")) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", P[j][i]);
        }
    }
    */

    int a = -1, b = -1;
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {

            if (2*(P[i][j] - P[i+1][j-1]) - 2*(j-i+1) + 1 > ans) {
                ans = 2*(P[i][j] - P[i+1][j-1]) - 2*(j-i+1) + 1;
                a = i;
                b = j;
            }

        }
    }

    printf("%d %d", a, b);
}
