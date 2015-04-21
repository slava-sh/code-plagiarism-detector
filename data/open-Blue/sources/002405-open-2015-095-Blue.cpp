#include <stdio.h>
#include <string.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

char s[20009];

int a[20009];
int b[20009];
int c[20009];

int main()
{
    int L;
    scanf("%d\n%s", &L, s);
    int n = strlen(s);

    for (int t = 1; t <= min(n, L); t++) {
        if (n%t == 0) {

            int i;
            for (i = 0; i < n; i++) {
                if (s[i] != s[i%t]) break;
            }
            if (i == n) {
                printf("1\n");
                for (i = 0; i < t; i++) printf("%c", s[i]);
                return 0;
            }

        }
    }

/*
    if (s[0] == 'a')
        a[0] = 1;
    else if (s[0] == 'b')
        b[0] = 1;
    else
        c[0] = 1;

    for (int i = 1; i < n; i++) {
        a[i] = a[i-1];
        b[i] = b[i-1];
        c[i] = c[i-1];
        if (s[i] == 'a')
            a[i]++;
        else if (s[i] == 'b')
            b[i]++;
        else
            c[i]++;
    }
*/

    for (int x = 1; x <= min(n, L); x++) {

        int y = n;
        while (y >= x*2) {
            int t = 0;
            for (int i = y-x; i < y; i++, t++) {
                if (s[i] != s[t]) break;
            }
            if (t != x) break;
            y -= x;
        }

        int z = x;
        while (y >= z+x) {
            int t = 0;
            for (int i = z; i < z+x; i++, t++) {
                if (s[i] != s[t]) break;
            }
            if (t != x) break;
            z += x;
        }

        for (int q = 1; q <= min(y-z, L); q++) {

            int i;
            for (i = z; i < y;) {

                int t = 0;
                for (int j = i; i+x <= y && j < i+x; j++, t++)
                    if (s[j] != s[t]) break;
                if (t == x)
                    i += x;
                else {
                    t = z;
                    for (int j = i; i+q <= y && j < i+q; j++, t++)
                        if (s[j] != s[t]) break;
                    if (t != z+q) break;
                    i += q;
                }

            }

            if (i == y) {
                printf("2\n");
                for (int i = 0; i < x; i++)
                    printf("%c", s[i]);
                printf("\n");
                for (int i = z; i < z+q; i++) {
                    printf("%c", s[i]);
                }
                return 0;
            }

        }

    }

    printf("3\na\nb\nc");
}
