#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

const int maxn = 1001;
const double oo = 1E20;

int h1,h2,n,w,h,ans;
int a[maxn],b[maxn],v[maxn],used[maxn];
char c[maxn];

int jiao(double l1,double r1,double l2,double r2)
{
    return l1 < r2 && l2 < r1;
}

void solve(int h1,double l,double r,int sum,int step)
{
    double what,nl,nr;
    int i;
    if (step == 0) 
    {
        if (h1 != h2) 
        {
            what = w*h1/(h1-h2);
            if (l <= what && what <= r) ans = max(ans,sum);
        }

        h1 = -h1;
        for (i = 1; i <= n; ++i)
            if (!used[i] && c[i] == 'F' && jiao(a[i],b[i],l,r))
            {
                used[i] = true;
                nl = max((double)a[i],l)*(100+abs(h1))/abs(h1);
                nr = min((double)b[i],r)*(100+abs(h1))/abs(h1);
                solve(h1,nl,nr,sum+v[i],!step);
                used[i] = false;
            }
    }
    else 
    {
        what = w*(abs(h1)+h)/(abs(h1)+h2);
        if (l <= what && what <= r) ans = max(ans,sum);
        h1 = 2*h-h1;
        for (i = 1; i <= n; ++i)
            if (!used[i] && c[i] == 'T' && jiao(a[i],b[i],l,r))
            {
                used[i] = true;
                nl = max((double)a[i],l)*(h1)/(h1-h);
                nr = min((double)b[i],r)*(h1)/(h1-h);
                solve(h1,nl,nr,sum+v[i],!step);
                used[i] = false;
            }
    }
}

int main()
{
    int i;

    h = 100;
    w = 100000;

    scanf("%d %d %d\n",&h1,&h2,&n);
    for (i = 1; i <= n; ++i)
        scanf("%d %c %d %d\n",&v[i],&c[i],&a[i],&b[i]);

    solve(h1,0,oo,0,0);
    solve(h1,0,oo,0,1);

    printf("%d",ans);

    return 0;
}
