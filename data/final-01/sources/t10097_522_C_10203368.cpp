#include <cstdio>
#include <algorithm>
using namespace std;

int t, m, i, k, dis, sum, sum1, mini, a[100005], d[100005], r[100005];
bool b[100005];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        dis = 0; sum = 0; sum1 = 0; mini = 100001;
        scanf("%d%d", &m, &k);
        for (i=1; i<=k; i++) { scanf("%d", a+i); b[i] = false; }
        for (i=1; i<m; i++) { scanf("%d%d", d+i, r+i); if (!dis && r[i]) dis = i; }
        if (!dis)
        {
            for (i=1; i<m; i++) if (d[i]) a[d[i]]--; else sum++;
            for (i=1; i<=k; i++) if (sum>=a[i]) printf("Y"); else printf("N");
            printf("\n");
        } else
        {
            for (i=1; i<dis; i++) if (d[i]) a[d[i]]--; else sum++;
            for (i=dis; i<m; i++) if (d[i]) { b[d[i]]=true; a[d[i]]--; } else sum1++;
            for (i=1; i<=k; i++) if (!b[i] && sum>=a[i] && a[i]<mini) mini = a[i];
            for (i=1; i<=k; i++) if (!b[i] && sum>=a[i]) a[i] -= mini;
            sum = sum - mini + sum1;
            for (i=1; i<=k; i++) if (sum>=a[i]) printf("Y"); else printf("N");
            printf("\n");
        }
    }
    return 0;
}
