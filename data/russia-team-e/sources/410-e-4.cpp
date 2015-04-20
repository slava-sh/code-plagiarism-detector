#include <stdio.h>

#define ll long long int

using namespace std;

int arr[10000][9];
int type[10000][9];
int cnt[9];

int bsearch(int t, int num)
{
    int l = 0, r = cnt[t]-1;

    while (l <= r) {
        int m = arr[(l+r)/2][t];
        //printf("%d ", m);
        if (m > num)
            r = (l+r)/2-1;
        else if (m < num)
            l = (l+r)/2+1;
        else
            return (l+r)/2;
    }
    return -1;
}

void qsort(int l, int r, int t)
{
    int x = l, y = r, m = arr[(l+r)/2][t];
    while (x <= y) {
        while (arr[x][t] < m) x++;
        while (arr[y][t] > m) y--;
        if (x <= y) {
            int k = arr[x][t];
            arr[x][t] = arr[y][t];
            arr[y][t] = k;

            k = type[x][t];
            type[x][t] = type[y][t];
            type[y][t] = k;

            x++; y--;
        }
    }
    if (x < r) qsort(x, r, t);
    if (l < y) qsort(l, y, t);
}

ll exp10[11];


int cip(ll num, int p)
{
    return (num%exp10[p])/exp10[p-1];
}

int main()
{
    freopen("numbers.in", "r", stdin);
    freopen("numbers.out", "w", stdout);
    exp10[0] = 1;
    for (int t = 1; t < 11; t++) exp10[t] = exp10[t-1]*10;
    for (int t = 0; t < 8; t++) cnt[t] = 0;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int c, k;
        scanf("%d %d", &c, &k);
        int cipcnt = 1;
        if (c >= 10)
            cipcnt++;
        if (c >= 100)
            cipcnt++;
        for (int j = 0; j < k; j++)
        {
            int t;
            scanf("%d", &t);
            if (t >= 100 && t < 1000)
            {
                arr[cnt[cipcnt+3]][cipcnt+3] = c*1000+t;
                type[cnt[cipcnt+3]][cipcnt+3] = cipcnt;
                cnt[cipcnt+3]++;
            }
            if (t >= 1000 && t < 10000)
            {
                arr[cnt[cipcnt+4]][cipcnt+4] = c*10000+t;
                type[cnt[cipcnt+4]][cipcnt+4] = cipcnt;
                cnt[cipcnt+4]++;
            }
            if (t >= 10000 && t < 100000)
            {
                arr[cnt[cipcnt+5]][cipcnt+5] = c*100000+t;
                type[cnt[cipcnt+5]][cipcnt+5] = cipcnt;
                cnt[cipcnt+5]++;
            }
        }
    }

    qsort(0, cnt[4]-1, 4);
    qsort(0, cnt[5]-1, 5);
    qsort(0, cnt[6]-1, 6);
    qsort(0, cnt[7]-1, 7);
    qsort(0, cnt[8]-1, 8);

    int m;
    scanf("%d", &m);

    while (m--)
    {
        ll num;
        scanf("%I64d", &num);

        if (num < 10000000000LL) {
            printf("Incorrect\n");
        }

        int t = bsearch(4, (int)(num/10000000LL));
        int cipcnt = 4;

        if (t == -1) {
            t = bsearch(5, (int)(num/1000000LL));
            cipcnt = 5;
        }
        if (t == -1) {
            t = bsearch(6, (int)(num/100000LL));
            cipcnt = 6;
        }
        if (t == -1) {
            t = bsearch(7, (int)(num/10000LL));
            cipcnt = 7;
        }
        if (t == -1) {
            t = bsearch(8, (int)(num/1000LL));
            cipcnt = 8;
        }

        if (t == -1)
        {
            printf("Incorrect");
            continue;
        }
        else
        {
            printf("+");
            if (type[t][cipcnt] == 1)
            {
                printf("%I64d", num/10000000000LL);
            }
            if (type[t][cipcnt] == 2)
            {
                printf("%I64d", num/1000000000LL);
            }
            if (type[t][cipcnt] == 3)
            {
                printf("%I64d", num/100000000LL);
            }

            printf("(%I64d)", (num%exp10[11-type[t][cipcnt]])/exp10[11-cipcnt]);

            if (cipcnt == 4)
            {
                printf("%d%d%d-%d%d-%d%d", cip(num, 7), cip(num, 6), cip(num, 5), cip(num, 4), cip(num, 3), cip(num, 2), cip(num, 1));
            }
            else if (cipcnt == 4)
            {
                printf("%d%d-%d%d-%d%d", cip(num, 6), cip(num, 5), cip(num, 4), cip(num, 3), cip(num, 2), cip(num, 1));
            }
            else if (cipcnt == 6)
            {
                printf("%d%d%d-%d%d", cip(num, 5), cip(num, 4), cip(num, 3), cip(num, 2), cip(num, 1));
            }
            else if (cipcnt == 7)
            {
                printf("%d%d-%d%d", cip(num, 4), cip(num, 3), cip(num, 2), cip(num, 1));
            }
            else if (cipcnt == 8)
            {
                printf("%d%d%d", cip(num, 3), cip(num, 2), cip(num, 1));
            }

        }
        printf("\n");
    }
}
