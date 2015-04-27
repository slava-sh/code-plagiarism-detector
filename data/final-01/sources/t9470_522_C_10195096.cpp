#include <iostream>
#include <cstdio>
#include <vector>
#include <limits.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int m, k;
        scanf("%d %d", &m, &k);
        vector <int> a(k), endWith1(k), copy1;
        for (int j = 0; j < k; j++) {
            scanf("%d", &a[j]);
            endWith1[j] = 0;
        }

        int unkn = 0;
        char is_first_one = 1;
        for (int j = 0; j < m - 1; j++) {
            int c, d;
            scanf("%d %d", &c, &d);

            if (d == 1 && is_first_one) {
                for (int l = 0; l < k; l++) {
                    if (unkn >= a[l]) {
                        endWith1[l] = 1;
                    }
                }
                copy1 = a;
                is_first_one = 0;
            }

            if (c > 0) {
                if (is_first_one == 0)
                    endWith1[c - 1] = 0;
                a[c - 1]--;
            }
            else
                unkn++;
        }

        int minval = INT_MAX;
        for (int j = 0; j < k; j++) {
            if (endWith1[j] && minval > copy1[j]) {
                minval = copy1[j];
            }
        }
        if (minval == INT_MAX)
            minval = 0;
        for (int j = 0; j < k; j++) {
            if (endWith1[j] || unkn >= minval + a[j]) {
                printf("Y");
            }
            else
                printf("N");
        }
        printf("\n");
    }
    return 0;
}
