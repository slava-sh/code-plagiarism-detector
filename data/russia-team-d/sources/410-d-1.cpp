#include <stdio.h>
#include <fstream>

#define min(a, b) ((a) < (b) ? (a) : (b))

int arr[100000];

void qsort(int l, int r)
{
    int x = l, y = r, m = arr[(l+r)/2];
    while (x <= y)
    {
        while (arr[x] > m) x++;
        while (arr[y] < m) y--;
        if (x <= y) {
            int t = arr[x];
            arr[x] = arr[y];
            arr[y] = t;
            x++; y--;
        }
    }
    if (x < r) qsort(x, r);
    if (l < y) qsort(l, y);
}

int main()
{
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(0, n-1);
    int l = 0, r = arr[n-1];
    //for (int i = 0; i < n; i++)
    //    printf("%d ", arr[i]);
    int b;
    //printf("%d ", r);
    //printf("%d ", k);
    while (l <= r) {
        int m = (l+r)/2;

        bool good = true;
        int pos = 0;
        for (int i = 0; i < n; i++) {
            //printf("%d ", pos);
            int newpos = pos + m;
            pos += arr[i];
            if (pos > k) {
                good = false;
                break;
            }
            pos = newpos;
        }
        //printf("\n");

        if (good) {
            b = m;
            l = m+1;
        }
        else {
            r = m-1;
        }
    }

    printf("%d\n", b);

    return 0;
}
